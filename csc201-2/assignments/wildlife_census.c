#include <stdio.h>
#include <string.h>

struct species_record {
  int id;
  char name[40];
  char park[50];
  char zone;
  short int count;
  float habitat_area;
  char status;
};

void read_populations(int *population, int n) {
  int i;

  printf("\nEnter population of each species:\n");
  for (i = 0; i < n; i++) {
    printf("Species %d: ", i + 1);
    scanf("%d", population + i);
  }
}

void display_populations(int *population, int n) {
  int i;

  printf("\n----- Stored Population Data -----\n");
  for (i = 0; i < n; i++)
    printf("Species %d : %d\n", i + 1, *(population + i));
}

int total_population(int *population, int n) {
  int i, total = 0;

  for (i = 0; i < n; i++)
    total = total + *(population + i);

  return total;
}

float average_population(int *population, int n) {
  return (float)total_population(population, n) / n;
}

int max_population(int *population, int n) {
  int i, maximum = *population;

  for (i = 1; i < n; i++) {
    if (*(population + i) > maximum)
      maximum = *(population + i);
  }

  return maximum;
}

int run_1d_census() {
  int population[10];
  int n, total, maximum;
  float average;

  printf("\n===== 1D CENSUS =====\n");
  do {
    printf("Enter number of species (1-10): ");
    scanf("%d", &n);
  } while (n < 1 || n > 10);

  read_populations(population, n);
  display_populations(population, n);

  total = total_population(population, n);
  average = average_population(population, n);
  maximum = max_population(population, n);

  printf("\n----- Census Analysis -----\n");
  printf("Total Population   : %d\n", total);
  printf("Average Population : %.2f\n", average);
  printf("Maximum Population : %d\n", maximum);
  printf("Pointer of array   : %p\n", population);

  return total;
}

void read_zone_matrix(int *matrix, int rows, int cols) {
  int i, j;

  printf("\nEnter population for each species and zone:\n");
  for (i = 0; i < rows; i++) {
    printf("Species %d:\n", i + 1);
    for (j = 0; j < cols; j++) {
      printf("  Zone %d: ", j + 1);
      scanf("%d", matrix + i * cols + j);
    }
  }
}

void display_zone_matrix(int *matrix, int rows, int cols, char *zones) {
  int i, j;

  printf("\n----- Zone Population Matrix -----\n");
  printf("%-12s", "Species");
  for (j = 0; j < cols; j++)
    printf("%-10c", *(zones + j));
  printf("\n");

  for (i = 0; i < rows; i++) {
    printf("Species %-4d", i + 1);
    for (j = 0; j < cols; j++)
      printf("%-10d", *(matrix + i * cols + j));
    printf("\n");
  }
}

int row_total(int *matrix, int cols, int row) {
  int j, total = 0;

  for (j = 0; j < cols; j++)
    total = total + *(matrix + row * cols + j);

  return total;
}

int col_total(int *matrix, int rows, int cols, int col) {
  int i, total = 0;

  for (i = 0; i < rows; i++)
    total = total + *(matrix + i * cols + col);

  return total;
}

float zone_density(int population, float area) {
  if (area <= 0)
    return 0;

  return (float)population / area;
}

int run_2d_census() {
  int matrix[10 * 5];
  char zones[5];
  float habitat_area[5];
  int rows, cols, i, j;
  int species_total, zone_pop, overall = 0;
  float density;

  printf("\n===== 2D CENSUS =====\n");
  do {
    printf("Enter number of species (1-10): ");
    scanf("%d", &rows);
  } while (rows < 1 || rows > 10);

  do {
    printf("Enter number of zones (1-5): ");
    scanf("%d", &cols);
  } while (cols < 1 || cols > 5);

  printf("\nEnter zone codes and habitat area (sq.km):\n");
  for (j = 0; j < cols; j++) {
    printf("Zone %d code: ", j + 1);
    scanf(" %c", zones + j);
    printf("Zone %c area: ", *(zones + j));
    scanf("%f", habitat_area + j);
  }

  read_zone_matrix(matrix, rows, cols);
  display_zone_matrix(matrix, rows, cols, zones);

  printf("\n----- Species-wise Totals -----\n");
  for (i = 0; i < rows; i++) {
    species_total = row_total(matrix, cols, i);
    overall = overall + species_total;
    printf("Species %d Total Population : %d\n", i + 1, species_total);
  }

  printf("\n----- Zone-wise Density -----\n");
  for (j = 0; j < cols; j++) {
    zone_pop = col_total(matrix, rows, cols, j);
    density = zone_density(zone_pop, *(habitat_area + j));
    printf("Zone %c Area=%.2f Population=%d Density=%.2f\n", *(zones + j),
           *(habitat_area + j), zone_pop, density);
  }

  printf("\nOverall Wildlife Population : %d\n", overall);
  return overall;
}

