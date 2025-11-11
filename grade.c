#include <stdio.h>

int main() {
    float sub1, sub2, sub3, sub4, sub5;
    float total, percentage;

      printf("Enter marks of five subjects: ");
    scanf("%f %f %f %f %f", &sub1, &sub2, &sub3, &sub4, &sub5);

     total = sub1 + sub2 + sub3 + sub4 + sub5;
    percentage = (total / 500) * 100;

     printf("Percentage = %.2f%%\n", percentage);

     if (percentage >= 90 && percentage <= 100)
        printf("Grade: A\n");
    else if (percentage >= 80 && percentage < 90)
        printf("Grade: B\n");
    else if (percentage >= 60 && percentage < 80)
        printf("Grade: C\n");
    else
        printf("Grade: D\n");

    return 0;
}
