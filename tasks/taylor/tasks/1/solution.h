#include <stdio.h>
#include <math.h>

double taylor( double x, int n ) {
    return pow(-1, n)*(pow(x, 2*n+1)/pow(9, n+1));
}

double f( double x) {
    return x/(9 + x*x);
}

double find_epsilon(double x) {
    double e = x;
    while ((x + e) != x) {
        e /= 2;
    }
    return e;
}

void print_table(double a, double x, double sum, double f, int n) {
    if (a==x) { 
        for (int i = 0; i<37; ++i) printf("-");
        puts("");
        printf("| %-6s | %-8s | %-8s | %-2s |\n", "x", "taylor", "function", "n");
        for (int i = 0; i<37; ++i) printf("-");
        puts("");
    }
    printf("| %-6.2lf | %-8.4lf | %-8.4lf | %-2d |\n", x, sum, f, n);
    for (int i = 0; i<37; ++i) printf("-");
    puts("");
}

int main() {
    double a = -1, b = 1, k = 100;
    double x = a-0.05;
    double e = find_epsilon(1.0);
    double temp;
    double sum;
    int n = 0;

    do {
        x+=0.05;
        sum = 0;
        n = 0;
        temp = x;
        sum = 0;
        while ( fabs(temp) > e*k && n < 100 ) {
            temp = taylor(x, n);
            sum += temp;
            n++;
        }
        print_table(a, x, sum, f(x), n);
    } while (x < b);
}