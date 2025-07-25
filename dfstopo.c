#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int graph[MAX][MAX], visit[MAX], path[MAX], count = 0, stack[MAX];
int top = -1, c = 0, i, j;

void dfs(int n, int source) {
    visit[source] = 1;
    path[source] = 1;

    for (i = 0; i < n; i++) {
        count++;
        if (graph[source][i] && visit[i] && path[i])
            c = 1;
        if (graph[source][i] && !visit[i])
            dfs(n, i);
    }

    path[source] = 0;
    stack[++top] = source;
}

void tester() {
    int n;
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        visit[i] = 0;
        path[i] = 0;
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Topological Order:\n");
    for (i = 0; i < n; i++) {
        if (!visit[i])
            dfs(n, i);
    }

    if (c == 1) {
        printf("Cycle Detected! Topological sort not possible.\n");
        return;
    }

    for (i = top; i >= 0; i--)
        printf("-->%c", stack[i] + 65);
    printf("\n");
}

void plotter(int k) {
    int v;
    FILE *f = NULL;

    if (k == 0)
        f = fopen("dfstopworst.txt", "w");
    else
        f = fopen("dfstopbest.txt", "w");

    if (!f) {
        printf("File open error!\n");
        return;
    }

    for (v = 1; v <= 10; v++) {
        // Allocate and build graph
        int **arr = malloc(v * sizeof(int *));
        for (i = 0; i < v; i++)
            arr[i] = malloc(v * sizeof(int));

        if (k == 0) {
            // Worst case: fully connected except diagonal
            for (i = 0; i < v; i++)
                for (j = 0; j < v; j++)
                    arr[i][j] = (i != j) ? 1 : 0;
        } else {
            // Best case: linear chain
            for (i = 0; i < v; i++)
                for (j = 0; j < v; j++)
                    arr[i][j] = 0;
            for (i = 0; i < v - 1; i++)
                arr[i][i + 1] = 1;
        }

        // Copy to global graph
        for (i = 0; i < v; i++) {
            visit[i] = 0;
            path[i] = 0;
            for (j = 0; j < v; j++)
                graph[i][j] = arr[i][j];
        }

        count = 0;
        top = -1;
        for (i = 0; i < v; i++)
            if (!visit[i])
                dfs(v, i);

        fprintf(f, "%d\t%d\n", v, count);

        for (i = 0; i < v; i++)
            free(arr[i]);
        free(arr);
    }

    fclose(f);
}

int main() {
    int ch;
    for (;;) {
        printf("\n1. Test Topological Sort");
        printf("\n2. Generate Best and Worst Case Files");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            tester();
            break;
        case 2:
            plotter(0); // worst case
            plotter(1); // best case
            printf("Files generated: dfstopbest.txt and dfstopworst.txt\n");
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
