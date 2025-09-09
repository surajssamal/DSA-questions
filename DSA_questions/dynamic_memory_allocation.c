#include <stdio.h>
#include <stdlib.h>

int main() {
  int *ptr;
  ptr = (int *)malloc(4 * sizeof(int));
  for (int i = 0; i < 4; i++) {

    printf("adress %p and %d\n", &ptr[i], ptr[i]);
  }
  printf("talking more heap by reallock");
  // extending the malloc heap by realloc;
  ptr = (int *)realloc(ptr, 3 * sizeof(int));
  for (int i = 0; i < 6; i++) {

    printf("adress %p and %d\n", &ptr[i], ptr[i]);
  }
  free(ptr);
  // int t = 12;
  // int *ptr = &t;
  // printf("%p\n", ptr);
  return 0;
}
