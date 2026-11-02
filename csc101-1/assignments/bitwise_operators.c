#include <stdio.h>

int main() {
  int a=12, b=25;

  printf("Bitwise AND = %d\n", a & b);
  printf("Bitwise OR = %d\n", a | b);
  printf("Bitwise XOR = %d\n", a ^ b);
  printf("Bitwise Complement = %d\n", ~a);
  printf("Bitwise Shift Left = %d\n", a << 1);
  printf("Bitwise Shift Right = %d\n", a >> 1);
  return 0;
}
