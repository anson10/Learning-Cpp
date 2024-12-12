#ifndef LINEAR_REGRESSION_H
#define LINEAR_REGRESSION_H

#include <vector>

// Gradient Descent
void gradientDescent(const std::vector<double>& x, const std::vector<double>& y, double& m, double& b, double learningRate, int iterations);

// Mean Squared Error
double calculateCost(const std::vector<double>& x, const std::vector<double>& y, double m, double b);

//  R² Score
double calculateR2Score(const std::vector<double>& y, const std::vector<double>& predictions);

#endif
