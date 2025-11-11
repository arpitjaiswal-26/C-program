#include <stdio.h>

int main() {
    int n;
    long long fact = 1; // use long long to handle large results

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        for (int i = 1; i <= n; i++) {
            fact *= i;
        }
        printf("Factorial of %d = %lld\n", n, fact);
    }

    return 0;
}
