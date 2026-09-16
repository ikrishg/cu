#include <stdio.h>

int main() {
  int choice;
  int totalAnimals = 0;

  do {
    printf("\n===== Wildlife Census Data Management =====\n");
    printf("1. Record Animal Sightings\n");
    printf("2. Display Survey Report\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {

    case 1: {
      int count = 1;
      int sightings;

      printf("\nEnter sightings for 5 survey checkpoints\n");

      while (count <= 5) {
        printf("Checkpoint %d: ", count);
        scanf("%d", &sightings);

        totalAnimals += sightings;
        count++;
      }

      printf("\nSurvey data recorded successfully.\n");
      break;
    }

    case 2: {
      printf("\n----- Wildlife Survey Report -----\n");

      for (int i = 1; i <= 5; i++) {
        printf("Checkpoint %d surveyed.\n", i);
      }

      printf("Total Animals Sighted: %d\n", totalAnimals);
      break;
    }

    case 3:
      printf("\nExiting Wildlife Census System...\n");
      break;

    default:
      printf("\nInvalid choice.\n");
    }

  } while (choice != 3);

  return 0;
}
