#include <stdio.h>
#include <math.h>

// Function to solve the system of equations using Gauss-Seidel method
void gaussSeidel(double a[3][3], double b[3], double x[3], double tolerance, int maxIter) {
    double x_old[3];
    int iter = 0;
    double error;

    // Initialize x with initial guess (0,0,0)
    for (int i = 0; i < 3; i++) {
        x[i] = 0.0;
    }

    do {
        // Store the current values of x in x_old
        for (int i = 0; i < 3; i++) {
            x_old[i] = x[i];
        }

        // Update x, y, z using Gauss-Seidel iterative formulas
        x[0] = (b[0] - a[0][1] * x[1] - a[0][2] * x[2]) / a[0][0];
        x[1] = (b[1] - a[1][0] * x[0] - a[1][2] * x[2]) / a[1][1];
        x[2] = (b[2] - a[2][0] * x[0] - a[2][1] * x[1]) / a[2][2];

        // Calculate the error (max difference between old and new values)
        error = 0.0;
        for (int i = 0; i < 3; i++) {
            error = fmax(error, fabs(x[i] - x_old[i]));
        }

        iter++;
    } while (error > tolerance && iter < maxIter);

    // Print the result
    if (error <= tolerance) {
        printf("Solution converged after %d iterations.\n", iter);
        printf("x = %.6lf, y = %.6lf, z = %.6lf\n", x[0], x[1], x[2]);
    } else {
        printf("Solution did not converge after %d iterations.\n", iter);
    }
}

int main() {
    double a[3][3], b[3], x[3];
    double tolerance;
    int maxIter;

    // Input the coefficients of the system of equations
    printf("Enter the coefficients for the system of equations (3 equations, 3 variables):\n");
    for (int i = 0; i < 3; i++) {
        printf("Equation %d:\n", i + 1);
        printf("a%d1, a%d2, a%d3: ", i + 1, i + 1, i + 1);
        scanf("%lf %lf %lf", &a[i][0], &a[i][1], &a[i][2]);
        printf("b%d: ", i + 1);
        scanf("%lf", &b[i]);
    }

    // Input tolerance and maximum number of iterations
    printf("Enter the tolerance for convergence: ");
    scanf("%lf", &tolerance);
    printf("Enter the maximum number of iterations: ");
    scanf("%d", &maxIter);

    // Solve the system of equations using Gauss-Seidel method
    gaussSeidel(a, b, x, tolerance, maxIter);

    return 0;
}
