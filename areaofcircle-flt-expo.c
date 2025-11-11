#include <stdio.h>
#define PI 3.14159

int main() {
    float radius, area;

     printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

     area = PI * radius * radius;

    printf("Area of circle (floating notation): %.2f\n", area);
    printf("Area of circle (exponential notation): %.2e\n", area);

    return 0;
}
