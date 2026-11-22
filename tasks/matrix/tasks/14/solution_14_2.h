//14_2
#include <stdio.h>
int main() {
    FILE *f = fopen("matrices.txt", "r");
    if (f == NULL) {
        printf("Не удалось открыть файл\n");
        return 1;
    }

    int n;
    while (fscanf(f,"%d", &n) ==1) {
        int a[n][n];
        int v[n][n];
        int min;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j<n; j++) {
                fscanf(f,"%d",&a[i][j]);
                if (i==0 && j==0) {
                    min = a[i][j];
                }
                if (j>=i) {
                    v[i][j] = a[i][j];
                }
                if (i>=j && a[i][j]<min) {
                    min = a[i][j];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j<n; j++) {
                if (j>=i) {
                    printf("%d ",v[i][j]*min);
                } else {
                    printf("%d ",a[i][j]);
                }
            }
            printf("\n");
        }
    }
    fclose(f);
    return 0;

}
