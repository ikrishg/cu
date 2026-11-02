#include <stdio.h>
#include <string.h>

struct location {
    char park[50];
    char zone[30];
};

union taginfo {
    char contact[40];
    int chip;
};

struct animal {
    int id;
    char species[40];
    int count;
    struct location loc;
    int type;
    union taginfo info;
};

int main() {
    struct animal a[20];
    int n, i, ch, found, total;
    char key[40], park[50];

    printf("Enter number of records: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nRecord %d\n", i + 1);
        printf("Enter ID: ");
        scanf("%d", &a[i].id);
        printf("Enter species: ");
        scanf(" %[^\n]", a[i].species);
        printf("Enter count: ");
        scanf("%d", &a[i].count);
        printf("Enter park: ");
        scanf(" %[^\n]", a[i].loc.park);
        printf("Enter zone: ");
        scanf(" %[^\n]", a[i].loc.zone);
        printf("Enter type (1-contact 2-chip): ");
        scanf("%d", &a[i].type);
        if (a[i].type == 1) {
            printf("Enter contact: ");
            scanf(" %[^\n]", a[i].info.contact);
        } else {
            printf("Enter chip: ");
            scanf("%d", &a[i].info.chip);
        }
    }

    do {
        printf("\n1.Display\n2.Search\n3.Park total\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("\n--- Records ---\n");
            for (i = 0; i < n; i++) {
                printf("ID=%d\n", a[i].id);
                printf("Species=%s\n", a[i].species);
                printf("Count=%d\n", a[i].count);
                printf("Park=%s\n", a[i].loc.park);
                printf("Zone=%s\n", a[i].loc.zone);
                if (a[i].type == 1)
                    printf("Contact=%s\n", a[i].info.contact);
                else
                    printf("Chip=%d\n", a[i].info.chip);
                printf("\n");
            }
        } else if (ch == 2) {
            printf("Enter species: ");
            scanf(" %[^\n]", key);
            found = 0;
            for (i = 0; i < n; i++) {
                if (strcmp(a[i].species, key) == 0) {
                    printf("ID=%d Count=%d Park=%s\n", a[i].id, a[i].count, a[i].loc.park);
                    found = 1;
                }
            }
            if (found == 0)
                printf("Not found\n");
        } else if (ch == 3) {
            printf("Enter park: ");
            scanf(" %[^\n]", park);
            total = 0;
            for (i = 0; i < n; i++) {
                if (strcmp(a[i].loc.park, park) == 0)
                    total = total + a[i].count;
            }
            printf("Total in park=%d\n", total);
        }
    } while (ch != 4);

    return 0;
}
