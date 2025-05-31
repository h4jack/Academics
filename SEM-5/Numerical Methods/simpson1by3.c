#include <stdio.h>
#include <math.h>

double f(double x) {
    // taking function: f(x) = x^2 + 2x + 1
    return 1/(1+x*x);
}

// Function to perform Simpson's 1/3 rule
double simpson13(double a, double b, int n) {
    if (n % 2 != 0) {
        printf("Number of intervals (n) must be even for Simpson's 1/3 rule.\n");
        return -1;  // Return error code
    }

    // Step size (h)
    double h = (b - a) / n;

    // Apply Simpson's 1/3 rule formula
    double sum = f(a) + f(b);

    // Apply the 4*f(x_i) terms (odd indices)
    for (int i = 1; i < n; i += 2) {
        sum += 4 * f(a + i * h);
    }

    // Apply the 2*f(x_i) terms (even indices)
    for (int i = 2; i < n - 1; i += 2) {
        sum += 2 * f(a + i * h);
    }

    // Final result
    double result = sum * h / 3;
    return result;
}

int main() {
    double a, b, result;
    int n;

    // Ask user for the limits of integration
    printf("Enter the lower limit (a): ");
    scanf("%lf", &a);
    printf("Enter the upper limit (b): ");
    scanf("%lf", &b);

    // Ask for the number of subintervals (n must be even)
    printf("Enter the number of subintervals (n, must be even): ");
    scanf("%d", &n);

    // Perform Simpson's 1/3 rule integration
    result = simpson13(a, b, n);

    // Output the result if valid
    if (result != -1) {
        printf("The estimated value of the integral is: %.6lf\n", result);
    }

    return 0;
}
