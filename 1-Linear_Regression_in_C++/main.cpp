#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "linear_regression.h"

// Read data from CSV file 
void readCSV(const std::string& filename, std::vector<double>& x, std::vector<double>& y) {
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        double xi, yi;
        char comma;

        ss >> xi >> comma >> yi;
        x.push_back(xi);
        y.push_back(yi);
    }
}

int main() {
    std::vector<double> x, y;
    readCSV("linear-reg-data.csv", x, y);

    // Display first few data points for verification
    for (size_t i = 0; i < 3 && i < x.size(); ++i) {
        std::cout << "x: " << x[i] << ", y: " << y[i] << std::endl;
    }

    // Initialize model parameters
    double m = 0.0, b = 0.0;
    double learningRate = 0.0001;  // Adjust learning rate if necessary
    int iterations = 1000;

    // Train using Gradient Descent
    gradientDescent(x, y, m, b, learningRate, iterations);

    // predictions
    std::vector<double> predictions;
    for (const auto& xi : x) {
        predictions.push_back(m * xi + b);
    }

    // calculate and display metrics
    double mse = calculateCost(x, y, m, b);
    double r2 = calculateR2Score(y, predictions);

    std::cout << "Trained Model: y = " << m << "x + " << b << std::endl;
    std::cout << "Mean Squared Error: " << mse << std::endl;
    std::cout << "R² Score: " << r2 << std::endl;

    std::ofstream outFile("output.csv");
    outFile << "x,y,predicted_y\n";
    for (size_t i = 0; i < x.size(); ++i) {
        outFile << x[i] << "," << y[i] << "," << (m * x[i] + b) << "\n";
    }
    outFile.close();
    std::cout << "Data and predictions saved to 'output.csv'." << std::endl;

    return 0;
}
