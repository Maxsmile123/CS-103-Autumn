#include <stdio.h>
#include <math.h>

double f(double x) {
    return log(x) - x + 1.8;
}

double f_derivative(double x) {
    return 1/x - 1;
}

double f_derivative2(double x) {
    return -1*1/pow(x, 2);
}


double f_iter(double x) {
    return log(x) + 1.8;
}

double f_iter_div(double x) {
    return 1/x;
}

double f_iter_false(double x) {
    return exp(x - 1.8);
}

double f_iter_div_false(double x) {
    return exp(x - 1.8);
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

    while (fabs(x_now - x_prev) >= 0.00001){
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

    for (double i = end; i >= begin; i-=0.00001){
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
    double root = diahtomia(2, 3, &k);
    printf("By diahtomia method root is near to %.4lf. Number of iterations is %u\n", root, k);

    root = iteration(2, 3, &k);
    if (isfinite(root)){
        printf("By iterations method root is near to %.4lf. Number of iterations is %u\n", root, k);;   
    }
    root = Newton(2, 3, &k);
    if (isfinite(root)){
        printf("By Newton's method root is near to %.4lf. Number of iterations is %u\n", root, k);   
    }
    return 0;
}