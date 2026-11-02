#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
  char species[5][50];
  char copiedSpecies[50];
  char combinedInfo[100];
  char searchWord[30];
  int choice, i, record;
  int result;

  printf("===== WILDLIFE CENSUS DATA MANAGEMENT SYSTEM =====\n");

  printf("\nEnter names of 5 wildlife species:\n");

  for (i = 0; i < 5; i++) {
    printf("Species %d: ", i + 1);
    scanf(" %49[^\n]", species[i]);
  }

  do {
    printf("\n===== MENU =====\n");
    printf("1. Display Wildlife Records\n");
    printf("2. Find Length of Species Name\n");
    printf("3. Copy a Species Name\n");
    printf("4. Concatenate Species Information\n");
    printf("5. Compare Two Species Names\n");
    printf("6. Search for a Species / Keyword\n");
    printf("7. Convert Species Name to Uppercase\n");
    printf("8. Convert Species Name to Lowercase\n");
    printf("9. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {

    case 1:
      printf("\n----- WILDLIFE RECORDS -----\n");

      for (i = 0; i < 5; i++) {
        printf("Record %d : %s\n", i + 1, species[i]);
      }
      break;

    case 2:
      printf("\nEnter record number (1-5): ");
      scanf("%d", &record);

      if (record >= 1 && record <= 5) {
        printf("Species Name : %s\n", species[record - 1]);
        printf("Length       : %lu characters\n", strlen(species[record - 1]));
      } else {
        printf("Invalid record number.\n");
      }
      break;

    case 3:
      printf("\nEnter record number to copy (1-5): ");
      scanf("%d", &record);

      if (record >= 1 && record <= 5) {
        strcpy(copiedSpecies, species[record - 1]);

        printf("Original : %s\n", species[record - 1]);
        printf("Copied   : %s\n", copiedSpecies);
      } else {
        printf("Invalid record number.\n");
      }
      break;

    case 4:
      printf("\nEnter record number (1-5): ");
      scanf("%d", &record);

      if (record >= 1 && record <= 5) {
        strcpy(combinedInfo, "Species: ");
        strcat(combinedInfo, species[record - 1]);
        strcat(combinedInfo, " | Conservation Record");

        printf("Combined Information:\n%s\n", combinedInfo);
      } else {
        printf("Invalid record number.\n");
      }
      break;

    case 5:
      printf("\nEnter first record number (1-5): ");
      scanf("%d", &record);

      if (record >= 1 && record <= 5) {
        int record2;

        printf("Enter second record number (1-5): ");
        scanf("%d", &record2);

        if (record2 >= 1 && record2 <= 5) {
          result = strcmp(species[record - 1], species[record2 - 1]);

          if (result == 0)
            printf("The species names are equal.\n");
          else
            printf("The species names are different.\n");
        } else {
          printf("Invalid second record number.\n");
        }
      } else {
        printf("Invalid first record number.\n");
      }
      break;

    case 6:
      printf("\nEnter keyword to search: ");
      scanf(" %29[^\n]", searchWord);

      printf("\nSearch Results:\n");

      for (i = 0; i < 5; i++) {
        if (strstr(species[i], searchWord) != NULL) {
          printf("Found in Record %d: %s\n", i + 1, species[i]);
        }
      }
      break;

    case 7:
      printf("\nEnter record number (1-5): ");
      scanf("%d", &record);

      if (record >= 1 && record <= 5) {
        for (i = 0; species[record - 1][i] != '\0'; i++) {
          species[record - 1][i] = toupper(species[record - 1][i]);
        }

        printf("Uppercase Name: %s\n", species[record - 1]);
      } else {
        printf("Invalid record number.\n");
      }
      break;

    case 8:
      printf("\nEnter record number (1-5): ");
      scanf("%d", &record);

      if (record >= 1 && record <= 5) {
        for (i = 0; species[record - 1][i] != '\0'; i++) {
          species[record - 1][i] = tolower(species[record - 1][i]);
        }

        printf("Lowercase Name: %s\n", species[record - 1]);
      } else {
        printf("Invalid record number.\n");
      }
      break;

    case 9:
      printf("\nExiting Wildlife Census System...\n");
      break;

    default:
      printf("\nInvalid choice.\n");
    }

  } while (choice != 9);

  return 0;
}
