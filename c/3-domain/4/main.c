#include <stdio.h>

int main() {
  int population[20];
  int n, i;
  int total = 0, max, min;
  float average;
  int search, found = 0;

  printf("===== Wildlife Census Data Management =====\n");

  printf("Enter the number of species: ");
  scanf("%d", &n);

  printf("\nEnter the population of each species:\n");
  for (i = 0; i < n; i++) {
    printf("Species %d: ", i + 1);
    scanf("%d", &population[i]);
  }

  printf("\n----- Stored Population Data -----\n");
  for (i = 0; i < n; i++) {
    printf("Species %d : %d\n", i + 1, population[i]);
  }

  max = population[0];
  min = population[0];

  for (i = 0; i < n; i++) {
    total += population[i];

    if (population[i] > max)
      max = population[i];

    if (population[i] < min)
      min = population[i];
  }

  average = (float)total / n;

  printf("\n----- Census Analysis -----\n");
  printf("Total Population   : %d\n", total);
  printf("Average Population : %.2f\n", average);
  printf("Maximum Population : %d\n", max);
  printf("Minimum Population : %d\n", min);

  printf("\nEnter a population value to search: ");
  scanf("%d", &search);

  for (i = 0; i < n; i++) {
    if (population[i] == search) {
      printf("Population found at Species %d.\n", i + 1);
      found = 1;
      break;
    }
  }

  if (!found)
    printf("Population not found.\n");

  return 0;
}