void read_records(struct species_record *records, int n) {
  int i;

  for (i = 0; i < n; i++) {
    printf("\nRecord %d\n", i + 1);
    printf("Enter ID: ");
    scanf("%d", &records[i].id);
    printf("Enter species: ");
    scanf(" %[^\n]", records[i].name);
    printf("Enter park: ");
    scanf(" %[^\n]", records[i].park);
    printf("Enter zone: ");
    scanf(" %c", &records[i].zone);
    printf("Enter count: ");
    scanf("%hd", &records[i].count);
    printf("Enter habitat area: ");
    scanf("%f", &records[i].habitat_area);
    printf("Enter status (S/E/C): ");
    scanf(" %c", &records[i].status);
  }
}

void display_records(struct species_record *records, int n) {
  int i;
  float density;

  printf("\n--- Records ---\n");
  for (i = 0; i < n; i++) {
    density = zone_density(records[i].count, records[i].habitat_area);
    printf("ID=%d\n", records[i].id);
    printf("Species=%s\n", records[i].name);
    printf("Park=%s\n", records[i].park);
    printf("Zone=%c\n", records[i].zone);
    printf("Count=%hd\n", records[i].count);
    printf("Area=%.2f\n", records[i].habitat_area);
    printf("Density=%.2f\n", density);
    printf("Status=%c\n\n", records[i].status);
  }
}

int search_by_name(struct species_record *records, int n, char *key) {
  int i, found = 0;

  for (i = 0; i < n; i++) {
    if (strcmp(records[i].name, key) == 0) {
      printf("ID=%d Count=%hd Park=%s\n", records[i].id, records[i].count,
             records[i].park);
      found = 1;
    }
  }

  return found;
}

float park_density(struct species_record *records, int n, char *park) {
  int i, total_count = 0;
  float total_area = 0;

  for (i = 0; i < n; i++) {
    if (strcmp(records[i].park, park) == 0) {
      total_count = total_count + records[i].count;
      total_area = total_area + records[i].habitat_area;
    }
  }

  return zone_density(total_count, total_area);
}

int run_structure_census() {
  struct species_record records[20];
  int n, ch, found;
  char key[40], park[50];
  float density;

  printf("\n===== STRUCTURE CENSUS =====\n");
  do {
    printf("Enter number of records (1-20): ");
    scanf("%d", &n);
  } while (n < 1 || n > 20);

  read_records(records, n);

  do {
    printf("\n1.Display\n2.Search\n3.Park density\n4.Back\n");
    printf("Enter choice: ");
    scanf("%d", &ch);

    if (ch == 1) {
      display_records(records, n);
    } else if (ch == 2) {
      printf("Enter species: ");
      scanf(" %[^\n]", key);
      found = search_by_name(records, n, key);
      if (found == 0)
        printf("Not found\n");
    } else if (ch == 3) {
      printf("Enter park: ");
      scanf(" %[^\n]", park);
      density = park_density(records, n, park);
      printf("Density=%.2f\n", density);
    }
  } while (ch != 4);

  return n;
}

int main() {
  int choice, result;

  printf("===== WILDLIFE CENSUS DATA MANAGEMENT =====\n");

  do {
    printf("\n1.1D arrays\n2.2D arrays\n3.Array of structures\n4.Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
      result = run_1d_census();
      printf("Total population=%d\n", result);
    } else if (choice == 2) {
      result = run_2d_census();
      printf("Overall population=%d\n", result);
    } else if (choice == 3) {
      result = run_structure_census();
      printf("Records stored=%d\n", result);
    }
  } while (choice != 4);

  return 0;
}
