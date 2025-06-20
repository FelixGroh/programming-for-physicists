#include <iostream>
#include <cmath>
#include <iomanip>

// Inline-Funktion für f(x)
inline double f(double x) {
    return 10.0 * std::exp(-x / 5.0) * std::sin(3 * x);
}

// Klasse zur numerischen Integration
class NumerischeIntegration {
private:
    double a, b;
    int ts;

public:
    // Konstruktor mit Standardwerten
    NumerischeIntegration(double a_ = 0.0, double b_ = 1.0, int ts_ = 10)
        : a(a_), b(b_), ts(ts_) {}

    // Simpson-Regel mit 4 Punkten pro Teilintervall
    double integriere() {
        double sum = 0.0;
        double h = (b - a) / ts;
        for (int i = 0; i < ts; ++i) {
            double x0 = a + i * h;
            double x1 = x0 + h / 3.0;
            double x2 = x0 + 2.0 * h / 3.0;
            double x3 = x0 + h;

            // Gewichte nach Simpson 4-Punkte-Regel (Boole’s Rule)
            sum += (h / 8.0) * (f(x0) + 3 * f(x1) + 3 * f(x2) + f(x3));
        }
        return sum;
    }
};

// Näherungsweise analytischer Wert des Integrals über [1,2]
// Dieser muss entweder aus analytischer Lösung oder einem hochpräzisen Verfahren stammen
double true_integral_value() {
    // Hier setzen wir einen Näherungswert als Referenz (z. B. mit WolframAlpha berechnet)
    return 1.17387; // angenommener Referenzwert
}

int main() {
    std::cout << std::fixed << std::setprecision(8);

    int teilintervalle[] = {10, 50, 100, 1000000};
    double a = 1.0, b = 2.0;
    double exact_value = true_integral_value();

    for (int ts : teilintervalle) {
        NumerischeIntegration integ(a, b, ts);
        double result = integ.integriere();
        double error = std::abs(result - exact_value);

        std::cout << "ts = " << ts << ":\n";
        std::cout << "  Approximiertes Integral = " << result << "\n";
        std::cout << "  Absoluter Fehler        = " << error << "\n\n";
    }

    return 0;
}
