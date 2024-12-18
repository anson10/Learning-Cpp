#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<cmath>
#include<iomanip>
#include <cstdlib>

// Read CSV file
std::vector<std::vector<double>> readCSV(const std::string& filename)
{
    std::vector<std::vector<double>> data;
    std::ifstream file(filename);

    if (!file.is_open())
    {
        throw std::runtime_error("Could not open file");
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::vector<double> row;
        std::stringstream ss(line);
        std::string value;
        while (std::getline(ss, value, ','))
        {
            row.push_back(std::stod(value));
        }
        data.push_back(row);
    }
    file.close();
    return data;
}

// Normalise data
void Normalize(std::vector<std::vector<double>>& X)
{
    int rows = X.size();
    int cols = X[0].size();

    for (int j = 1; j < cols; ++j)
    {
        double mean = 0, std_dev = 0;

        for (int i = 0; i < rows; ++i)
        {
            mean += X[i][j];
        }
        mean /= rows;

        for (int i = 0; i < rows; ++i)
        {
            std_dev += std::pow(X[i][j] - mean, 2);
        }
        std_dev = std::sqrt(std_dev / rows);

        for (int i = 0; i < rows; ++i)
        {
            X[i][j] = (X[i][j] - mean) / std_dev;
        }
    }
}

// Cost Function
double ComputeCost(const std::vector<std::vector<double>>& X, const std::vector<double>& Y, const std::vector<double>& theta)
{
    int m = Y.size();
    double cost = 0;

    for (int i = 0; i < m; ++i)
    {
        double prediction = 0;
        for (size_t j = 0; j < theta.size(); ++j)
        {
            prediction += theta[j] * X[i][j];
        }
        cost += std::pow(prediction - Y[i], 2);
    }
    return cost / (2 * m);
}

// Gradient descent
std::vector<double> gradientDescent(std::vector<std::vector<double>>& X, const std::vector<double>& Y, double alpha, int iterations)
{
    int m = Y.size();
    int n = X[0].size();
    std::vector<double> theta(n, 0.0); // Initialize coefficients to 0

    for (int iter = 0; iter < iterations; ++iter)
    {
        std::vector<double> gradient(n, 0.0);

        // Compute gradient for each theta
        for (int i = 0; i < m; ++i)
        {
            double prediction = 0;
            for (int j = 0; j < n; ++j)
            {
                prediction += theta[j] * X[i][j];
            }
            for (int j = 0; j < n; ++j)
            {
                gradient[j] += (prediction - Y[i]) * X[i][j];
            }
        }

        // Update theta
        for (int j = 0; j < n; ++j)
        {
            theta[j] -= (alpha / m) * gradient[j];
        }

        // Optional: Print cost every 100 iterations
        if (iter % 100 == 0)
        {
            std::cout << "Iteration " << iter << ", Cost: " << ComputeCost(X, Y, theta) << "\n";
        }
    }

    return theta;
}

// Write predictions to file
void writePredictionsToFile(const std::vector<double>& Y, const std::vector<double>& predictions, const std::string& filename)
{
    std::ofstream file(filename);

    if (!file.is_open())
    {
        throw std::runtime_error("Could not open file to write predictions.");
    }

    for (size_t i = 0; i < Y.size(); ++i)
    {
        file << i + 1 << " " << Y[i] << " " << predictions[i] << "\n";
    }

    file.close();
}

// Plot using gnuplot
//void plotWithGnuplot(const std::string& filename)
//{
//    std::string command = "gnuplot -e \"set title 'Actual vs Predicted'; "
//        "set xlabel 'Index'; "
//        "set ylabel 'Values'; "
//        "plot '" + filename + "' using 1:2 with linespoints title 'Actual', '"
//        + filename + "' using 1:3 with linespoints title 'Predicted'\"";
//    system(command.c_str());
//}

//void plotWithGnuplot(const std::string& filename) {
//    std::string gnuplotCommand = "gnuplot -e \"set terminal pngcairo; set output 'plot.png'; ";
//    gnuplotCommand += "set title 'Actual vs Predicted'; set xlabel 'Index'; set ylabel 'Values'; ";
//    gnuplotCommand += "plot '" + filename + "' using 1:2 with linespoints title 'Actual', '";
//    gnuplotCommand += filename + "' using 1:3 with linespoints title 'Predicted'\"";
//
//    int result = std::system(gnuplotCommand.c_str());
//
//    if (result != 0) {
//        std::cerr << "Error: Could not execute Gnuplot.\n";
//    }
//}

int main()
{
    try
    {
        // Read dataset
        std::string filename = "data.csv";
        auto data = readCSV(filename);

        int rows = data.size();
        int cols = data[0].size();

        // Separate features (X) and target variable (Y)
        std::vector<std::vector<double>> X(rows, std::vector<double>(cols, 1.0)); // Add bias term
        std::vector<double> Y(rows);

        for (int i = 0; i < rows; ++i)
        {
            Y[i] = data[i][cols - 1]; // Last column is the target
            for (int j = 0; j < cols - 1; ++j)
            {
                X[i][j + 1] = data[i][j]; // Features
            }
        }

        // Normalize features
        Normalize(X);

        // Hyperparameters
        double alpha = 0.01;   // Learning rate
        int iterations = 1000;

        // Model Training
        std::vector<double> theta = gradientDescent(X, Y, alpha, iterations);

        // Output coefficients
        std::cout << "Coefficients: ";
        for (const auto& coef : theta)
        {
            std::cout << coef << " ";
        }
        std::cout << "\n";

        // Predict values
        std::vector<double> predictions(rows);
        for (int i = 0; i < rows; ++i)
        {
            predictions[i] = 0;
            for (size_t j = 0; j < theta.size(); ++j)
            {
                predictions[i] += theta[j] * X[i][j];
            }
        }

        // Write predictions to file
        std::string outputFile = "predictions.txt";
        writePredictionsToFile(Y, predictions, outputFile);

        // Plot data using gnuplot
        /*plotWithGnuplot(outputFile);*/

    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
