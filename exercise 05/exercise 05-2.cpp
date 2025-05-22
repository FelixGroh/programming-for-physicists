#include <iostream>
#include <iomanip>

int main() {
    int epsilon[3][3][3] = {{{0}}};
    epsilon[0][1][2] = 1;
    epsilon[1][2][0] = 1;
    epsilon[2][0][1] = 1;
    epsilon[2][1][0] = -1;
    epsilon[1][0][2] = -1;
    epsilon[0][2][1] = -1;

    const double a[3] = {2.3, -1.36, 6.91};
    const double b[3] = {10.3, -4.34, 5.3};

    std::cout << std::fixed << std::setprecision(10);
    
    double scalar_index = 0.0;
    double scalar_pointer = 0.0;
    for (int i = 0; i < 3; ++i) {
        scalar_index += a[i] * b[i];
        scalar_pointer += *(a + i) *  *(b + i);
    }

    std::cout << "index : " << scalar_index << ", pointer: " << scalar_pointer << '\n';

    double c_index[3] = {0.0, 0.0, 0.0};
    double c_pointer[3] = {0.0, 0.0, 0.0};
    for (int k = 0; k < 3; ++k) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                c_index[k] += epsilon[i][j][k] * a[i] * b[j];
                c_pointer[k] += epsilon[i][j][k] * (*(a + i)) * (*(b + j));
            }
        }
    }

     std::cout << "scalar product (index):    (";
    for (int i = 0; i < 3; ++i) {
        std::cout << c_index[i] << (i < 2 ? ", " : ")\n");
    }

    std::cout << "cross-product (pointer):   (";
    for (int i = 0; i < 3; ++i) {
        std::cout << c_pointer[i] << (i < 2 ? ", " : ")\n");
    }

    return 0;
}