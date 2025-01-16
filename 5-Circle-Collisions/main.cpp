#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "olcConsoleGameEngine.h"

using namespace std;

struct sBall
{
    float px, py;
    float vx, vy;
    float ax, ay;
    float radius;
    float mass;

    int id;
};

class CirclePhysics : public olcConsoleGameEngine
{
public:
    CirclePhysics()
    {
        m_sAppName = L"Circle Physics";
    }

private:
    vector<pair<float, float>> modelCircle;
    vector<sBall> vecBalls;
    sBall* pSelectedBall = nullptr;

    // Adds a ball to the vector
    void AddBall(float x, float y, float r = 5.0f)
    {
        sBall b;
        b.px = x;
        b.py = y;
        b.vx = 0;
        b.vy = 0;
        b.ax = 0;
        b.ay = 0;
        b.radius = r;
        b.mass = r * 10.0f;
        b.id = vecBalls.size();
        vecBalls.emplace_back(b);
    }

public:
    bool OnUserCreate()
    {
        // Define Circle Model with evenly spaced points
        int nPoints = 20;
        for (int i = 0; i < nPoints; i++)
        {
            float theta = i / (float)nPoints * 2.0f * 3.14159f; // Proper spacing
            modelCircle.push_back({ cosf(theta), sinf(theta) });
        }

        // Add 10 Random Balls
        for (int i = 0; i < 10; i++)
            AddBall(rand() % ScreenWidth(), rand() % ScreenHeight(), rand() % 16 + 2);

        return true;
    }

    bool OnUserUpdate(float fElapsedTime)
    {
        auto DoCirclesOverlap = [](float x1, float y1, float r1, float x2, float y2, float r2)
            {
                return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) <= (r1 + r2) * (r1 + r2);
            };

        auto IsPointInCircle = [](float x1, float y1, float r1, float px, float py)
            {
                return ((x1 - px) * (x1 - px) + (y1 - py) * (y1 - py)) < (r1 * r1);
            };

        // Handle mouse input for selecting and moving balls
        if (m_mouse[0].bPressed || m_mouse[1].bPressed)
        {
            pSelectedBall = nullptr;
            for (auto& ball : vecBalls)
            {
                if (IsPointInCircle(ball.px, ball.py, ball.radius, m_mousePosX, m_mousePosY))
                {
                    pSelectedBall = &ball;
                    break;
                }
            }
        }

        if (m_mouse[0].bHeld && pSelectedBall != nullptr)
        {
            pSelectedBall->px = m_mousePosX;
            pSelectedBall->py = m_mousePosY;
        }

        if (m_mouse[0].bReleased)
            pSelectedBall = nullptr;

        if (m_mouse[1].bReleased && pSelectedBall != nullptr)
        {
            pSelectedBall->vx = 5.0f * (pSelectedBall->px - (float)m_mousePosX);
            pSelectedBall->vy = 5.0f * (pSelectedBall->py - (float)m_mousePosY);
            pSelectedBall = nullptr;
        }

        vector<pair<sBall*, sBall*>> vecCollidingPairs;

        // Update ball positions
        for (auto& ball : vecBalls)
        {
            ball.ax = -ball.vx * 0.8f;
            ball.ay = -ball.vy * 0.8f;

            ball.vx += ball.ax * fElapsedTime;
            ball.vy += ball.ay * fElapsedTime;
            ball.px += ball.vx * fElapsedTime;
            ball.py += ball.vy * fElapsedTime;

            if (ball.px < 0) ball.px += (float)ScreenWidth();
            if (ball.px >= ScreenWidth()) ball.px -= (float)ScreenWidth();
            if (ball.py < 0) ball.py += (float)ScreenHeight();
            if (ball.py >= ScreenHeight()) ball.py -= (float)ScreenHeight();

            if ((ball.vx * ball.vx + ball.vy * ball.vy) < 0.01f)
            {
                ball.vx = 0;
                ball.vy = 0;
            }
        }

        // Detect collisions
        for (auto& ball : vecBalls)
        {
            for (auto& target : vecBalls)
            {
                if (ball.id != target.id && DoCirclesOverlap(ball.px, ball.py, ball.radius, target.px, target.py, target.radius))
                {
                    vecCollidingPairs.push_back({ &ball, &target });

                    float fDistance = sqrtf((ball.px - target.px) * (ball.px - target.px) + (ball.py - target.py) * (ball.py - target.py));
                    float fOverlap = 0.5f * (fDistance - ball.radius - target.radius);

                    ball.px -= fOverlap * (ball.px - target.px) / fDistance;
                    ball.py -= fOverlap * (ball.py - target.py) / fDistance;

                    target.px += fOverlap * (ball.px - target.px) / fDistance;
                    target.py += fOverlap * (ball.py - target.py) / fDistance;
                }
            }
        }

        // Handle dynamic collisions
        for (auto& c : vecCollidingPairs)
        {
            sBall* b1 = c.first;
            sBall* b2 = c.second;

            float fDistance = sqrtf((b1->px - b2->px) * (b1->px - b2->px) + (b1->py - b2->py) * (b1->py - b2->py));
            float nx = (b2->px - b1->px) / fDistance;
            float ny = (b2->py - b1->py) / fDistance;

            float tx = -ny;
            float ty = nx;

            float dpTan1 = b1->vx * tx + b1->vy * ty;
            float dpTan2 = b2->vx * tx + b2->vy * ty;

            float dpNorm1 = b1->vx * nx + b1->vy * ny;
            float dpNorm2 = b2->vx * nx + b2->vy * ny;

            float m1 = (dpNorm1 * (b1->mass - b2->mass) + 2.0f * b2->mass * dpNorm2) / (b1->mass + b2->mass);
            float m2 = (dpNorm2 * (b2->mass - b1->mass) + 2.0f * b1->mass * dpNorm1) / (b1->mass + b2->mass);

            b1->vx = tx * dpTan1 + nx * m1;
            b1->vy = ty * dpTan1 + ny * m1;
            b2->vx = tx * dpTan2 + nx * m2;
            b2->vy = ty * dpTan2 + ny * m2;
        }

        // Clear screen
        Fill(0, 0, ScreenWidth(), ScreenHeight(), ' ');

        // Draw balls
        for (auto& ball : vecBalls)
            DrawWireFrameModel(modelCircle, ball.px, ball.py, 0.0f, ball.radius, FG_WHITE);

        // Draw collisions
        for (auto& c : vecCollidingPairs)
            DrawLine(c.first->px, c.first->py, c.second->px, c.second->py, PIXEL_SOLID, FG_RED);

        // Draw cue line
        if (pSelectedBall != nullptr)
            DrawLine(pSelectedBall->px, pSelectedBall->py, m_mousePosX, m_mousePosY, PIXEL_SOLID, FG_BLUE);

        return true;
    }
};

int main()
{
    CirclePhysics game;
    if (game.ConstructConsole(160, 120, 8, 8))
        game.Start();
    else
        wcout << L"Could not construct console" << endl;

    return 0;
}
