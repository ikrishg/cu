#include <stdio.h>

int main() {

  int a;
  const int b;
  double c;

  printf("No. of Bytes is %d\n", sizeof(a));
  printf("No. of Bytes is %d\n", sizeof(c));
  printf("No. of Bytes is %d\n", sizeof(long int));
}
