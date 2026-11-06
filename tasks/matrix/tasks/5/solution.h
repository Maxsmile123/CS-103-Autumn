#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main() {
  int height;
  int length;
  int maxelem=-INFINITY;
  scanf("%d", &length);
  scanf("%d", &height);
  int* arr = (int*)malloc(height * length * sizeof(int));
  for (int i = 0;i < height*length;i+=length) {
    for (int j = 0;j < length;j++) {
      scanf("%d", &arr[i + j]);
      maxelem = max(maxelem, arr[i + j]);
    }
  }
  int isfirst = -1;
  int* summax = calloc(length, sizeof(int));
  for (int i = 0;i < height*length;i+=length) {
    int ismaxhere = 0;
    for (int j = 0;j < length;j++) {
      if (arr[i + j] == maxelem) {
        ismaxhere = 1;
        for (int t = 0;t < length;t++) {
          summax[t] += arr[t + i];
        }
        break;
      }
    }
    if (ismaxhere && isfirst==-1) {
      isfirst = i/length;
    }
  }
  for (int i = 0;i < height*length;i+=length) {
    for (int j = 0;j < length;j++) {
      if (i / length == isfirst) {
        printf("%d ", summax[j]);
      }
      else {
        printf("%d ", arr[i + j]);
      }
    }
  }
}

