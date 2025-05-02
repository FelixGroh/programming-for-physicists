#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    std::cout << std::fixed;

    double M_PI = 3.141592653589;

    double a = pow(64, 1.0 / 128);
    double b = pow(1.0 / 3.0, 2.0 * M_PI / 5.0);
    double c = cos(M_PI / 2);
    double d = exp(5.84 - 12);
    double e = log(exp(1.1));

    std::cout << std::setprecision(10);
    std::cout << "Ergebnisse mit 10 Stellen:" << std::endl;
    std::cout << a << ", " << b << ", " << c << ", " << d << ", " << e << std::endl;

    std::cout << std::setprecision(20);
    std::cout << "Ergebnisse mit 20 Stellen:" << std::endl;
    std::cout << a << ", " << b << ", " << c << ", " << d << ", " << e << std::endl;

    return 0;
}
