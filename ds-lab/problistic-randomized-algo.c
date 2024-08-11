#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double monteCarloPi(int n) {
    int circlePoints = 0;
    int squarePoints = 0;

    for (int i = 0; i < n; i++) {
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;

        if (x * x + y * y <= 1) {
            circlePoints++;
        }
        squarePoints++;
    }

    return 4.0 * (double)circlePoints / (double)squarePoints;
}

int main() {
    srand(time(0));
    int n = 100000; // Number of points
    double pi = monteCarloPi(n);
    printf("Estimated Pi value: %f\n", pi);

    return 0;
}
