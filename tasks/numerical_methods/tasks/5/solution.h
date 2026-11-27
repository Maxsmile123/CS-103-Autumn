#include <float.h>
#include <math.h>
#include <stdio.h>
#include <windows.h>

double func5(double n) {
  return sqrt(1 - n) - tan(n);
}

double func5x(double n) {
  return atan(sqrt(1 - n));
}

double derfunc5(double n) {
  return -1 / (2 * sqrt(1 - n)) - 1 / (cos(n) * cos(n));
}

double func6(double n) {
  return n + cos(pow(n, 0.52) + 2);
}
double func6x(double n) {
  return -cos(pow(n, 0.52) + 2);
}
double derfunc6(double n) {
  return 1 - sin(pow(n, 0.52) + 2) * 0.52 * pow(n, -0.48);
}

double func7(double n) {
  return 3 * log(n) * log(n) + 6 * log(n) - 5;
}

double func7x(double n) {
  return exp((5 - 3*log(n)*log(n))/6);
}

double derfunc7(double n) {
  return 6 / n + 6 * log(n) / n;
}

double dichotomy(double (*fun)(double), double a, double b, double x) {
  int cycle = 0;
  while (fabsl(a - b) > FLT_EPSILON) {
    if ((fun(a) * fun((a+b)/2))<0) {
      b = (a + b) / 2;
    }
    else {
      a = (a + b) / 2;
    }
    ++cycle;
  }
  printf("Дихотомии|%f   |%f   |%f|%d\n", (a+b)/2, x,fabsl((a+b)/2-x), cycle);

}
double iter(double (*fun)(double), double a, double b, double x) {
  double x0 = (a + b) / 2;
  double x1 = fun(x0);
  int cycle = 1;
  while (fabsl(x1 - x0) > FLT_EPSILON) {
    x0 = x1;
    x1 = fun(x0);
    ++cycle;
  }
  printf("Итераций |%f   |%f   |%f|%d\n", fun(x1), x,fabsl(x-fun(x1)), cycle);
}
double newton(double (*fun)(double), double (*defun)(double), double a, double b, double x) {
  double x0 = (a + b) / 2;
  double x1 = x0 - (fun(x0) / defun(x0));
  int cycle = 1;
  while (fabsl(x1 - x0) > FLT_EPSILON) {
    x0 = x1;
    x1= x0 - (fun(x0) / defun(x0));
    ++cycle;
  }
  printf("Ньютона  |%f   |%f   |%f|%d\n", x1 - (fun(x1) / defun(x1)), x, fabsl(x1 - (fun(x1) / defun(x1))-x), cycle);
}
int main(void) {
  float first = 0.5768;
  float second = 0.9892;
  float third = 1.8832;
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);
  printf("Уравнение            |Метод    |Примерный x|Табличный х|Точность|Итерации\n");
  printf("√1-x-tg(x)=0         |");
  dichotomy(func5, 0, 1, first);
  printf("√1-x-tg(x)=0         |");
  iter(func5x, 0, 1, first);
  printf("√1-x-tg(x)=0         |");
  newton(func5, derfunc5, 0, 1, first);
  printf("x+cos(x^(0.52)+2)=0  |");
  dichotomy(func6, 0.5, 1, second);
  printf("x+cos(x^(0.52)+2)=0  |");
  iter(func6x, 0.5, 1, second);
  printf("x+cos(x^(0.52)+2)=0  |");
  newton(func6, derfunc6, 0.5, 1, second);
  printf("3*ln(x)^2+6*ln(x)-5=0|");
  dichotomy(func7, 1, 3, third);
  printf("3*ln(x)^2+6*ln(x)-5=0|");
  iter(func7x, 1, 3, third);
  printf("3*ln(x)^2+6*ln(x)-5=0|");
  newton(func7, derfunc7, 1, 3, third);
}
