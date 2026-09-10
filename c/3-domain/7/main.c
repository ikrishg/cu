#include <stdio.h>

/* Global variable */
int totalSpecies;

/* Function to calculate total population */
int calculateTotal(int population[], int n) {
  int total = 0; // Local variable

  for (int i = 0; i < n; i++) {
    total += population[i];
  }

  return total;
}

/* Function to calculate average population */
float calculateAverage(int total, int n) {
  float average; // Local variable

  average = (float)total / n;

  return average;
}

/* Function to find maximum population */
int findMaximum(int population[], int n) {
  int maximum = population[0]; // Local variable

  for (int i = 1; i < n; i++) {
    if (population[i] > maximum)
      maximum = population[i];
  }

  return maximum;
}

int main() {
  int population[10];
  int n;
  int total, maximum;
  float average;

  printf("===== WILDLIFE CENSUS DATA MANAGEMENT =====\n");

  /* Input */
  do {
    printf("\nEnter number of species (1-10): ");
    scanf("%d", &n);

    if (n < 1 || n > 10)
      printf("Invalid input. Enter a value between 1 and 10.\n");

  } while (n < 1 || n > 10);

  totalSpecies = n;

  printf("\nEnter population of each species:\n");

  for (int i = 0; i < n; i++) {
    printf("Species %d: ", i + 1);
    scanf("%d", &population[i]);
  }

  /* Passing values to user-defined functions */
  total = calculateTotal(population, n);
  average = calculateAverage(total, n);
  maximum = findMaximum(population, n);

  /* Final results displayed from main() */
  printf("\n----- WILDLIFE CENSUS ANALYSIS -----\n");
  printf("Number of Species : %d\n", totalSpecies);
  printf("Total Population  : %d\n", total);
  printf("Average Population: %.2f\n", average);
  printf("Maximum Population: %d\n", maximum);

  return 0;
}
