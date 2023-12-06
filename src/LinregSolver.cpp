#include <iostream>
#include <vector>
#include <numeric> // for std::accumulate

class LinearRegression
{
public:
    LinearRegression() : B_1(0), B_0(0) {}
    void addDataPoint(double x, double y) // a double is a floating point number but with more precision (64 bits)
    {
        x_values.push_back(x); // push_back adds an element to the end of the vector, like python's append()
        y_values.push_back(y);
    }

    void computeRegression()
    {
        B_1 = computeSlope();
        B_0 = computeIntercept();
    }

    double predict(double x) const
    {
        return B_1 * x + B_0;
    }

    void displayResults()
    {
        std::cout << "Slope (B_1): " << B_1 << std::endl;
        std::cout << "Intercept (B_0): " << B_0 << std::endl;
    }

private:
    std::vector<double> x_values; // vector of x values
    std::vector<double> y_values; // vector of y values
    double B_1;                   // slope
    double B_0;                   // intercept

    double computeMean(const std::vector<double> &values) const
    {                                                                              // const std::vector<double> &values is a reference to a vector of doubles that is constant, meaning it cannot be changed
                                                                                   // the & means that the vector is passed by reference, meaning that the vector is not copied when passed to the function, but rather the function works on the original vector
                                                                                   // this is more efficient than passing by value, which would copy the vector and then work on the copy
        return std::accumulate(values.begin(), values.end(), 0.0) / values.size(); // sum(vector) / len(vector) = mean
    }

    double computeSlope()
    // formula for slope: (n * sum(x * y) - sum(x) * sum(y)) / (n * sum(x * x) - sum(x) * sum(x))
    // latex: \frac{n \sum_{i=1}^{n} x_i y_i - \sum_{i=1}^{n} x_i \sum_{i=1}^{n} y_i}{n \sum_{i=1}^{n} x_i^2 - (\sum_{i=1}^{n} x_i)^2}
    {
        double sum_x = std::accumulate(x_values.begin(), x_values.end(), 0.0);                       // sum()
        double sum_y = std::accumulate(y_values.begin(), y_values.end(), 0.0);                       // sum()
        double sum_xy = std::inner_product(x_values.begin(), x_values.end(), y_values.begin(), 0.0); // sum(x * y for x, y in zip(x_values, y_values))
        double sum_xx = std::inner_product(x_values.begin(), x_values.end(), x_values.begin(), 0.0); // sum(x * x for x in x_values)
        int n = x_values.size();                                                                     // len(x_values)

        return (n * sum_xy - sum_x * sum_y) / (n * sum_xx - sum_x * sum_x);
    }

    double computeIntercept()
    // formula for intercept: mean(y) - B_1 * mean(x)
    // latex: \bar{y} - B_1 \bar{x}
    {
        double mean_x = computeMean(x_values);
        double mean_y = computeMean(y_values);

        return mean_y - B_1 * mean_x;
    }
};

int main()
{
    LinearRegression lr; // create a LinearRegression object

    lr.addDataPoint(1, 2); // add data points
    lr.addDataPoint(2, 3);
    lr.addDataPoint(3, 5);

    lr.computeRegression(); // compute the regression
    lr.displayResults();    // display the results

    // lets predict something
    std::cout << "Predicted value for x = 4: " << lr.predict(4) << std::endl;

    return 0;
}