#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    int n = 1000000;
    double e_def = 2.71828182845904523536;
    
    std::cout << std::fixed;
    std::cout << std::setprecision(18);

    float e_approx_f = pow(1 + 1. / n, n);
    std::cout << "e_float: " << e_approx_f << ", e_error: " << e_def - e_approx_f <<'\n';

    double e_approx_d = pow(1 + 1 / double(n), n);
    std::cout << "e_double: " << e_approx_d << ", e_error: " << e_def - e_approx_d <<'\n';

    return 0;
}