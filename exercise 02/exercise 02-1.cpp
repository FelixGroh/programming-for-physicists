#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double q = 8.0 / 9.0;
    int n = 100;
    double s_n = 0;

    std::cout << "index,sum" << '\n';
    std::cout << std::fixed;
    std::cout << std::setprecision(15);
    
    for (int k = 0; k <= n; k++) {
        s_n += std::pow(q, k);
        std::cout << k << ',' << s_n << '\n';
    }

    return 0;
}