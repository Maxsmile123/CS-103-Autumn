#include <stdio.h>
#include <math.h>

double get_epsilon(void){
    double eps = 1.0;
    while ((2.0 + eps)/2 > 1){
        eps/=2;
    }
    return eps;
}

double f(double x){
    return (1 - pow(x, 2)/2.0)*cos(x) - x/2*sin(x);
}

double Taylor(double x, double k){
    double sum = 1;
    double t = 1;
    int i = 0;
    double eps = get_epsilon();
    for (i; i <= 100; i++){
        t = -1*t*x*x*(2*(i+1)*(i+1) + 1)/((2*i*i + 1)*(2*i+2)*(2*i + 1));
        if (fabs(t) < eps*k){
            return sum;
        }
        sum+=t;
    }
    return sum;
}

int main(void){
    printf("x     C function   Taylor's method   Delta\n");
    for (double i = 0.1; i <= 0.62; i += 0.02){
        double c = f(i);
        double t = Taylor(i, 10);
        double d = fabs(c - t);
        printf("%2.2lf %12.5lf %12.5lf %12.5lf\n", i, c, t, d);
    }
    return 0;
}