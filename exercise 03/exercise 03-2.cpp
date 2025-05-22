#include <iostream>
#include <cmath>
#include <iomanip>

double x_t1_f(float x_t) {
    if (x_t < 0.5) {
        return 2.0 * x_t;
    }
    else {
        return 2.0 * x_t - 1.0;
    }
}

double x_t1_d(double x_t) {
    if (x_t < 0.5) {
        return 2.0 * x_t;
    }
    else {
        return 2.0 * x_t - 1.0;
    }
}

int main()  {
    const int N = 70;
    float x_t_f[4] = {1. / 3, 1. / 7, 1. / 11, 1. / std::pow(2, 20)};
    double x_t_d[4] = {1. / 3, 1. / 7, 1. / 11, 1. / std::pow(2, 20)};
    
    std::cout << std::fixed;
    std::cout << std::setprecision(15);
    std::cout << "x_0f,x_0d,x_1f,x_1d,x_2f,x_2d,x_3f,x_3d" << '\n';
    std::cout << x_t_f[0] << "," << x_t_d[0] << "," << x_t_f[1] << "," << x_t_d[1] << "," << x_t_f[2] << "," << x_t_d[2] << "," << x_t_f[3] << "," << x_t_d[3] << '\n';

    for (int n = 0; n < N; n++) {
        for (int j = 0; j < 4; j++) {
            x_t_f[j] = x_t1_f(x_t_f[j]);
            x_t_d[j] = x_t1_d(x_t_d[j]);
        }
            std::cout << x_t_f[0] << "," << x_t_d[0] << "," << x_t_f[1] << "," << x_t_d[1] << "," << x_t_f[2] << "," << x_t_d[2] << "," << x_t_f[3] << "," << x_t_d[3] << '\n';
    }

    return 0;
}

/* Offensichtlich gehen bei Brüchen, welche nicht ohne Präzisionsfehler dargestellt werden können, 
je Iteration immer weitere Informationen verloren, sodass irgendwann die Zahlen representation auf 0.5
konvergiert und schließlich bei 0 verbleibt. Die geschieht bei floats entsprechend schneller als bei doubles.
Für Zahlen aus dem Raum der rationalen Zahlen ließe sich dies durch eine Bruchdarstellung verhindern,
wobei ein Integer den Zähler und ein Integer den Nenner darstellte. Dies funktioniert, da Integer
einen verlustfreien Datentypen darstellen*/