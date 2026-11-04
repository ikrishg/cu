#include <stdio.h>

struct passenger {
  int no;
  char name[25];
  float ticket_price;
};

void read_passengers(struct passenger *p, int n) {
  int i;

  for (i = 0; i < n; i++) {
    printf("\nPassenger %d\n", i + 1);
    printf("Enter passenger number: ");
    scanf("%d", &p[i].no);
    printf("Enter passenger name: ");
    scanf(" %[^\n]", p[i].name);
    printf("Enter ticket price: ");
    scanf("%f", &p[i].ticket_price);
  }
}

void display_passengers(struct passenger *p, int n) {
  int i;

  printf("\n--- Passenger Details ---\n");
  for (i = 0; i < n; i++) {
    printf("No=%d\n", p[i].no);
    printf("Name=%s\n", p[i].name);
    printf("Price=%.2f\n\n", p[i].ticket_price);
  }
}

void search_passenger(struct passenger *p, int n, int no) {
  int i, found = 0;

  for (i = 0; i < n; i++) {
    if (p[i].no == no) {
      found = 1;
      break;
    }
  }

  if (found == 1)
    printf("Passenger found\n");
  else
    printf("Passenger Not found\n");
}

void modify_price(struct passenger *p, int n) {
  int i;

  for (i = 0; i < n; i++) {
    if (p[i].ticket_price >= 250 && p[i].ticket_price <= 299)
      p[i].ticket_price = 300;
  }
}

int main() {
  struct passenger p[5];
  int ch, no;

  printf("===== RAILWAY RESERVATION =====\n");
  read_passengers(p, 5);

  do {
    printf("\n1.Display\n2.Search\n3.Modify price\n4.Exit\n");
    printf("Enter choice: ");
    scanf("%d", &ch);

    if (ch == 1) {
      display_passengers(p, 5);
    } else if (ch == 2) {
      printf("Enter passenger number: ");
      scanf("%d", &no);
      search_passenger(p, 5, no);
    } else if (ch == 3) {
      modify_price(p, 5);
      printf("Prices updated\n");
    }
  } while (ch != 4);

  return 0;
}
