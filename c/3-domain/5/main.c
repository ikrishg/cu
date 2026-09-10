#include <stdio.h>

int main() {
  int population[3][4] = {
      {120, 150, 100, 130}, {80, 95, 70, 85}, {200, 180, 220, 190}};

  float habitatArea[4] = {45.5, 52.0, 48.5, 60.0};
  char zoneCode[4] = {'A', 'B', 'C', 'D'};

  int i, j;
  int totalSpecies, totalZone, overallTotal = 0;

  printf("===============================================\n");
  printf("       WILDLIFE CENSUS DATA MANAGEMENT\n");
  printf("===============================================\n");

  do {
    printf("\nEnter the number of species to analyze (1-3): ");
    scanf("%d", &i);

    if (i < 1 || i > 3)
      printf("Invalid input. Enter a value between 1 and 3.\n");

  } while (i < 1 || i > 3);

  printf("\n----- Wildlife Population Data -----\n");

  printf("%-12s", "Species");

  for (j = 0; j < 4; j++) {
    printf("%-10c", zoneCode[j]);
  }

  printf("\n");

  for (int x = 0; x < i; x++) {
    printf("Species %-4d", x + 1);

    for (j = 0; j < 4; j++) {
      printf("%-10d", population[x][j]);
    }

    printf("\n");
  }

  printf("\n----- Species-wise Population -----\n");

  for (int x = 0; x < i; x++) {
    totalSpecies = 0;

    for (j = 0; j < 4; j++) {
      totalSpecies += population[x][j];
    }

    printf("Species %d Total Population : %d\n", x + 1, totalSpecies);

    overallTotal += totalSpecies;
  }

  printf("\n----- Zone-wise Population -----\n");

  for (j = 0; j < 4; j++) {
    totalZone = 0;

    for (int x = 0; x < i; x++) {
      totalZone += population[x][j];
    }

    printf("Zone %c | Habitat Area: %.2f sq.km | Population: %d\n", zoneCode[j],
           habitatArea[j], totalZone);
  }

  printf("\n===============================================\n");
  printf("Overall Wildlife Population : %d\n", overallTotal);
  printf("===============================================\n");

  return 0;
}
