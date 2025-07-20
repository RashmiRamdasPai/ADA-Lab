#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

int count, i, j;

// Brute-force string matching
bool stringmatching(char *pattern, char *text, int m, int n) {
    count = 0;
    for (i = 0; i <= n - m; i++) {
        j = 0;
        while (j < m) {
            count++;
            if (pattern[j] != text[i + j])
                break;
            j++;
        }
        if (j == m)
            return true;
    }
    return false;
}

void tester() {
    int m, n;
    char text[1000], pattern[1000];

    printf("\nEnter the text length: ");
    scanf("%d", &n);
    getchar();  // consume newline

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0;  // remove trailing newline if any

    printf("Enter the pattern length: ");
    scanf("%d", &m);
    getchar();  // consume newline

    printf("Enter the pattern: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = 0;

    bool ans = stringmatching(pattern, text, m, n);
    if (ans)
        printf("\nString found");
    else
        printf("\nString not found");
}

void plotter() {
	int m;
    FILE *f1 = fopen("stringbest.txt", "a");
    FILE *f2 = fopen("stringavg.txt", "a");
    FILE *f3 = fopen("stringworst.txt", "a");

    
    char *text = (char *)malloc(1000 * sizeof(char));
    for (i = 0; i < 1000; i++)
        text[i] = 'a';
    int n = 1000;

    srand(time(NULL)); // Seed random for average case

    for ( m = 10; m <= 1000; m += 10) {
        char *pattern = (char *)malloc((m + 1) * sizeof(char));

        // Best case (match at first position)
        for (i = 0; i < m; i++) pattern[i] = 'a';
        pattern[m] = '\0';
        stringmatching(pattern, text, m, n);
        fprintf(f1, "%d\t%d\n", m, count);

        // Worst case (last character mismatches)
        pattern[m - 1] = 'b';
        stringmatching(pattern, text, m, n);
        fprintf(f3, "%d\t%d\n", m, count);

        // Average case (random pattern)
        for (i = 0; i < m; i++)
            pattern[i] = 'a' + rand() % 3; // a, b, c
        pattern[m] = '\0';
        stringmatching(pattern, text, m, n);
        fprintf(f2, "%d\t%d\n", m, count);

        free(pattern);
    }

    free(text);
    fclose(f1);
    fclose(f2);
    fclose(f3);
}

int main() {
    int ch;
    while (1) {
        printf("\nEnter your choice: 1.Test 2.Plot 3.Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1: tester(); break;
            case 2: plotter(); break;
            case 3: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
