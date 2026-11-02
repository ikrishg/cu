#include <stdio.h>

int main() {
  int currentPopulation, births, deaths;
  float habitatArea, density;
  char reserveCode;

  printf("Wildlife Census Data Management\n");

  printf("Enter reserve code (single character): ");
  fflush(stdin);
  reserveCode = getchar();

  printf("Enter current wildlife population: ");
  scanf("%d", &currentPopulation);

  printf("Enter number of births: ");
  scanf("%d", &births);

  printf("Enter number of deaths: ");
  scanf("%d", &deaths);

  printf("Enter habitat area (sq. km): ");
  scanf("%f", &habitatArea);

  currentPopulation = currentPopulation + births - deaths;
  density = currentPopulation / habitatArea;

  printf("\nWildlife Census Report\n");
  printf("Reserve Code          : %c\n", reserveCode);
  printf("Updated Population    : %d\n", currentPopulation);
  printf("Population Density    : %.2f animals/sq. km\n", density);

  if (currentPopulation < 100 && density < 5) {
    printf("Conservation Status   : High Priority Conservation Area\n");
  } else {
    printf("Conservation Status   : Stable Monitoring Area\n");
  }

  return 0;
}
