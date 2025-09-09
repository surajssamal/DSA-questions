#include <stdio.h>

int main(void) {
  int k = 112;
  int *some = &k;
  printf("%p and the add %p and the value of some and k is %d,%d\n", some,
         &some, k, *some);

  return 0;
}
