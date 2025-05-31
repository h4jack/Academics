#include <stdio.h>
#include <math.h>

// Function representing the equation x^3 - 3x - 5
double f(double x) {
    return (x * x * x - 3 * x - 5);
}

// Derivative of the function f(x) = x^3 - 3x - 5
double f_prime(double x) {
    return (3 * x * x - 3);  // Derivative: 3x^2 - 3
}

// Newton-Raphson Method
void newtonRaphson(double x0, double tolerance) {
    double x1;

    // Iteration process
    while (1) {
        // Calculate the next approximation
        x1 = x0 - f(x0) / f_prime(x0);

        // If the difference between successive approximations is within tolerance, stop
        if (fabs(x1 - x0) < tolerance) {
            printf("Root found at x = %.6lf\n", x1);
            return;
        }

        // Update the approximation for the next iteration
        x0 = x1;
    }
}

int main() {
    double x0, tolerance;

    // Take user input for the initial guess and tolerance
    printf("Enter the initial guess for the root: ");
    scanf("%lf", &x0);
    printf("Enter the tolerance for root approximation: ");
    scanf("%lf", &tolerance);

    // Call the Newton-Raphson method
    newtonRaphson(x0, tolerance);

    return 0;
}
