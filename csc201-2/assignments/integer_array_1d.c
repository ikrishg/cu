#include <stdio.h>

void read_numbers(int *a, int n) {
  int i;

  printf("\nEnter %d numbers:\n", n);
  for (i = 0; i < n; i++) {
    printf("a[%d]: ", i);
    scanf("%d", a + i);
  }
}

void display_numbers(int *a, int n) {
  int i;

  printf("\n----- Numbers -----\n");
  for (i = 0; i < n; i++)
    printf("%d ", *(a + i));
  printf("\n");
}

void display_odd_positions(int *a, int n) {
  int i;

  printf("\n----- Odd Positioned Elements -----\n");
  for (i = 0; i < n; i++) {
    if (i % 2 != 0)
      printf("a[%d]=%d\n", i, *(a + i));
  }
}

void display_even_numbers(int *a, int n) {
  int i;

  printf("\n----- Even Numbers -----\n");
  for (i = 0; i < n; i++) {
    if (*(a + i) % 2 == 0)
      printf("%d ", *(a + i));
  }
  printf("\n");
}

int find_maximum(int *a, int n) {
  int i;
  int max = *a;

  for (i = 1; i < n; i++) {
    if (*(a + i) > max)
      max = *(a + i);
  }

  return max;
}

void sum_and_average(int *a, int n) {
  int i;
  int sum = 0;
  float average;

  for (i = 0; i < n; i++)
    sum = sum + *(a + i);

  average = (float)sum / n;
  printf("Sum=%d\n", sum);
  printf("Average=%.2f\n", average);
}

int main() {
  int a[50];
  int n, ch, max;

  printf("===== 1D INTEGER ARRAY =====\n");
  printf("Enter n: ");
  scanf("%d", &n);

  read_numbers(a, n);

  do {
    printf("\n1.Display\n2.Odd positions\n3.Even numbers\n4.Maximum\n5.Sum and average\n6.Exit\n");
    printf("Enter choice: ");
    scanf("%d", &ch);

    if (ch == 1) {
      display_numbers(a, n);
    } else if (ch == 2) {
      display_odd_positions(a, n);
    } else if (ch == 3) {
      display_even_numbers(a, n);
    } else if (ch == 4) {
      max = find_maximum(a, n);
      printf("Maximum=%d\n", max);
    } else if (ch == 5) {
      sum_and_average(a, n);
    }
  } while (ch != 6);

  return 0;
}
