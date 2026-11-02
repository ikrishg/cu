#include<stdio.h>
#include<string.h>

union stud_det {
  char name[10];
  int age;
} u1;

int main() {
  strcpy(u1.name, "Krish");
  printf("Your name is %s\n", u1.name);
  u1.age = 17;
  printf("%s your age is %d", u1.name, u1.age);
}
