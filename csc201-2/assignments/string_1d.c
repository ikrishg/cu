#include <stdio.h>

void read_string(char *s) {
  printf("Enter a string: ");
  scanf(" %[^\n]", s);
}

void display_string(char *s) {
  printf("String=%s\n", s);
}

int string_length(char *s) {
  int len = 0;

  while (*(s + len) != '\0')
    len++;

  return len;
}

void reverse_string(char *s) {
  int i, j;
  char temp;
  int len = string_length(s);

  for (i = 0, j = len - 1; i < j; i++, j--) {
    temp = *(s + i);
    *(s + i) = *(s + j);
    *(s + j) = temp;
  }
}

void copy_string(char *dest, char *src) {
  int i = 0;

  while (*(src + i) != '\0') {
    *(dest + i) = *(src + i);
    i++;
  }
  *(dest + i) = '\0';
}

int count_char(char *s, char ch) {
  int i = 0;
  int count = 0;

  while (*(s + i) != '\0') {
    if (*(s + i) == ch)
      count++;
    i++;
  }

  return count;
}

int main() {
  char s[100];
  char copy[100];
  char ch;
  int choice, len, count;

  printf("===== 1D CHAR ARRAY =====\n");
  read_string(s);

  do {
    printf("\n1.Display\n2.Length\n3.Reverse\n4.Copy\n5.Count character\n6.Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
      display_string(s);
    } else if (choice == 2) {
      len = string_length(s);
      printf("Length=%d\n", len);
    } else if (choice == 3) {
      reverse_string(s);
      printf("Reversed=");
      display_string(s);
    } else if (choice == 4) {
      copy_string(copy, s);
      printf("Copied=%s\n", copy);
    } else if (choice == 5) {
      printf("Enter character: ");
      scanf(" %c", &ch);
      count = count_char(s, ch);
      if (count > 0)
        printf("Present, count=%d\n", count);
      else
        printf("Not present\n");
    }
  } while (choice != 6);

  return 0;
}
