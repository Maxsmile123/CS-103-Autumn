#pragma once

#include <float.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>

long double Func(long double x) {
    long double t = x;
    long double sum = t;

    for (int k = 1; k < 100; k++) {
        t = -t * x * x * (2 * k - 1) / (2 * k + 1);
        sum += t;
    }
    return sum;
}

int Task() {
    double a, b;
    int n;
    scanf("%lf %lf %d", &a, &b, &n);
    double h = (b - a) / n;

    for (int i = 0; i <= n; i++) {
        long double x = a + i * h;
        long double s = Func(x);
        long double d = atanl(x);
        printf("%f %.20f %.20f %e\n",
               (double)x, (double)s, (double)d, (double)fabsl(s - d));
    }
    return 0;
}
