#include <stdio.h>
#include <stdlib.h>
#include <limits.h>  // For INT_MAX and INT_MIN

// Euclid's algorithm
float euclid(int m, int n) {
    int r;
    float count = 0;
    while (n) {
        count++;
        r = m % n;
        m = n;
        n = r;
    }
    printf("\nGCD (Euclid): %d", m);
    return count;
}

// Consecutive integer checking method
float consec(int m, int n) {
    int min = (m < n) ? m : n;
    float count = 0;
    while (1) {
        count++;
        if (m % min == 0) {
            count++;
            if (n % min == 0) {
                printf("\nGCD (Consec): %d", min);
                return count;
            }
        }
        min--;
    }
}

// Repeated subtraction method
float modified(int m, int n) {
    float count = 0;
    int temp;
    while (n > 0) {
        if (n > m) {
            temp = m;
            m = n;
            n = temp;
        }
        m = m - n;
        count++;
    }
    printf("\nGCD (Modified): %d", m);
    return count;
}

// Function to test all methods
void tester() {
    int m, n;
    printf("\nEnter two numbers: ");
    scanf("%d %d", &m, &n);

    if (m <= 0 || n <= 0) {
        printf("Cannot find GCD... Invalid inputs.\n");
        return;
    }

    printf("\nSteps taken by each method:");
    printf("\nEuclid steps: %.0f", euclid(m, n));
    printf("\nConsecutive steps: %.0f", consec(m, n));
    printf("\nModified steps: %.0f\n", modified(m, n));
}

// Function to generate data for plot
void plotter() {
    FILE *f1 = fopen("euclidBest.txt", "w");
    FILE *f2 = fopen("euclidWorst.txt", "w");
    FILE *f3 = fopen("consecBest.txt", "w");
    FILE *f4 = fopen("consecWorst.txt", "w");
    FILE *f5 = fopen("modifiedBest.txt", "w");
    FILE *f6 = fopen("modifiedWorst.txt", "w");

    int i, j, k;

    for (i = 10; i <= 100; i += 10) {
        float minE = INT_MAX, maxE = INT_MIN;
        float minC = INT_MAX, maxC = INT_MIN;
        float minM = INT_MAX, maxM = INT_MIN;

        for (j = 2; j <= i; j++) {
            for (k = 2; k <= i; k++) {
                float e = euclid(j, k);
                if (e < minE) minE = e;
                if (e > maxE) maxE = e;

                float c = consec(j, k);
                if (c < minC) minC = c;
                if (c > maxC) maxC = c;

                float m = modified(j, k);
                if (m < minM) minM = m;
                if (m > maxM) maxM = m;
            }
        }

        fprintf(f1, "%d\t%.0f\n", i, minE);
        fprintf(f2, "%d\t%.0f\n", i, maxE);
        fprintf(f3, "%d\t%.0f\n", i, minC);
        fprintf(f4, "%d\t%.0f\n", i, maxC);
        fprintf(f5, "%d\t%.0f\n", i, minM);
        fprintf(f6, "%d\t%.0f\n", i, maxM);
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
    fclose(f5);
    fclose(f6);
}

// Main driver function
int main() {
    int ch;
    printf("\nEnter:\n1. Tester\n2. Plotter\nChoice: ");
    scanf("%d", &ch);

    switch (ch) {
        case 1:
            tester();
            break;
        case 2:
            plotter();
            break;
        default:
            printf("Invalid choice!!\n");
    }

    return 0;
}
