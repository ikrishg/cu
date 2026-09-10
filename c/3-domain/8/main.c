#include <stdio.h>

/* Recursive function to calculate total population */
int calculateTotal(int *population, int n) {
  if (n == 0)
    return 0;

  return *population + calculateTotal(population + 1, n - 1);
}

/* Function to find maximum using pointers */
int findMaximum(int *population, int n) {
  int max = *population;
  int i;

  for (i = 1; i < n; i++) {
    if (*(population + i) > max)
      max = *(population + i);
  }

  return max;
}

/* Function to display data using pointer expressions */
void displayPopulation(int *population, int n) {
  int i;

  printf("\n----- Wildlife Census Records -----\n");

  for (i = 0; i < n; i++) {
    printf("Species %d : %d animals\n", i + 1, *(population + i));
  }
}

int main() {
  int population[10];
  int n, i;
  int total, maximum;
  float average;

  printf("===== WILDLIFE CENSUS DATA MANAGEMENT =====\n");

  /* Input validation */
  do {
    printf("\nEnter number of species (1-10): ");
    scanf("%d", &n);

    if (n < 1 || n > 10)
      printf("Invalid input. Enter a value between 1 and 10.\n");

  } while (n < 1 || n > 10);

  printf("\nEnter population of each species:\n");

  for (i = 0; i < n; i++) {
    printf("Species %d: ", i + 1);
    scanf("%d", &population[i]);
  }

  /* Display using pointers */
  displayPopulation(population, n);

  /* Recursive calculation */
  total = calculateTotal(population, n);

  /* Pointer-based maximum */
  maximum = findMaximum(population, n);

  average = (float)total / n;

  printf("\n----- Census Analysis -----\n");
  printf("Total Population   : %d\n", total);
  printf("Average Population : %.2f\n", average);
  printf("Maximum Population : %d\n", maximum);

  return 0;
}
