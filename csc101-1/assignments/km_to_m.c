#include <stdio.h>

int main() {
  float km;

  printf("Enter km distance... ");
  scanf("%f", &km);

  printf("Meters = %f", km * 1000);

  return 0;
}
