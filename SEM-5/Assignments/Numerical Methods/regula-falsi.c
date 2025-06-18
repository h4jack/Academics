#include <stdio.h>
#include <math.h>

// Function representing the equation x^3 - 5x - 1
double f(double x) {
    return (x * x * x - 5 * x + 1);
}

// Regula Falsi Method
void regulaFalsi(double a, double b, double tolerance) {
    double c;
    // Ensure that the function has opposite signs at the endpoints
    if (f(a) * f(b) >= 0) {
        printf("The function must have opposite signs at a and b.\n");
        return;
    }
    while (fabs(f(a)) > tolerance) {
        // Find the point where the line intersects the x-axis
        c = b - (f(b) * (b - a)) / (f(b) - f(a));
        // If the root is found or the approximation is within tolerance
        if (fabs(f(c)) < tolerance) {
            printf("Root found at x = %.6lf\n", c);
            return;
        }
        // Narrow down the interval
        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    }

    printf("Root approximation: %.6lf\n", c);
}

int main() {
    double a, b, tolerance;

    // Take user input for the interval and tolerance
    printf("Enter the value of a (lower bound of the interval): ");
    scanf("%lf", &a);
    printf("Enter the value of b (upper bound of the interval): ");
    scanf("%lf", &b);
    printf("Enter the tolerance for root approximation: ");
    scanf("%lf", &tolerance);

    // Call the regula falsi method function
    regulaFalsi(a, b, tolerance);

    return 0;
}
