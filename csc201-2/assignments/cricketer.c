#include <stdio.h>
#include <string.h>

struct cricketer {
  char name[40];
  char team[40];
  float batting_average;
};

void read_cricketers(struct cricketer *c, int n) {
  int i;

  for (i = 0; i < n; i++) {
    printf("\nCricketer %d\n", i + 1);
    printf("Enter player name: ");
    scanf(" %[^\n]", c[i].name);
    printf("Enter team name: ");
    scanf(" %[^\n]", c[i].team);
    printf("Enter batting average: ");
    scanf("%f", &c[i].batting_average);
  }
}

void display_cricketers(struct cricketer *c, int n) {
  int i;

  printf("\n--- Cricketer Details ---\n");
  for (i = 0; i < n; i++) {
    printf("Player=%s\n", c[i].name);
    printf("Team=%s\n", c[i].team);
    printf("Average=%.2f\n\n", c[i].batting_average);
  }
}

void search_cricketer(struct cricketer *c, int n, char *name) {
  int i, found = 0;

  for (i = 0; i < n; i++) {
    if (strcmp(c[i].name, name) == 0) {
      printf("Player=%s Team=%s Average=%.2f\n", c[i].name, c[i].team,
             c[i].batting_average);
      found = 1;
    }
  }

  if (found == 0)
    printf("Cricketer not found\n");
}

int main() {
  struct cricketer c[50];
  int n;
  char key[40];

  printf("===== CRICKETER DETAILS =====\n");
  printf("Enter number of cricketers: ");
  scanf("%d", &n);

  read_cricketers(c, n);
  display_cricketers(c, n);

  printf("Enter player name to search: ");
  scanf(" %[^\n]", key);
  search_cricketer(c, n, key);

  return 0;
}
