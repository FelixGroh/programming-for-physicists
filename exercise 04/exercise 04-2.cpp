#include <iostream>
#include <iomanip>

void fibonacci_seq(int n, int* fibonacci_arr) {
    if (n == 0) {
        *(fibonacci_arr + 0) = 0;
    }
    else if (n == 1) {
        *(fibonacci_arr + 1) = 1;
    }
    else {
        fibonacci_seq(n - 1, fibonacci_arr);
        *(fibonacci_arr + n) = *(fibonacci_arr + n - 1) + *(fibonacci_arr + n - 2);
    }
}

int main() {
    const int N = 40;
    int fibonacci_arr[N + 1];

    fibonacci_seq(N, fibonacci_arr); // Compute up to N-1

    std::cout << "index,fn" << '\n';
    std::cout << std::fixed << std::setprecision(15);
    for (int j = 0; j <= N; j++) {
        std::cout << j << "," << *(fibonacci_arr + j) << '\n';
    }

    return 0;
}
