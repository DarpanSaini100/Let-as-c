#include <stdio.h>

int main() {
    int num, i, isPrime = 1;

    printf("Enter a number: ");
    scanf("%d", &num);

    // 0 and 1 are not prime numbers
    if (num <= 1) {
        isPrime = 0;
    }

    // Check divisibility
    for(i = 2; i <= num/2; i++) {
        if(num % i == 0) {
            isPrime = 0;
            break;
        }
    }

    if(isPrime)
        printf("%d is a Prime Number.", num);
    else
        printf("%d is NOT a Prime Number.", num);

    return 0;
}
