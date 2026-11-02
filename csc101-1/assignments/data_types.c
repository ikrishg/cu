#include <stdio.h>

int main() {
  char initial;
  short int age;
  char gender;
  int year;
  long int salary;
  long long int loan;
  float withdraw;
  double balance;
  long double deposit;
  char eligible;

  printf("Enter your initial: ");
  scanf(" %c", &initial);
  printf("Enter your age: ");
  scanf("%hd", &age);
  printf("Enter birth year: ");
  scanf("%d", &year);
  printf("Enter gender: ");
  scanf(" %c", &gender);
  printf("Enter salary: ");
  scanf("%ld", &salary);
  printf("Enter loan amount: ");
  scanf("%lld", &loan);
  printf("Enter withdraw amount: ");
  scanf("%f", &withdraw);
  printf("Enter account balance: ");
  scanf("%lf", &balance);
  printf("Enter deposit amount: ");
  scanf("%Lf", &deposit);
  printf("Are you eligible? (Y/N): ");
  scanf(" %c", &eligible);

  printf("\n--- User Information ---\n");
  printf("Initial: %c\n", initial);
  printf("Age: %hd\n", age);
  printf("Birth Year: %d\n", year);
  printf("Gender: %c\n", gender);
  printf("Salary: %ld\n", salary);
  printf("Loan Amount: %lld\n", loan);
  printf("Withdraw Amount: %.2f\n", withdraw);
  printf("Account Balance: %.2lf\n", balance);
  printf("Deposit Amount: %.2Lf\n", deposit);
  printf("Eligible: %c\n", eligible);
  return 0;
}
