#include <math.h>
#include <stdio.h>
#include <windows.h>

#define MAXITER 100

int main(void) {
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);
  long double eps = 1;
  long double k = 1000000000;
  float a = 0.0;
  float b = 0.5;
  float n = 10;
  int risek = 1;
  long double m = 10000000000;
  while (eps / 2 + 1 < eps + 1) {
    eps /= 2;
  }
  long double acc = eps * k;
  printf("x       | сумма рядов  | значение функции| итерации\n");
  for (int i = n + 1;i > 0;i--) {
    double res = 2 * (cos(a) * cos(a) - 1);
    int cur = 1;
    int iter = 1;
    double slag = -(2 * a * a);
    double summa = slag;
    while (fabsl(summa-res)>acc && iter<MAXITER) {
      ++cur;
      ++iter;
      slag *=  ((-4 * a * a) / (2 * cur * ((2 * cur) - 1)));
      summa += slag;
    }
    printf("%f| % .6Le| % .6Le   | %d\n",a, summa, res, iter);
    a += (b / n);
  }
}
