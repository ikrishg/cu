#include <stdio.h>

int main() {
  float a=4, b=2.2;
  float sum, sub, mul, div;

  sum = a + b;
  sub = a - b;
  mul = a * b;
  div = a / b;

  printf("   Arithmetic Operations\n");
  printf("   *********************\n");
  printf("Summation of a and b=%f\nSubstraction of b=%f\n", sum, sub);
  printf("Multiplication of a and b=%f\nDivision of a and b=%f\n", mul, div);

  return 0;
}
