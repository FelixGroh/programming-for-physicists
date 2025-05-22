#include <iostream>

// Call-by-Pointer
void switch_pointer(double* a, double* b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

// Call-by-Reference
void switch_reference(double& a, double& b) {
    double temp = a;
    a = b;
    b = temp;
}

int main() {
    double x = 5.0, y = 10.0;
    
    // Call-by-Pointer
    switch_pointer(&x, &y);

    // Call-by-Reference
    switch_reference(x, y);
}

/* Eine Analoge Funktion mit call-by-value würde die Variablen im Hauptprogramm überhaupt nicht vertauschen. */