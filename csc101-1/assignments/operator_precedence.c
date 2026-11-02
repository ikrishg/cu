#include <stdio.h>

int main() {
  float a, b, c, x, y, z;

  a = 9;
  b = 12;
  c = 3;

  x = a - b  / 3 + c * 2 - 1;
  y = a - b  / (3 + c) * (2 - 1);
  z = a - (b / (3 + c) * 2) - 1;


  printf("x=%f, y=%f, z=%f\n", x, y, z);

  return 0;
}
