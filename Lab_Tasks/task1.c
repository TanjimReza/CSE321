#include <stdio.h> 


double area(double radius) {
    double pi = 3.14;
    return pi * radius * radius;
}

double circumference(double radius) {
    double pi = 3.14;
    return 2 * pi * radius;
}

double diameter(double radius) {
    return 2 * radius;
}

int main() {
    double radius;
    printf("Enter radius of circle: ");
    scanf("%lf", &radius);
    printf("Diameter = %.1f, Circumference = %.4f, Area = %.4f \n", diameter(radius), circumference(radius), area(radius));
    return 0;
}

