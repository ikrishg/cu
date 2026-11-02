#include<stdio.h>

int main() {
  int a=10,b=12;
  int *ptr1=&a, *ptr2=&b;
  printf("Address of the variable a is %p\n",ptr1);
  printf("Address of the variable b is %p",ptr2);
}
