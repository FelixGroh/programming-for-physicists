#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    int N1 = 2536;
    int N2 = 45;
    int N3 = 20;

    double s1 = 0, s2 = 0, s3 = 0;

    for (int k = 0; k <= N1; k++) {
       s1 += std::pow(0.5, k); 
    }

    for (int k = 3; k <= N2; k++) {
        s2 += std::pow(k, 3.0 / 5.0);
    }

    for (int k = -5; k <= N3; k++) {
        s3 += std::pow(k, 5) / (std::exp(-k) + 1);
    }
    
    std::cout << std::fixed;
    std::cout << std::setprecision(15);
    std::cout << "s1 = " << s1 << ", s2 = " << s2 << ", s3 = " << s3 << '\n';

    return 0;
}