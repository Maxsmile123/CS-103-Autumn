#include <stdio.h>
#include <math.h>

#define EPS 1e-10

double calculate_direct(double x) {
    return (1 + 2 * x * x) * exp(x * x);
}

double calculate_series(double x) {
    double sum = 1.0;
    double term = 1.0;

    int m = 0;

    while (fabs(term) > EPS) {
        term *= (2.0 * m + 3) * x * x /
                ((m + 1.0) * (2.0 * m + 1));

        m++;

        sum += term;
    }

    return sum;
}

int main() {
    double x_values[] = {0.0, 1.0};

    for (int i = 0; i < 2; i++) {
        double x = x_values[i];

        double direct = calculate_direct(x);
        double series = calculate_series(x);

        printf("x = %.1f\n", x);
        printf("Direct: %.10f\n", direct);
        printf("Series: %.10f\n", series);
        printf("Difference: %.12f\n\n",
               fabs(direct - series));
    }

    return 0;
}
