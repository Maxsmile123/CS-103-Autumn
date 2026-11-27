#include <stdio.h>
#include <math.h>

double f(double x) {
    return exp(x) + sqrt(1 + exp(2*x)) - 2;
}

double f_iter(double x) {
    return x - 0.9 * f(x);
}

double f_derivative(double x) {
    return exp(x) + exp(2*x) / sqrt(1 + exp(2*x));
}

double f_derivative2(double x) {
    return exp(x) + 2*exp(2*x) / sqrt(1 + exp(2*x)) - exp(4*x) / pow(1 + exp(2*x), 1.5);
}

double f_iter_div(double x) {
    return 1 - 0.9 * (exp(x) + exp(2*x) / sqrt(1 + exp(2*x)));
}

double f_iter_false(double x) {
    return log(2 - sqrt(1 + exp(2*x)));
}

double f_iter_div_false(double x) {
    return -exp(2*x) / (sqrt(1 + exp(2*x)) * (2 - sqrt(1 + exp(2*x))));
}

double diahtomia(double begin, double end, unsigned* k) {
    double x;
    *k = 0;

    while (end - begin >= 0.0001) {
        x = (begin + end) / 2;
        (*k)++;
        if (f(begin) * f(x) > 0) {
            begin = x;
        }
        else {
            end = x;
        }
    }

    return (begin + end) / 2;
}

double iteration(float begin, float end, unsigned* k){
    double x_now = (begin+end)/2;
    double x_prev = end;
    *k = 0;

    for (double i = begin; i < end; i+=0.0001){
        if (fabs(f_iter_div(i)) < 1){
            continue;
        }
        else {
            printf("Iteration's method can't be used in this case\n");
            return NAN;
        }
    }

    while (fabs(x_now - x_prev) >= 0.0001){
        x_prev = x_now;
        x_now = f_iter(x_prev);
        (*k)++;
        if (*k > 10000) {
            printf("Too big iterations");
            return NAN;
        }
    }
    return x_now;
}

double Newton(float begin, float end, unsigned* k){
    double x_now = (begin + end)/2;
    double x_prev = end;
    *k = 0;

    for (double i = end; i >= begin; i-=0.0001){
        if (fabs(f(i)*f_derivative2(i)) >= pow(f_derivative(i), 2)){
            printf("Newton's method can't be used in this case");
            return NAN;
        }
    }

    while (fabs(x_now - x_prev) >= 0.0001){
       x_prev = x_now;
       x_now = x_prev - f(x_prev)/f_derivative(x_prev);
       (*k)++;
       if (*k > 10000) {
            printf("Too big iterations");
            return NAN;
        }
    }
    return x_now;
}

int main(void) {
    unsigned k; 
    double root = diahtomia(-1, 0, &k);
    printf("By diahtomia method root is near to %.4lf. Number of iterations is %u\n", root, k);

    root = iteration(-1, 0, &k);
    if (isfinite(root)){
        printf("By iterations method root is near to %.4lf. Number of iterations is %u\n", root, k);;   
    }
    root = Newton(-1, 0, &k);
    if (isfinite(root)){
        printf("By Newton's method root is near to %.4lf. Number of iterations is %u\n", root, k);   
    }
    return 0;
}