#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

double f(double t, double y) {
    return y - t * t + 1;
}

double y_analytic(double t, double alpha) {
    return t * t + 2 * t + 1 + (alpha - 1) * std::exp(t);
}

std::vector<std::vector<double>> rungeKutta4(double a, double b, int N, double alpha) {
    double h = (b - a) / N;
    std::vector<std::vector<double>> result;

    double t = a;
    double y = alpha;

    for (int i = 0; i <= N; ++i) {
        double y_exact = y_analytic(t, alpha);
        double error = y - y_exact;

        result.push_back({t, y, y_exact, error});

        // Runge-Kutta 4
        double k1 = h * f(t, y);
        double k2 = h * f(t + h / 2.0, y + k1 / 2.0);
        double k3 = h * f(t + h / 2.0, y + k2 / 2.0);
        double k4 = h * f(t + h, y + k3);

        y += (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
        t += h;
    }

    return result;
}

// Funktion zur Ausgabe
void printResults(const std::vector<std::vector<double>>& data, int N) {
    std::cout << "\n# Ergebnisse für N = " << N << "\n";
    std::cout << "# t \t\t\t y_num \t\t\t y_ana \t\t\t Fehler \n";
    for (const auto& row : data) {
        std::cout << std::fixed << std::setprecision(15)
                  << row[0] << "\t" << row[1] << "\t" << row[2] << "\t" << row[3] << "\n";
    }
}

int main() {
    double a = 0.0;
    double b = 4.0;
    double alpha = 0.3;

    std::vector<int> N_values = {50, 500, 5000};

    for (int N : N_values) {
        std::vector<std::vector<double>> result = rungeKutta4(a, b, N, alpha);
        printResults(result, N);
    }

    return 0;
}
