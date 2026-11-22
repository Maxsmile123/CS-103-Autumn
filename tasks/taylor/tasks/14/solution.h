//14_variant
#include <stdio.h>
#include <math.h>

double Taylor(double x_i, double delta, int *iterations) {
    double term = -3.0;
    double summ = term;
    int i =0;
    while (fabs(term) >= delta && i<100) {

        term = term*x_i*(i+4.0)/(i+3.0);
        summ += term;
        i++;
        
    }
    *iterations = i;
    return summ;
    
}

double standard(double x) {
    return (2.0*x -3.0)/pow((x - 1.0),2);
}

double machine_epsilon() {
    double eps = 1.0;
    double pred_eps = eps;
    while (1.0 + eps != 1.0) {
        pred_eps = eps;
        eps *= 0.5;
    }
    return pred_eps;
}

int main(void) {
    double a = 0.1, b = 0.6;
    int n = 5;
    int iterations;
    double eps = 0.0;
    double shag = (b-a)/n;
    eps = machine_epsilon();
    double delta = eps*100;
    printf("x      Taylor                 standard             iterations\n");
    for (int i = 0; i<=n; i++) {
        double x_i = a + i * shag;
        double result = Taylor(x_i, delta, &iterations);
        printf("%.2f  %20.16f  %20.16f  %3d\n", x_i, result, standard(x_i), iterations);

    }
    
    return 0;
}
