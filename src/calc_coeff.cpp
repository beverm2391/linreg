#include <iostream> // preprocessor directive 'include' to include the contents of the iostream library
                    // preprocessors are executed before compilation
                    // iostream contains declarations for objects like cout, cin, cerr etc.

// using namespace std;
// this is actually considered bad practice, especially in header files or in large projects, as it imports the entire standard namespace into the global namespace and can potentially lead to name conflicts.

// This function calculates the coefficients of a linear regression model. y = B_1 * x + B_0
template <typename T, typename M> // template declaration, using T and M as template parameters which will be replaced by actual types when the function is called
void calcCoeff(vector<T> indep_var, vector<T> dep_var, M &B_1, M &B_0) // void means no return value
{
    return 0;
};