#include <stdio.h>

int main() {
  printf("Kwish Swiss Bank Account Opening");

  char type;

  printf("\nEnter account type (S for Savings, C for Current): ");
  scanf(" %c", &type);

  char name[50];
  int age;

  switch (type) {
    case 'S':
    case 's':
      printf("Savings account selected.\n");
      break;
    case 'C':
    case 'c':
      printf("Current account selected.\n");
      break;
    default:
      printf("Invalid account type entered.\n");
  }

  printf("Enter your name: ");
  scanf("%s", name);
  printf("Enter your age: ");
  scanf("%d", &age);

  if (age < 18) {
    printf("You must be at least 18 years old to open an account.\n");
  } else {
    printf("Account opening successful for %s, age %d.\n", name, age);
    printf("Account number: %d\n", name[0] * 100000 + age);
  }

  printf("Thank you for choosing Kwish Swiss Bank!\n");

  return 0;
}
