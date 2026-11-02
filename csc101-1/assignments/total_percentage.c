#include <stdio.h>

int main() {
  float one;
  float two;
  float three;
  float four;
  float five;

  printf("Enter marks...\n");
  printf("1... ");
  scanf("%f", &one);
  printf("2... ");
  scanf("%f", &two);
  printf("3... ");
  scanf("%f", &three);
  printf("4... ");
  scanf("%f", &four);
  printf("5... ");
  scanf("%f", &five);

  float total = one + two + three + four + five;
  float percentage = (total / 500) * 100;

  printf("Total marks = %.2f\n", total);
  printf("Percentage = %.2f%%\n", percentage);

  return 0;
}
