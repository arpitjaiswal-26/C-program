
 #include <stdio.h>

int main() {
    int n;

    printf("Enter number of elements in each array: ");
    scanf("%d", &n);

    int a[n], b[n], sum[n];

    
    printf("Enter elements of first array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    
    printf("Enter elements of second array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    for (int i = 0; i < n; i++) {
        sum[i] = a[i] + b[i];
    }


    printf("Sum of corresponding elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", sum[i]);
    }

    printf("\n");
    return 0;
}
