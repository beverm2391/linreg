#include "LinearRegression.h"
#include <iostream>

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