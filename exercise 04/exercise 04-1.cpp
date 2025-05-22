#include <iostream>
#include <iomanip>
#include <cmath>

double f1(double x) {
    return 1.0 / x;
}

double f2(double x) {
    return 10.0 * exp(-x / 5.0) * sin(3.0 * x);
}

void lagrange_polynomial(
    double (*func)(double), const double* points, unsigned int N_points, double a, double b,
     unsigned int N_xp, double* xp, double* fp, double* Pfp) {
    double dx = (b - a) / N_xp;

    for (unsigned int j = 0; j <= N_xp; ++j) {
        double x = a + j * dx;
        xp[j] = x;
        fp[j] = func(x);

        Pfp[j] = 0.0;
        for (unsigned int k = 0; k < N_points; ++k) {
            double Lk = 1.0;
            for (unsigned int i = 0; i < N_points; ++i) {
                if (i != k) {
                    Lk *= (x - points[i]) / (points[k] - points[i]);
                }
            }
            Pfp[j] += func(points[k]) * Lk;
        }
    }
}

int main() {
    // Example 1
    double points1[] = { 2, 2.5, 4 };
    const unsigned int N_points1 = sizeof(points1) / sizeof(points1[0]);
    const unsigned int N_xp = 300;
    double xp[N_xp + 1], fp[N_xp + 1], Pfp[N_xp + 1];

    std::cout << "# Beispiel 1: f(x) = 1/x mit Stützstellen 2, 2.5, 4\n";
    lagrange_polynomial(f1, points1, N_points1, 0.5, 6.0, N_xp, xp, fp, Pfp);

    std::cout << "# Index x f(x) P(x) Fehler\n";
    for (unsigned int j = 0; j <= N_xp; ++j) {
        std::cout << std::setw(3) << j
                  << std::fixed << std::setprecision(10)
                  << " " << xp[j]<< " " << fp[j]<< " " << Pfp[j]<< " " << fp[j] - Pfp[j] << "\n";
    }

    // Example 2
    double points2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    const unsigned int N_points2 = sizeof(points2) / sizeof(points2[0]);

    std::cout << "\n# Beispiel 2: f(x) = 10 * e^(-x/5) * sin(3x) mit Stützstellen 1..9\n";
    lagrange_polynomial(f2, points2, N_points2, 0.91, 9.07, N_xp, xp, fp, Pfp);

    std::cout << "# Index x f(x) P(x) Fehler\n";
    for (unsigned int j = 0; j <= N_xp; ++j) {
        std::cout << std::setw(3) << j
                  << std::fixed << std::setprecision(10)
                  << " " << xp[j] << " " << fp[j] << " " << Pfp[j] << " " << fp[j] - Pfp[j] << "\n";
    }

    return 0;
}