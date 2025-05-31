#include <stdio.h>

// Function to calculate the Lagrange basis polynomial l_i(x)
double lagrange_basis(double x, double x_data[], int i, int n) {
    double result = 1.0;
    for (int j = 0; j < n; j++) {
        if (j != i) {
            result *= (x - x_data[j]) / (x_data[i] - x_data[j]);
        }
    }
    return result;
}

// Function to perform Lagrange interpolation
double lagrange_interpolation(double x, double x_data[], double y_data[], int n) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        result += y_data[i] * lagrange_basis(x, x_data, i, n);
    }
    return result;
}

int main() {
    int n;

    // Input number of data points
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double x_data[n], y_data[n];

    // Input data points (x, y)
    printf("Enter the x and y values for the data points:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%lf", &x_data[i]);
        printf("y[%d] = ", i);
        scanf("%lf", &y_data[i]);
    }

    double x, y;

    // Ask the user for the value of x to estimate y
    while(1){
        printf("Enter the value of x for which you want to find the corresponding y: ");
        scanf("%lf", &x);

        // Perform the Lagrange interpolation to find y
        y = lagrange_interpolation(x, x_data, y_data, n);

        // Output the result
        printf("The estimated value of y for x = %.6lf is: %.6lf\n", x, y);
        printf("\nPress [CTRL+C] to Terminate the Program.******\n");
    }
    return 0;
}
