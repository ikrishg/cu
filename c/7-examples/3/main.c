#include <stdio.h>

int main() {
  int factorial = 1, n;

  printf("enter n: ");
  scanf("%d", &n);

  while (n > 1)
  {
    factorial *= n--;
  }

  printf("%d", factorial);

  return 0;
}
