#include <iostream>
#include <iomanip>
#include <vector>

class LogisticMap {
private:
    double a_start, a_end, a_step;
    unsigned int N;
    double x0;

public:
    LogisticMap(double a_start, double a_end, double a_step = 0.0025, unsigned int N = 300, double x0 = 0.1)
        : a_start(a_start), a_end(a_end), a_step(a_step), N(N), x0(x0) {}

    void generateDiagram() const {
        std::cout << std::fixed << std::setprecision(15);
        std::cout << "# 0: Verzweigungsparameter a \n# 1...: Werte der Folge x_n \n";

        for (double a = a_start; a <= a_end; a += a_step) {
            double x = x0;
            std::cout << a << " ";

            for (unsigned int n = 0; n <= N; ++n) {
                std::cout << x << " ";
                x = a * x * (1.0 - x);
            }
            std::cout << "\n";
        }
    }
};

int main() {
    // Beispiel: a \in [2.8, 4.0], N = 300
    LogisticMap map(2.8, 4.0, 0.005, 100);
    map.generateDiagram();

    return 0;
}
