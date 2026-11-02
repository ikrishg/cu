#include <stdio.h>
#include <string.h>

struct stud_det {
  char name[10];
  int age;
} s1;

int main() {
  strcpy(s1.name, "Krish");
  s1.age = 17;

  printf("%s is %d years old\n", s1.name, s1.age);

  return 0;
}
