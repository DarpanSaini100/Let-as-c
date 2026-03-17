#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

// Complex number structure
typedef struct {
    double real;
    double imag;
} Complex;

// Complex addition
Complex add(Complex a, Complex b) {
    Complex res;
    res.real = a.real + b.real;
    res.imag = a.imag + b.imag;
    return res;
}

// Complex subtraction
Complex subtract(Complex a, Complex b) {
    Complex res;
    res.real = a.real - b.real;
    res.imag = a.imag - b.imag;
    return res;
}

// Complex multiplication
Complex multiply(Complex a, Complex b) {
    Complex res;
    res.real = a.real * b.real - a.imag * b.imag;
    res.imag = a.real * b.imag + a.imag * b.real;
    return res;
}

// Recursive FFT
void fft(Complex *a, int n) {
    if (n <= 1)
        return;

    // Divide into even and odd
    Complex even[n/2], odd[n/2];

    for (int i = 0; i < n/2; i++) {
        even[i] = a[2*i];
        odd[i]  = a[2*i + 1];
    }

    // Recursive calls
    fft(even, n/2);
    fft(odd, n/2);

    // Combine
    for (int k = 0; k < n/2; k++) {
        double angle = -2 * PI * k / n;
        Complex w;
        w.real = cos(angle);
        w.imag = sin(angle);

        Complex t = multiply(w, odd[k]);

        a[k] = add(even[k], t);
        a[k + n/2] = subtract(even[k], t);
    }
}

// Utility function to print result
void printFFT(Complex *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("X[%d] = %.2f + %.2fi\n", i, a[i].real, a[i].imag);
    }
}

// Driver code
int main() {
    int n = 4;

    Complex input[4] = {
        {1, 0},
        {2, 0},
        {3, 0},
        {4, 0}
    };

    fft(input, n);

    printf("FFT Result:\n");
    printFFT(input, n);

    return 0;
}