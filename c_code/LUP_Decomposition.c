#include <stdio.h>
#include <math.h>

#define N 3

void printMatrix(double A[N][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%.2f ", A[i][j]);
        }
        printf("\n");
    }
}

void LUP_Decompose(double A[N][N], int P[N]) {
    for(int i = 0; i < N; i++)
        P[i] = i;

    for(int k = 0; k < N; k++) {
        double max = 0.0;
        int k_prime = k;

        for(int i = k; i < N; i++) {
            if(fabs(A[i][k]) > max) {
                max = fabs(A[i][k]);
                k_prime = i;
            }
        }

        if(max == 0) {
            printf("Singular matrix!\n");
            return;
        }

        // Swap rows
        int temp = P[k];
        P[k] = P[k_prime];
        P[k_prime] = temp;

        for(int j = 0; j < N; j++) {
            double t = A[k][j];
            A[k][j] = A[k_prime][j];
            A[k_prime][j] = t;
        }

        for(int i = k + 1; i < N; i++) {
            A[i][k] /= A[k][k];
            for(int j = k + 1; j < N; j++) {
                A[i][j] -= A[i][k] * A[k][j];
            }
        }
    }
}

int main() {
    double A[N][N] = {
        {2, 0, 2},
        {1, 1, 1},
        {3, 2, 1}
    };

    int P[N];

    LUP_Decompose(A, P);

    printf("LUP Decomposition Matrix:\n");
    printMatrix(A);

    printf("Permutation Array:\n");
    for(int i = 0; i < N; i++)
        printf("%d ", P[i]);

    return 0;
}