#include <stdio.h>
#include <math.h>

// Function representing the equation x^3 - 2x - 5
double f(double x) {
    return (x * x * x - 2 * x - 5);
}

// Bisection Method
void bisection(double a, double b, double tolerance) {
    double c;
    
    // Ensure that the function changes sign at the endpoints
    if (f(a) * f(b) >= 0) {
        printf("The function must have opposite signs at a and b.\n");
        return;
    }

    while ((b - a) / 2 > tolerance) {
        c = (a + b) / 2;
        if (f(c) == 0) {
            printf("Root found at x = %.6lf\n", c);
            return;
        }
        if (f(a) * f(c) < 0) b = c;
        else a = c;
    }
    c = (a + b) / 2;
    printf("Root approximation: %.6lf\n", c);
}

int main() {
    double a, b, tolerance;
    // Take user input
    printf("Enter the value of a (lower bound of the interval): ");
    scanf("%lf", &a);
    printf("Enter the value of b (upper bound of the interval): ");
    scanf("%lf", &b);
    printf("Enter the tolerance for root approximation: ");
    scanf("%lf", &tolerance);

    // Call the bisection method function
    bisection(a, b, tolerance);
    return 0;
}
