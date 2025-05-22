#include <iostream>
#include <iomanip>
#include <cmath>

double f(double x) {
    return std::exp(x) - 20;
}

double f_analytical_deriv(double (*func)(double), double x, double h) { // Overloading this function in order to make the code more concise.
    return std::exp(x);
}

double deriv_f3(double (*func)(double), double x, double h) {
    return (func(x + h) - func(x - h)) / (2 * h);
}

double deriv_f5(double (*func)(double), double x, double h) {
    return (func(x - 2 * h) - 8 * func(x - h) + 8 * func(x + h) - func(x + 2 * h)) / (12 * h);
}

double newton_method(double (*func)(double), double (*deriv)(double (double),double, double), const int N, const double h, double p) {
    double fp, fp_deriv;

   double true_root = std::log(20);  // ≈ 2.995732273553991

    for (int i = 0; i <= N; ++i) {
        fp = func(p);
        fp_deriv = deriv(func, p, h);
    
        std::cout << "Iteration " << i << ": p = " << p << ", f(p) = " << fp << ", rel. error = " << std::abs((p - true_root) / true_root) << "\n";

        p = p - fp / fp_deriv;
    }
    
    return p;
}

int main() {
    double p0 = 2.0;
    double h = 0.1;
    const int N = 10;

    double f0;

    std::cout << std::fixed << std::setprecision(20);

    f0 = newton_method(f, deriv_f3, N, h, p0);
    std::cout << "root using three point derivative: " << f0 << '\n';

    f0 = newton_method(f, deriv_f5, N, h, p0);
    std::cout << "root using five point derivative:  " << f0 << '\n';

    f0 = newton_method(f, f_analytical_deriv, N, h, p0);
    std::cout << "root using analytical derivative:  " << f0 << '\n';

    return 0;
}