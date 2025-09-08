#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int opcount = 0, dp[25][25], weight[25], profit[25];
int i,j,k;
int max(int num1, int num2)
{
    return num1 > num2 ? num1 : num2;
}

int knapsackMemo(int n, int W)
{
    if (dp[n][W] != -1)
        return dp[n][W];

    opcount++;
    if (weight[n] <= W)
        return dp[n][W] = max(knapsackMemo(n - 1, W), profit[n] + knapsackMemo(n - 1, W - weight[n]));
    else
        return dp[n][W] = knapsackMemo(n - 1, W);
}

void init(int n, int W)
{
    for ( i = 0; i <= n; i++)
    {
        for (j = 0; j <= W; j++)
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else
                dp[i][j] = -1;
    }
}

void tester()
{
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Sack capacity: ");
    scanf("%d", &W);
    for (i = 1; i <= n; i++)
    {
        printf("Enter weight and profit of item %d :", i );
        scanf("%d%d", &weight[i], &profit[i]);
    }
    init(n, W);
    printf("Max profit is %d\n", knapsackMemo(n, W));
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= W; j++)
        {
            printf("%d\t", dp[i][j]);
        }
        printf("\n");
    }
    printf("Picked items:\n");
    int k = W;
    for ( i = n; i > 0; i--)
    {
        if (dp[i][k] != dp[i - 1][k])
        {
            printf("%d\t", i);
            k -= weight[i - 1];
        }
    }
    printf("\nOpcount:%d", opcount);
}

void plotter()
{
    FILE *fp = fopen("knapsackMemo.txt", "w");
    for(k=1;k<=10;k++)
    {
        int n=k*2;
        int m=k*5;
        for (j = 1; j <= n; j++)
        {
            weight[j] = rand() % m + 1;
            profit[j] = rand() % 50 + 1;
        }
        init(n, m);
        opcount = 0;
        knapsackMemo(n, m);
        fprintf(fp, "%d\t%d\n", n, opcount);
    }
    fclose(fp);
}

void main()
{
    int ch;
    printf("Enter \n1.Tester\n2.Plotter\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        tester();
        break;
    case 2:
        plotter();
        break;
    default:
        printf("Invalid choice.\n");
    }
}
