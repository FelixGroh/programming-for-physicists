#include <iostream>
#include <cmath>
#include <iomanip>

double f(double x) {
    double g = std::pow(x, 3);
    double h = std::log(x) + 5.0;
    return g - h;
}

int main()  {
    double a = 0.25, b = 2.5, p;
    double f_a = f(a), f_pn, f_test;
    const int N = 100;

    std::cout << std::fixed;
    std::cout << std::setprecision(15);
    std::cout << "a,b,p" << '\n';

    for (int n = 0; n < N; n++) {
        p = a + (b - a) / 2;

        std::cout << a << "," << b << "," << p << '\n';
        
        f_pn = f(p);
        f_test = f_a * f_pn;

        if (f_test > 0) {
            a = p;
            f_a = f_pn;
            continue;
        }
        else if (f_test < 0) {
            b = p;
            continue;
        }
        else {
            break;
        }
    }
    
    return 0;
}