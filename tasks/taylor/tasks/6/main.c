#include <stdio.h>
#include <math.h>

double machine_epsilon(void) {
    double eps = 1.0;

    while (1.0 + eps / 2.0 > 1.0) {
        eps /= 2.0;
    }
    return eps;
}

double f(double x) {
    return sinh(x);
}

double teylor(double x, double eps, int* steps) {
    double ans = x;
    double t = x;
    int start = 2;
    *steps = 0;

    while (fabs(t) > eps && *steps < 100) {
        t *= x * x;
        t /= (start * (start + 1));
        start += 2;

        ans += t;
        *steps += 1;
    }

    return ans;
}

int main(void) {
    double a = 0.0, b = 1.0;
    int n = 20;
    double k = 1.0;
    double eps = machine_epsilon() * k;

    printf("x       | част сумма ряда | значение ф-ции | число итераций\n");
    for (int i = 0; i <= n; i++) {
        double x = a + (b - a) * i / n;
        int steps;
        double ans = teylor(x, eps, &steps);

        printf("%f        ", x);
        printf("%f      ", ans);
        printf(" %f       ", f(x));
        printf("%d\n", steps);
    }
    return 0;
}