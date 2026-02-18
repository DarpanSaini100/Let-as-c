#include <stdio.h>

int main() {
    int num, i, isPrime = 1;

    printf("Enter a number: ");
    scanf("%d", &num);

    
    if (num <= 1) {
        isPrime = 0;
    }

//A number cannot have a divisor greater than half of itself
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
