#include <stdio.h>
#include <math.h>

double F1(double x) {
    return exp(x) + logl(x) - 10*x;
}

double F2(double x) {
    return cos(x) - exp(-((x*x)/2)) + x - 1;
}

double F3(double x) {
    return 1 - x + sin(x) - logl(1+x);
}

double f1(double x) {
    return (exp(x) + logl(x))/10;
    //return 1 + sin(x) - logl(1+x);
}

double f2(double x) {
    return 1 + exp(-((x*x)/2)) - cos(x);
    //return 1 + sin(x) - logl(1+x);
}

double f3(double x) {
    return 1 + sin(x) - logl(1+x);
    //return 1 + sin(x) - logl(1+x);
}

double find_epsilon(double x) {
    double e = x;
    while ((x + e) != x) {
        e /= 2;
    }
    return e;
}

double f_derivative(double (*f)(double), double x, double e) {
    return (f(x+e) - f(x))/(e);
}

double second_f_derivative(double (*f)(double), double x, double e) {
    return (f(x + 2*e) - 2*f(x + e) + f(x)) / (e*e);
}

double dichotomy(double (*F)(double), double a, double b, double e) {

    int k = 0;
    double new;

    if (F(a)*F(b) > 0) {
        printf("На выбранном отрезке корней нет\n");
        //return 1;
    }

    else {
        while (fabs(a-b)>=e) {
            k+=1;
            new = (a+b)/2;

            if (F(new)==0) {
                a = new;
                b = new;
                break;
            }

            if ( F(a) * F(new) > 0) {
                a = new;
            }
            else {
                b = new;
            }
        }

        printf("Дихотомия: выполнено %d итераций\nx = %.4f\n", k, new);

    }   

}

double iterations(double (*f)(double), double (*F)(double), double a, double b, double x, double e) {

    double new_x;
    int k = 0;
    int flag;

    for (a+e; a<b; a+=e) {
        if ( fabs(f_derivative(f, x, e)) > 1 )
        flag = 0;
        break;
    }

    if ( flag ) {

        new_x = f(x);
        k+=1;

        while( fabs(new_x - x) > e ) {
            k+=1;
            x = new_x;
            new_x = f(x);
        }

        printf("Метод итераций: выполнено %d итераций\nx = %.4f\n", k, new_x);

    }

    else {
        printf("Метод итераций неприменим\n");
    }
}

double Newton(double (*F)(double), double a, double b, double x, double e) {

    double new_x;
    int k = 0, flag;

    for (a+e; a<b; a+=e) {
        if ( fabs( F(x)*second_f_derivative(F, x, e) ) > pow(f_derivative(F, x, e), 2) )
        flag = 0;
        break;
    }

    if ( flag ) {

        new_x = x - F(x)/f_derivative(F, x, e);
        k+=1;

        while( fabs(new_x - x) > e ) {
            k+=1;
            x = new_x;
            new_x = x - F(x)/f_derivative(F, x, e);
        }
    
        printf("Метод Ньютона: выполнено %d итераций\nx = %.4f\n", k, new_x);

    }

    else {
        printf("Метод Ньютона неприменим\n");
    }
}

void run(double a, double b, double e, double (*F)(double), double (*f)(double)) {
    dichotomy(F, a, b, e);
    iterations(f, F, a, b, (a+b)/2, e);
    Newton(F, a, b, (a+b)/2, e);
    puts("");
}

int main() {
    double e = pow(10, -10);
    run(3, 4, e, F1, f1);
    run(1, 2, e, F2, f2);
    run(1, 1.5, e, F3, f3);
}