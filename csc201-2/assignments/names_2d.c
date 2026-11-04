#include <stdio.h>

void read_names(char names[][40], int n) {
  int i;

  printf("\nEnter %d names:\n", n);
  for (i = 0; i < n; i++) {
    printf("Name %d: ", i + 1);
    scanf(" %[^\n]", *(names + i));
  }
}

void display_names(char names[][40], int n) {
  int i;

  printf("\n----- Names -----\n");
  for (i = 0; i < n; i++)
    printf("%s\n", *(names + i));
}

int name_compare(char *a, char *b) {
  int i = 0;

  while (*(a + i) != '\0' && *(b + i) != '\0') {
    if (*(a + i) != *(b + i))
      return *(a + i) - *(b + i);
    i++;
  }

  return *(a + i) - *(b + i);
}

void copy_name(char *dest, char *src) {
  int i = 0;

  while (*(src + i) != '\0') {
    *(dest + i) = *(src + i);
    i++;
  }
  *(dest + i) = '\0';
}

void bubble_sort(char names[][40], int n) {
  int i, j;
  char temp[40];

  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (name_compare(*(names + j), *(names + j + 1)) > 0) {
        copy_name(temp, *(names + j));
        copy_name(*(names + j), *(names + j + 1));
        copy_name(*(names + j + 1), temp);
      }
    }
  }
}

int main() {
  char names[50][40];
  int n, ch;

  printf("===== 2D CHAR ARRAY =====\n");
  printf("Enter number of names: ");
  scanf("%d", &n);

  read_names(names, n);

  do {
    printf("\n1.Display\n2.Bubble sort\n3.Exit\n");
    printf("Enter choice: ");
    scanf("%d", &ch);

    if (ch == 1) {
      display_names(names, n);
    } else if (ch == 2) {
      bubble_sort(names, n);
      printf("Sorted\n");
      display_names(names, n);
    }
  } while (ch != 3);

  return 0;
}
