#include <iostream>
#include <iomanip>

void lagrange_polynomial(
    const double* x_values, const double* y_values, unsigned int N_points, double a, double b,
         unsigned int N_xp, double* xp, double* Pfp) {

    double dx = (b - a) / N_xp;

    for (unsigned int j = 0; j <= N_xp; ++j) {
        double x = a + j * dx;
        xp[j] = x;

        Pfp[j] = 0.0;
        for (unsigned int k = 0; k < N_points; ++k) {
            double Lk = 1.0;
            for (unsigned int i = 0; i < N_points; ++i) {
                if (i != k) {
                    Lk *= (x - x_values[i]) / (x_values[k] - x_values[i]);
                }
            }
            Pfp[j] += y_values[k] * Lk;
        }
    }
}

int main() {
    const unsigned int N_points = 7;
    const double x_values[N_points] = {2, 10.1, 15, 20, 40, 60, 90};
    const double y_values[N_points] = {2.1, 42, 43, 40.2, 12, 5, 17.5};
    const double a = 0.0, b = 100.0;

    const unsigned int N_xp = 500;
    double xp[N_xp + 1];
    double Pfp[N_xp + 1];

    lagrange_polynomial(x_values, y_values, N_points, a, b, N_xp, xp, Pfp);

    std::cout << "x,Pn" << "\n";
    for (unsigned int i = 0; i <= N_xp; ++i) {
        std::cout << xp[i] << "," << Pfp[i] << "\n";
    }
    return 0;
}