#include <stdio.h>

int main() {
  float r;
  float h;

  printf("Enter radius... ");
  scanf("%f", &r);
  printf("Enter height... ");
  scanf("%f", &h);

  printf("Volume = %.2f", 3.14*r*r*h);

  return 0;
}
