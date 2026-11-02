#include <stdio.h>

int main() {
  float l;
  float b;

  printf("Enter length... ");
  scanf("%f", &l);
  printf("Enter breadth... ");
  scanf("%f", &b);

  printf("Perimeter = %.2f", 2 * (l+b));

  return 0;
}
