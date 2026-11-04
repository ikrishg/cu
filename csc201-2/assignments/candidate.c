#include <stdio.h>

struct candidate {
  char name[40];
  char party[40];
  int constituency;
  int votes;
};

void read_candidates(struct candidate *c, int n) {
  int i;

  for (i = 0; i < n; i++) {
    printf("\nCandidate %d\n", i + 1);
    printf("Enter name: ");
    scanf(" %[^\n]", c[i].name);
    printf("Enter party: ");
    scanf(" %[^\n]", c[i].party);
    printf("Enter constituency number: ");
    scanf("%d", &c[i].constituency);
    printf("Enter votes: ");
    scanf("%d", &c[i].votes);
  }
}

void display_candidates(struct candidate *c, int n) {
  int i;

  printf("\n--- Candidate Details ---\n");
  for (i = 0; i < n; i++) {
    printf("Name=%s\n", c[i].name);
    printf("Party=%s\n", c[i].party);
    printf("Constituency=%d\n", c[i].constituency);
    printf("Votes=%d\n\n", c[i].votes);
  }
}

void display_by_constituency(struct candidate *c, int n, int constituency) {
  int i, found = 0;

  for (i = 0; i < n; i++) {
    if (c[i].constituency == constituency) {
      printf("Name=%s Party=%s Constituency=%d Votes=%d\n", c[i].name,
             c[i].party, c[i].constituency, c[i].votes);
      found = 1;
    }
  }

  if (found == 0)
    printf("No candidate found for constituency %d\n", constituency);
}

int main() {
  struct candidate c[50];
  int n, constituency;

  printf("===== CANDIDATE DETAILS =====\n");
  printf("Enter number of candidates: ");
  scanf("%d", &n);

  read_candidates(c, n);
  display_candidates(c, n);

  printf("Enter constituency number: ");
  scanf("%d", &constituency);
  display_by_constituency(c, n, constituency);

  return 0;
}
