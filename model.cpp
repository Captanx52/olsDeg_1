#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <sstream>

using namespace std;

struct Point
{
    double x;
    double y;
};

// OLS comput
double computeS(const vector<Point> &points, double m, double b)
{
    double s = 0.0;
    for (const auto &point : points)
    {
        double error = point.y - (m * point.x + b);
        s += error * error;
    }
    return s;
}

// Ds/Dm
double computeDerivative_m(const vector<Point> &points, double m, double b)
{
    double derivative_m = 0.0;
    for (const auto &point : points)
    {
        double error = point.y - (m * point.x + b);
        derivative_m -= 2 * point.x * error;
    }
    return derivative_m;
}

// Ds/Db
double computeDerivative_b(const vector<Point> &points, double m, double b)
{
    double derivative_b = 0.0;
    for (const auto &point : points)
    {
        double error = point.y - (m * point.x + b);
        derivative_b -= 2 * error;
    }
    return derivative_b;
}

// gradient
void gradientDescent(vector<Point> &points, double &m, double &b, double learning_rate, int iterations)
{
    for (int i = 0; i < iterations; i++)
    {
        // Derivations coput
        double derivative_m = computeDerivative_m(points, m, b);
        double derivative_b = computeDerivative_b(points, m, b);

        // updating m & b
        m -= learning_rate * derivative_m;
        b -= learning_rate * derivative_b;

        // for cheking the learning rate truth per iteration
        if (i % 100 == 0)
        {
            double s = computeS(points, m, b);
            cout << "Iteration " << i << ", S: " << s << ", m: " << m << ", b: " << b << endl;
        }
    }
}

int main()
{
    ifstream inputFile("data.csv");
    vector<Point> points;
    string line;

    while (getline(inputFile, line))
    {
        stringstream ss(line);
        double x, y;
        char comma;

        ss >> x >> comma >> y;
        points.push_back({x, y});
    }

    inputFile.close();

    // deafults
    double m = 0.0;
    double b = 0.0;

    double learning_rate = 0.0001;
    int iterations = 1000;

    gradientDescent(points, m, b, learning_rate, iterations);

    cout << "Final m: " << m << ", b: " << b << endl;

    return 0;
}
