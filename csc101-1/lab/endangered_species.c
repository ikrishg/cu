#include <stdio.h>

int main()
{
  int choice, population, zone, action;

  do
  {
    printf("\n===== ENDANGERED SPECIES STATUS CHECKER =====\n");
    printf("1. Check Conservation Status\n");
    printf("2. Protected Area Management\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {

    case 1:
      printf("\nEnter species population: ");
      scanf("%d", &population);

      if (population <= 0)
        printf("Invalid population entered.\n");

      if (population < 100)
        printf("Species requires immediate monitoring.\n");
      else
        printf("Species population is relatively stable.\n");

      if (population < 50)
        printf("Conservation Status: Critically Endangered\n");
      else if (population < 200)
        printf("Conservation Status: Endangered\n");
      else if (population < 500)
        printf("Conservation Status: Vulnerable\n");
      else
        printf("Conservation Status: Stable\n");

      break;

    case 2:
      printf("\nProtected Area Zones\n");
      printf("1. Core Zone\n");
      printf("2. Buffer Zone\n");
      printf("Enter zone: ");
      scanf("%d", &zone);

      switch (zone)
      {

      case 1:
        printf("\n1. Ban Entry\n");
        printf("2. Allow Research Access\n");
        printf("Choose action: ");
        scanf("%d", &action);

        switch (action)
        {
        case 1:
          printf("Entry prohibited in Core Zone.\n");
          break;
        case 2:
          printf("Research access granted.\n");
          break;
        default:
          printf("Invalid action.\n");
        }
        break;

      case 2:
        printf("\n1. Permit Eco-tourism\n");
        printf("2. Restrict Activities\n");
        printf("Choose action: ");
        scanf("%d", &action);

        switch (action)
        {
        case 1:
          printf("Eco-tourism permitted.\n");
          break;
        case 2:
          printf("Activities restricted in Buffer Zone.\n");
          break;
        default:
          printf("Invalid action.\n");
        }
        break;

      default:
        printf("Invalid zone.\n");
      }
      break;

    case 3:
      printf("Exiting program...\n");
      break;

    default:
      printf("Invalid choice.\n");
    }

  } while (choice != 3);

  return 0;
}
