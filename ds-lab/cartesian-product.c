// WAP to find the cartesian product of two set
//

#include <stdio.h>

int main() {
  int setA[] = {1, 2};
  int setB[] = {3, 4};

  int sizeA = sizeof(setA) / sizeof(setA[0]);
  int sizeB = sizeof(setB) / sizeof(setB[0]);

  printf("Cartesian Product:\n");
  for (int i = 0; i < sizeA; i++) {
    for (int j = 0; j < sizeB; j++) {
      printf("(%d, %d)\n", setA[i], setB[j]);
    }
  }

  return 0;
}
