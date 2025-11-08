#include <stdio.h>

int reverseDigit(int n) {
    int ans = 0;
    while(n) {
        ans = (ans * 10) + (n % 10);
        n /= 10;
    }
    return ans;
}

int main() {
    int n;
    printf("Enter a number :- ");
    scanf("%d", &n);

    printf("Reverse Number :- %d", reverseDigit(n));

    printf("\n");
    return 0;
}
