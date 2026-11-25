#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Примечание: в тестах ошибка. В общем условии даётся a, b, n такие что [a, b] и n промежутков. Вывод ненмого
// Изменил: подстроил под windows и сделал такой формат:
// --------------------------------------
// x: -0.100000
// Вычисленное значение ряда: -0.200671
// Значение функции: -0.200671
// Количество итераций: 2
// --------------------------------------

float func(float x) {
    return log((1 + x) / (1 - x));
}

float abs_float(float a) {
    if (a > 0) return a;
    return (float)-1 * a;
}

float approximately_value(float x, float goal, int *iters) {
    float curr = x;
    float sm = 0;
    float eps = 0.000001;
    for (int i = 0; i <= 100 && abs_float(goal - 2 * sm) > eps; ++i) {
        sm += curr;
        *iters = i;
        curr *= (float) x * x * ((float) 2 * i + 1) / ((float) 2 * i + 3);
    }
    return 2 * sm;
}

int main(int argc, char *argv[]) {
    float a, b, size, batch;
    long long n;
    scanf("%f %f %lld", &a, &b, &n);
    size = b - a;
    batch = size / n;
    float *nums = (float *) malloc(sizeof(float) * (n + 1));
    if (nums == NULL) {
        return -1;
    }
    long long tmp = 0;
    for (long long i = 0; i <= n; ++i) {
        nums[tmp++] = (float) a + (float) batch * i;
    }
    for (long long i = 0; i <= n; ++i) {
        float func_res = func(nums[i]);
        int iters = 0;
        float approx = approximately_value(nums[i], func_res, &iters);
        printf(" x: %f\n Вычисленное значение ряда: %f\n Значение функции: %f\n Количество итераций: %d\n", nums[i], approx, func_res, iters);
        printf("--------------------------------------\n");
    }
    free(nums);
}
