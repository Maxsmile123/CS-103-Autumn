#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void main() {
  int height;
  int length;
  scanf("%d", &length);
  scanf("%d", &height);
  int redge = length;
  int ledge = 0;
  int upedge = 0;
  int downedge = height;
  int* arr = (int*)malloc(height*length * sizeof(int));
  for (int i = 0;i < height;i+=length) {
    for (int j = 0;j < length;j++) {
      scanf("%d", &arr[i + j]);
    }
  }
  int cycle = 0;
  while (redge > ledge) {
    for (int i = cycle;i < redge;i++) {
      printf("%d " ,arr[i+cycle+height*cycle-1*cycle]);
    }
    for (int j = cycle+1;j < downedge;j++) {
      printf("%d ", arr[redge-1+length*j]);
    }
    for (int i = 0;i < length-ledge-cycle-1;i++) {
      printf("%d ", arr[length*height-2-1*cycle-height*cycle-i]);
    }
    for (int j = downedge-2;j > cycle;j--) {
      printf("%d ", arr[((redge - 1 + length * j)-height+1+2*cycle)]);
    }
    --redge;
    --downedge;
    ++upedge;
    ++ledge;
    ++cycle;
  }
  printf("\n");
}
