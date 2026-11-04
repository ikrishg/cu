#include <stdio.h>
#include <string.h>

struct book {
  int id;
  char name[40];
  char author[40];
  float price;
};

void read(struct book *b, int n) {
  int i;

  for (i = 0; i < n; i++) {
    printf("\nBook %d\n", i + 1);
    printf("Enter book id: ");
    scanf("%d", &b[i].id);
    printf("Enter book name: ");
    scanf(" %[^\n]", b[i].name);
    printf("Enter author: ");
    scanf(" %[^\n]", b[i].author);
    printf("Enter price: ");
    scanf("%f", &b[i].price);
  }
}

void display(struct book *b, int n) {
  int i;

  printf("\n--- Book Details ---\n");
  for (i = 0; i < n; i++) {
    printf("ID=%d\n", b[i].id);
    printf("Name=%s\n", b[i].name);
    printf("Author=%s\n", b[i].author);
    printf("Price=%.2f\n\n", b[i].price);
  }
}

void maximum(struct book *b, int n) {
  int i, max_index = 0;

  for (i = 1; i < n; i++) {
    if (b[i].price > b[max_index].price)
      max_index = i;
  }

  printf("ID=%d Name=%s Author=%s Price=%.2f\n", b[max_index].id,
         b[max_index].name, b[max_index].author, b[max_index].price);
}

int count(struct book *b, int n, char *author) {
  int i, total = 0;

  for (i = 0; i < n; i++) {
    if (strcmp(b[i].author, author) == 0)
      total++;
  }

  return total;
}

int main() {
  struct book b[5];
  int ch, total;
  char author[40];

  printf("===== BOOK MANAGEMENT STORE =====\n");
  read(b, 5);

  do {
    printf("\n1.Display\n2.Maximum price\n3.Count by author\n4.Exit\n");
    printf("Enter choice: ");
    scanf("%d", &ch);

    if (ch == 1) {
      display(b, 5);
    } else if (ch == 2) {
      maximum(b, 5);
    } else if (ch == 3) {
      printf("Enter author: ");
      scanf(" %[^\n]", author);
      total = count(b, 5, author);
      printf("Books by author=%d\n", total);
    }
  } while (ch != 4);

  return 0;
}
