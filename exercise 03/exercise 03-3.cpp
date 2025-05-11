#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    // exercise 3-3a
    long long prod = 1;
    for (int k = 1; k <= 11; ++k) {
        prod *= (k * k);
    }
    std::cout << "Product = " << prod << '\n';

    // exercise 3-3b
    double sum = 0.0;
    for (int k = 0; k <= 20; ++k) {
        for (int i = 0; i <= 10; ++i) {
            if (i != k) {
                sum += k + std::pow(i, 3) / std::pow(k - i, 2);
            }
        }
    }
    std::cout << std::fixed << std::setprecision(15);
    std::cout << "Double summation = " << sum << '\n';

    // exercise 3-3c
    long long target = 672013120;
    long long total = 0;
    int N = 0;
    while (total < target) {
        long long inner_sum = 0;
        for (int i = 0; i <= 250; ++i) {
            if (i != N) {
                inner_sum += N + i * i;
            }
        }
        total += inner_sum;
        ++N;
    }
    std::cout << "N = " << N - 1 << ", sum = " << total <<'\n';

    return 0;
}