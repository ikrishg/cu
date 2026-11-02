#include <stdio.h>

int main() {
  char stud_name[20] = "Krish Gupta";
  int sub_marks[5] = {99, 98, 97, 96, 100};
  float att_ptg[5] = {99.5, 98.5, 97.5, 96.5, 100.0};

  printf("Student Name: %s\n", stud_name);
  printf("Subject\t\t\t\tMarks\tAttendance\n");
  printf("---------------------------------------------------\n");
  printf("English   \t\t\t%d\t%.2f%%\n", sub_marks[0], att_ptg[0]);
  printf("Language  \t\t\t%d\t%.2f%%\n", sub_marks[1], att_ptg[1]);
  printf("C PROG    \t\t\t%d\t%.2f%%\n", sub_marks[2], att_ptg[2]);
  printf("Statistics\t\t\t%d\t%.2f%%\n", sub_marks[3], att_ptg[3]);
  printf("WSD       \t\t\t%d\t%.2f%%\n", sub_marks[4], att_ptg[4]);
  return 0;
}
