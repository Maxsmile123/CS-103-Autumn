//14_15_16

#include <stdio.h>
#include <math.h>

double f_14(double x) {
    return tan(x/2.0) - 1.0/tan(x/2.0) + x;
}

double f_15(double x) {
    return 0.4 + atan(sqrt(x)) -x;
}

double f_16(double x) {
    return 3*sin(sqrt(x)) + 0.35*x - 3.8;
}

double df_14(double x) {
    return 1.0 + 1.0/(2.0*pow(cos(x/2.0),2)) + 1.0/(2.0*pow(sin(x/2.0),2));
}

double df_15(double x) {
    return 1.0 / (2.0 * sqrt(x) * (1.0 + x)) - 1.0;
}

double df_16(double x) {
    return 3.0 * cos(sqrt(x)) / (2.0 * sqrt(x)) + 0.35;
}

double g_14(double x) {
    return  x - 0.2*f_14(x);
}

double g_15(double x) {
    return 0.4 +atan(sqrt(x));
}

double g_16(double x) {
    return x - 2.0*f_16(x);
}

double bisection(double (*f)(double), double a, double b, double eps, int *iterations, double *accuracy) {
    int count = 0;
    double f_a = f(a);
    double f_b = f(b);
    if (f_a*f_b < 0) {
        while (fabs(a-b) >= eps) {
            double c = (a+b)/2.0;
            double f_c = f(c);
            count++;
            if (f_c == 0) {
                *iterations = count;
                *accuracy = 0.0;
                return c;
            } else {
                if (f_a*f_c<0) {
                    b = c;
                } else {
                    a = c;
                    f_a = f_c;
                }
            }
        }
        
        *iterations = count;
        *accuracy = fabs(b-a)/2.0;
        return (a+b)/2.0;
    }
    return -1;
}

double simple_iterations(double (*g)(double), double a, double b, double eps, int *iterations, double *accuracy) {
    double x_pred = (a+b)/2.0;
    double x = g(x_pred);
    int count = 1;
    while (fabs(x-x_pred)>=eps && count<1000 && isfinite(x)) {
        count++;
        x_pred = x;
        x = g(x_pred);
    }
    if (!isfinite(x) || count >= 1000) {
        *iterations = count;
        *accuracy = NAN;
        return NAN;
    }
    *iterations = count;
    *accuracy = fabs(x-x_pred);
    return x;
}

double Newton(double (*f)(double), double(*df)(double), double a, double b, double eps, int *iterations, double *accuracy) {
    double x_pred = (a+b)/2.0;
    double x = x_pred - f(x_pred)/df(x_pred);
    int count = 1;
    while (fabs(x-x_pred)>=eps && count<1000 && isfinite(x)) {
        count++;
        x_pred = x;
        x = x_pred - f(x_pred)/df(x_pred);
    }
    if (!isfinite(x) || count >= 1000) {
        *iterations = count;
        *accuracy = NAN;
        return NAN;
    }
    *iterations = count;
    *accuracy = fabs(x-x_pred);
    return x;
}

int main(void) {
    int iterations = 0;
    double accuracy = 0.0;
    double eps = 0.00001;
    printf("%-14s %-10s %-16s %-16s %-14s %-12s\n", "Method", "Equation", "Computed Root", "Reference Root", "Accuracy", "Iterations");

    double bisection_14 = bisection(f_14, 1.0, 2.0, eps, &iterations, &accuracy);
    printf("%-14s %-10d %-16.8f %-16.8f %-14.3e %-12d\n", "Bisection", 14, bisection_14, 1.0769, accuracy, iterations);

    double bisection_15 = bisection(f_15, 1.0, 2.0, eps, &iterations, &accuracy);
    printf("%-14s %-10d %-16.8f %-16.8f %-14.3e %-12d\n", "Bisection", 15, bisection_15, 1.2388, accuracy, iterations);

    double bisection_16 = bisection(f_16, 2.0, 3.0, eps, &iterations, &accuracy);
    printf("%-14s %-10d %-16.8f %-16.8f %-14.3e %-12d\n", "Bisection", 16, bisection_16, 2.2985, accuracy, iterations);

    double simple_14 = simple_iterations(g_14, 1.0, 2.0, eps, &iterations, &accuracy);
    printf("%-14s %-10d %-16.8f %-16.8f %-14.3e %-12d\n", "Fixed-Point", 14, simple_14, 1.0769, accuracy, iterations);

    double simple_15 = simple_iterations(g_15, 1.0, 2.0, eps, &iterations, &accuracy);
    printf("%-14s %-10d %-16.8f %-16.8f %-14.3e %-12d\n", "Fixed-Point", 15, simple_15, 1.2388, accuracy, iterations);

    double simple_16 = simple_iterations(g_16, 2.0, 3.0, eps, &iterations, &accuracy);
    printf("%-14s %-10d %-16.8f %-16.8f %-14.3e %-12d\n", "Fixed-Point", 16, simple_16, 2.2985, accuracy, iterations);

    double Newton_14 = Newton(f_14, df_14, 1.0, 2.0, eps, &iterations, &accuracy);
    printf("%-14s %-10d %-16.8f %-16.8f %-14.3e %-12d\n",  "Newton", 14, Newton_14, 1.0769, accuracy, iterations);

    double Newton_15 = Newton(f_15, df_15, 1.0, 2.0, eps, &iterations, &accuracy);
    printf("%-14s %-10d %-16.8f %-16.8f %-14.3e %-12d\n", "Newton", 15, Newton_15, 1.2388, accuracy, iterations);

    double Newton_16 = Newton(f_16, df_16, 2.0, 3.0, eps, &iterations, &accuracy);
    printf("%-14s %-10d %-16.8f %-16.8f %-14.3e %-12d\n", "Newton", 16, Newton_16, 2.2985, accuracy, iterations);
    return 0;
}
