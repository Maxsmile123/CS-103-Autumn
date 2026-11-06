#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n<1 || n>7) {
        printf("Incorrect size\n");
        return 1;
    }
    int a[n][n];
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            if (scanf("%d",&a[i][j]) !=1) {
                printf("Incorrect input\n");
                return 1;
            }
        }
    }
    for (int k = -1; k<(n*2-1);k++) {
        if (k==-1) {
            for (int i = 0; i<n; i++) {
                printf("%d ", a[i][i]);
            }
        } else if (k%4==0) {
            for (int i = (n-(k/2)-2); i>-1; i--) {
                printf("%d ", a[i][i+k/2+1]);
            }
        } else if (k%4==1) {
            for (int i = (n-(k/2)-2); i>-1; i--) {
                printf("%d ", a[i+k/2+1][i]);
            }
        } else if (k%4==2) {
            for (int i = k/2+1; i<n; i++) {
                printf("%d ", a[i][i-k/2-1]);
            }
        } else if (k%4==3) {
            for (int i = k/2+1; i<n; i++) {
                printf("%d ", a[i-k/2-1][i]);
            }
        }
    }
    return 0;
}
