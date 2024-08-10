// A program to print truth tablw for AND operation

#include <stdio.h>

int main() {
  printf("Truth table for AND operation:\n");
  printf("A | B | A AND B\n");
  for (int A = 0; A <= 1; A++) {
    for (int B = 0; B <= 1; B++) {
      printf(" %d | %d |   %d\n", A, B, A && B);
    }
  }
}
