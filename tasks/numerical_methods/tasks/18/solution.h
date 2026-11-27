#pragma once

#include <stdio.h>
#include <math.h>

typedef double (*EquationFunc)(double);

double first_equation(double x) {
    return x + sqrt(x) + cbrt(x) - 2.5;
}
double second_equation(double x) {
    return x - 1/(3 + sin(3.6*x));
}
double third_equation(double x) {
    return 0.1*x*x - x*log(x);
}

double first_iteration(double x) {
    return 2.5 - sqrt(x) - cbrt(x);
}
double second_iteration(double x) {
    return 1.0/(3.0+sin(3.6*x));
}
double third_iteration(double x) {
    return exp(0.1*x);
}

double first_derivative(double x) {
    return 1.0 + (1.0/(2.0*sqrt(x))) + (1.0/(3.0*cbrt(x*x)));
}
double second_derivative(double x) {
    return 1 + 3.6*cos(3.6*x)/pow(3+sin(3.6*x), 2.0);
}
double third_derivative(double x) {
    return 0.2*x - log(x) - 1;
}

double solve_dichotomy(EquationFunc func, double left_border, double right_border, double epsilon) {
    while ((right_border - left_border) > epsilon) {
        double midpoint = (right_border + left_border) / 2;
        if ((func(left_border) * func(midpoint)) < 0) {
            right_border = midpoint;
        }
        else {
            left_border = midpoint;
        }
    }
    return (left_border + right_border) / 2;
}

double solve_iterations(EquationFunc func, double left_border, double right_border, double epsilon) {
    double start = (left_border + right_border) / 2;
    double current = func(start);
    while (fabs(current - start) > epsilon) {
        start = current;
        current = func(start);
    }
    return current;
}

double solve_newton( EquationFunc func, EquationFunc deriv ,double left_border, double right_border, double epsilon) {
    double start = (left_border + right_border) / 2;
    double current = start - func(start)/deriv(start);
    while(fabs(start - current) > epsilon) {
        start = current;
        current = start - func(start)/deriv(start);
    }
    return current;
}

int Task () {
    double epsilon = 0;
    if (scanf("%lf",&epsilon) != 1 || epsilon <= 0.0) {
        return 1;
    }
    double res1_dichotomy = solve_dichotomy(first_equation, 0.4, 1.0, epsilon);
    double res1_iterations = solve_iterations(first_iteration, 0.4, 1.0, epsilon);
    double res1_newton = solve_newton(first_equation, first_derivative, 0.4, 1.0, epsilon);

    double res2_dichotomy = solve_dichotomy(second_equation, 0.0, 0.85, epsilon);
    double res2_iterations = solve_iterations(second_iteration, 0.0, 0.85, epsilon);
    double res2_newton = solve_newton(second_equation, second_derivative, 0.0, 0.85, epsilon);

    double res3_dichotomy = solve_dichotomy(third_equation, 1.0, 2.0, epsilon);
    double res3_iterations = solve_iterations(third_iteration, 1.0, 2.0, epsilon);
    double res3_newton = solve_newton(third_equation, third_derivative, 1.0, 2.0, epsilon);

    printf("%.15f %.15f %.15f\n",res1_dichotomy,res1_iterations, res1_newton);
    printf("%.15f %.15f %.15f\n",res2_dichotomy,res2_iterations, res2_newton);
    printf("%.15f %.15f %.15f\n",res3_dichotomy,res3_iterations, res3_newton);
    return 0;
}
