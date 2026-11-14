#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int matr[8][8];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matr[i][j]);
        }
    }
    int maxi = matr[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matr[i][j] > maxi) {
                maxi = matr[i][j];
            }
        }
    }
    int orig_n = n;
    for (int j = 0; j < n; j++) {
        int isin = 0;
        for (int i = 0; i < orig_n; i++) {
            if (matr[i][j] == maxi) {
                isin = 1;
                break;
            }
        }
        if (isin) {
            for (int col = j; col < n - 1; col++) {
                for (int i = 0; i < orig_n; i++) {
                    matr[i][col] = matr[i][col + 1];
                }
            }
            n--;
            j--;
        }
    }
    if (n == 0) {
        printf("все столбцы содержали максимальный элемент матрицы и были удалены.\n");
        return 0;
    }
    for (int i = 0; i < orig_n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
