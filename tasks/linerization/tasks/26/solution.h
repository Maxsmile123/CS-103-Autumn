#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int a[10][10];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    while (top <= bottom && left <= right) {
        for (int j = right; j >= left; j--) {
            printf("%d ", a[bottom][j]);
        }
        bottom--;
        if (top <= bottom) {
            for (int i = bottom; i >= top; i--) {
                printf("%d ", a[i][left]);
            }
            left++;
        }
        if (left <= right) {
            for (int j = left; j <= right; j++) {
                printf("%d ", a[top][j]);
            }
            top++;
        }
        if (top <= bottom) {
            for (int i = top; i <= bottom; i++) {
                printf("%d ", a[i][right]);
            }
            right--;
        }
    }
    printf("\n");
    return 0;
}
