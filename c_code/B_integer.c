#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Complex number structure
typedef struct {
    double real;
    double imag;
} Complex;

// Complex operations
Complex add(Complex a, Complex b) {
    Complex r = {a.real + b.real, a.imag + b.imag};
    return r;
}

Complex sub(Complex a, Complex b) {
    Complex r = {a.real - b.real, a.imag - b.imag};
    return r;
}

Complex mul(Complex a, Complex b) {
    Complex r = {
        a.real * b.real - a.imag * b.imag,
        a.real * b.imag + a.imag * b.real
    };
    return r;
}

// FFT function
void fft(Complex *a, int n, int invert) {
    if (n == 1) return;

    Complex *even = (Complex*)malloc(n/2 * sizeof(Complex));
    Complex *odd  = (Complex*)malloc(n/2 * sizeof(Complex));

    for (int i = 0; i < n/2; i++) {
        even[i] = a[2*i];
        odd[i]  = a[2*i + 1];
    }

    fft(even, n/2, invert);
    fft(odd, n/2, invert);

    double angle = 2 * PI / n * (invert ? -1 : 1);
    Complex w = {1, 0};
    Complex wn = {cos(angle), sin(angle)};

    for (int i = 0; i < n/2; i++) {
        Complex t = mul(w, odd[i]);

        a[i] = add(even[i], t);
        a[i + n/2] = sub(even[i], t);

        if (invert) {
            a[i].real /= 2;
            a[i].imag /= 2;
            a[i + n/2].real /= 2;
            a[i + n/2].imag /= 2;
        }

        w = mul(w, wn);
    }

    free(even);
    free(odd);
}

// Multiply big integers
void multiply(char *num1, char *num2) {
    int n1 = strlen(num1);
    int n2 = strlen(num2);

    int n = 1;
    while (n < n1 + n2) n <<= 1;

    Complex *fa = (Complex*)calloc(n, sizeof(Complex));
    Complex *fb = (Complex*)calloc(n, sizeof(Complex));

    // Store digits in reverse order
    for (int i = 0; i < n1; i++)
        fa[i].real = num1[n1 - i - 1] - '0';

    for (int i = 0; i < n2; i++)
        fb[i].real = num2[n2 - i - 1] - '0';

    // Apply FFT
    fft(fa, n, 0);
    fft(fb, n, 0);

    // Point-wise multiplication
    for (int i = 0; i < n; i++)
        fa[i] = mul(fa[i], fb[i]);

    // Inverse FFT
    fft(fa, n, 1);

    // Extract result
    int *result = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
        result[i] = (int)(fa[i].real + 0.5);

    // Handle carry
    for (int i = 0; i < n; i++) {
        if (result[i] >= 10) {
            result[i+1] += result[i] / 10;
            result[i] %= 10;
        }
    }

    // Print result (reverse)
    int i = n - 1;
    while (i > 0 && result[i] == 0) i--;

    printf("Result: ");
    for (; i >= 0; i--)
        printf("%d", result[i]);
    printf("\n");

    free(fa);
    free(fb);
    free(result);
}

// Driver
int main() {
    char num1[] = "123456";
    char num2[] = "789012";

    multiply(num1, num2);

    return 0;
}