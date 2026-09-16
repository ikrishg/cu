#include <stdio.h>

/* Call by Value */
void modifyByValue(int population) {
  population = population + 50;

  printf("Inside Call by Value   : %d\n", population);
}

/* Call by Reference */
void modifyByReference(int *population) {
  *population = *population + 50;

  printf("Inside Call by Reference: %d\n", *population);
}

int main() {
  int populationValue;
  int populationReference;

  printf("===== WILDLIFE CENSUS DATA MANAGEMENT =====\n");

  printf("\nEnter population for Call by Value: ");
  scanf("%d", &populationValue);

  printf("Before Call by Value    : %d\n", populationValue);

  modifyByValue(populationValue);

  printf("After Call by Value     : %d\n", populationValue);

  printf("\nEnter population for Call by Reference: ");
  scanf("%d", &populationReference);

  printf("Before Call by Reference: %d\n", populationReference);

  modifyByReference(&populationReference);

  printf("After Call by Reference : %d\n", populationReference);

  return 0;
}
