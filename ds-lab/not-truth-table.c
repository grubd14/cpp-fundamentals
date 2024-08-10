//A program to show truth table
//

#include <stdio.h>

int main() {
  printf("Truth table for NOT operations:\n");
  printf("A | NOT A \n");
  for (int A = 0; A <= 1; A++) {
    printf(" %d | %d\n", A, !A);
  }
};

