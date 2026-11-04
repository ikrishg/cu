#include <stdio.h>

struct student {
  int roll;
  char name[40];
  char class_name[20];
  float marks[3];
};

void read_students(struct student *s, int n) {
  int i, j;

  for (i = 0; i < n; i++) {
    printf("\nStudent %d\n", i + 1);
    printf("Enter roll number: ");
    scanf("%d", &s[i].roll);
    printf("Enter name: ");
    scanf(" %[^\n]", s[i].name);
    printf("Enter class: ");
    scanf(" %[^\n]", s[i].class_name);
    for (j = 0; j < 3; j++) {
      printf("Enter marks for subject %d: ", j + 1);
      scanf("%f", &s[i].marks[j]);
    }
  }
}

void display_students(struct student *s, int n) {
  int i;

  printf("\n--- Student Details ---\n");
  for (i = 0; i < n; i++) {
    printf("Roll=%d\n", s[i].roll);
    printf("Name=%s\n", s[i].name);
    printf("Class=%s\n", s[i].class_name);
    printf("Marks=%.2f %.2f %.2f\n\n", s[i].marks[0], s[i].marks[1],
           s[i].marks[2]);
  }
}

int search_student(struct student *s, int n, int roll) {
  int i;

  for (i = 0; i < n; i++) {
    if (s[i].roll == roll)
      return i;
  }

  return -1;
}

void modify_student(struct student *s, int n, int roll) {
  int i, j;

  i = search_student(s, n, roll);
  if (i == -1) {
    printf("Not found\n");
    return;
  }

  printf("Enter new name: ");
  scanf(" %[^\n]", s[i].name);
  printf("Enter new class: ");
  scanf(" %[^\n]", s[i].class_name);
  for (j = 0; j < 3; j++) {
    printf("Enter new marks for subject %d: ", j + 1);
    scanf("%f", &s[i].marks[j]);
  }
  printf("Record updated\n");
}

int main() {
  struct student s[50];
  int n, ch, roll, index;

  printf("===== STUDENT DATABASE =====\n");
  printf("Enter number of students: ");
  scanf("%d", &n);

  read_students(s, n);

  do {
    printf("\n1.Display\n2.Search\n3.Modify\n4.Exit\n");
    printf("Enter choice: ");
    scanf("%d", &ch);

    if (ch == 1) {
      display_students(s, n);
    } else if (ch == 2) {
      printf("Enter roll number: ");
      scanf("%d", &roll);
      index = search_student(s, n, roll);
      if (index == -1) {
        printf("Not found\n");
      } else {
        printf("Roll=%d Name=%s Class=%s Marks=%.2f %.2f %.2f\n", s[index].roll,
               s[index].name, s[index].class_name, s[index].marks[0],
               s[index].marks[1], s[index].marks[2]);
      }
    } else if (ch == 3) {
      printf("Enter roll number: ");
      scanf("%d", &roll);
      modify_student(s, n, roll);
    }
  } while (ch != 4);

  return 0;
}
