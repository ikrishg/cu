#include <stdio.h>

void read_matrix(int *m, int n) {
  int i, j;

  printf("\nEnter %d x %d matrix:\n", n, n);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("m[%d][%d]: ", i, j);
      scanf("%d", m + i * n + j);
    }
  }
}

void display_matrix(int *m, int n) {
  int i, j;

  printf("\n----- Matrix -----\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
      printf("%d ", *(m + i * n + j));
    printf("\n");
  }
}

void row_totals(int *m, int n) {
  int i, j, total;

  printf("\n----- Row Totals -----\n");
  for (i = 0; i < n; i++) {
    total = 0;
    for (j = 0; j < n; j++)
      total = total + *(m + i * n + j);
    printf("Row %d total=%d\n", i, total);
  }
}

int is_identity(int *m, int n) {
  int i, j;

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i == j) {
        if (*(m + i * n + j) != 1)
          return 0;
      } else {
        if (*(m + i * n + j) != 0)
          return 0;
      }
    }
  }

  return 1;
}

int main() {
  int m[10 * 10];
  int n, ch;

  printf("===== 2D INTEGER ARRAY =====\n");
  printf("Enter n for n x n matrix: ");
  scanf("%d", &n);

  read_matrix(m, n);

  do {
    printf("\n1.Display\n2.Row totals\n3.Identity check\n4.Exit\n");
    printf("Enter choice: ");
    scanf("%d", &ch);

    if (ch == 1) {
      display_matrix(m, n);
    } else if (ch == 2) {
      row_totals(m, n);
    } else if (ch == 3) {
      if (is_identity(m, n))
        printf("Identity matrix\n");
      else
        printf("Not an identity matrix\n");
    }
  } while (ch != 4);

  return 0;
}
