#include <stdio.h>
#include <stdlib.h>

int mat[100][100], paths[100][100];
int n;
int count=0;

void warshal(int mat[100][100], int n) {
    // Initialize paths matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            paths[i][j] = mat[i][j];

    // Warshall’s algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (paths[i][k]) {  // only check if i->k path exists
                for (int j = 0; j < n; j++) {
                        count++;
                    paths[i][j] = paths[i][j] || paths[k][j];
                }
            }
        }
    }
}

void tester() {
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    warshal(mat, n);

    printf("\nPath matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", paths[i][j]);
        printf("\n");
    }
}
void plotter(){
        FILE *f1=fopen("warshalbest1.txt","a");
        FILE *f2=fopen("warshalworst1.txt","a");
        for(int k=1;k<=10;k++){
                 n=k;
                 int mat[n][n];
                 count=0;
                 //best case
                 for(int i=0;i<n;i++)
                         for(int j=0;j<n;j++)
                                 mat[i][j]=0;
                 for(int i=0;i<n-1;i++)
                         mat[i][i+1]=1;
                 warshal(mat,n);
                 fprintf(f1,"%d\t%d\n",n,count);
                 //worst case
                 for(int i=0;i<n;i++){
                         for(int j=0;j<n;j++){
                                 if(i==j)
                                         mat[i][j]=1;
                                 else
                                         mat[i][j]=0;}}
                 count=0;
                  warshal(mat,n);
                 fprintf(f2,"%d\t%d\n",n,count);
        }
        fclose(f1);
        fclose(f2);
}

void main(){
        tester();
        plotter();
}


~                      
