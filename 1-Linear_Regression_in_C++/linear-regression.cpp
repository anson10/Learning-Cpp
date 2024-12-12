#include <iostream>
#include <vector>
#include <cmath>

// Gradient Descent function
void gradientDescent(const std::vector<double>& x, const std::vector<double>& y, double& m, double& b, double learningRate, int iterations) {
    for (int i = 0; i < iterations; ++i) {
        double mGradient = 0.0;
        double bGradient = 0.0;

        // Compute gradients
        for (size_t j = 0; j < x.size(); ++j) {
            double prediction = m * x[j] + b;
            mGradient += (prediction - y[j]) * x[j];
            bGradient += prediction - y[j];
        }

        mGradient /= x.size();
        bGradient /= x.size();

        // Update parameters
        m -= learningRate * mGradient;
        b -= learningRate * bGradient;

        // Debug
        if (i % 100 == 0) {
            std::cout << "Iteration " << i << ": m = " << m << ", b = " << b << std::endl;
        }

        // Early stopping if gradients are too small
        if (std::abs(mGradient) < 1e-10 && std::abs(bGradient) < 1e-10) {
            std::cout << "Gradients too small. Stopping early." << std::endl;
            break;
        }
    }
}

// Mean Squared Error function
double calculateCost(const std::vector<double>& x, const std::vector<double>& y, double m, double b) {
    double cost = 0.0;
    for (size_t i = 0; i < x.size(); ++i) {
        double prediction = m * x[i] + b;
        cost += std::pow(prediction - y[i], 2);
    }
    return cost / x.size();
}

// R² Score function
double calculateR2Score(const std::vector<double>& y, const std::vector<double>& predictions) {
    double ssTotal = 0.0;
    double ssResidual = 0.0;

    double meanY = 0.0;
    for (double yi : y) {
        meanY += yi;
    }
    meanY /= y.size();

    for (size_t i = 0; i < y.size(); ++i) {
        ssTotal += std::pow(y[i] - meanY, 2);
        ssResidual += std::pow(y[i] - predictions[i], 2);
    }

    return 1 - (ssResidual / ssTotal);
}
