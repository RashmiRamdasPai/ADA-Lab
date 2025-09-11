#include <stdio.h>
#include <stdlib.h>

int isCycle = 0, components = 0, n, opcount = 0, isTester = 0;
int i,j,k;

void dfs(int mat[n][n], int *vis, int source, int par)
{
    vis[source] = 1;

    if (isTester)
        printf("%d ", source);

    for ( i = 0; i < n; i++)
    {
        opcount++;
        if (mat[source][i] && vis[i] && i != par)
            isCycle = 1;
        else if (mat[source][i] && !vis[i])
            dfs(mat, vis, i, source);
    }
}

void checkConnectivity(int mat[n][n])
{
    int vis[n], k = 1;

    for ( i = 0; i < n; i++)
        vis[i] = 0;

    for ( i = 0; i < n; i++)
        if (!vis[i])
        {
            components++;

            if (isTester)
                printf("\nComponent %d: ", k++);
            dfs(mat, &vis[0], i, -1);
        }
}

void tester()
{
    isTester = 1;
    printf("Enter the number of vertices\n");
    scanf("%d", &n);
    int adjMat[n][n];
    printf("Enter the adjacency matrix :\n");
    for ( i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adjMat[i][j]);

    checkConnectivity(adjMat);

    printf("\nThe number of connected components :%d\n", components);

    if (isCycle)
        printf("Cycle exists\n");
    else
        printf("Cycle doesnot exists\n");
}

void plotter(){
	istester=0;
	FILE *f1 = fopen("bfsbest.txt","a");
	FILE *f2 = fopen("bfsworst.txt","a");
	for(k=1;k<=10;k++){
		n=k;
		int mat[n][n];
		//worst case:complete graph
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(i!=j)
				  mat[i][j]=1;
				else
				 mat[i][j]=0;
			}
		}
	
	opcount=0;
	iscyclic=0;
	connected=0;
	connectivity(mat);
	fprintf(f1,"%d\t%d\n",n,opcount);
	//best case:linear chain
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			mat[i][j]=0;
	for(i=0;i<n-1;i++)
{
		  mat[i][i+1]=1;
		  mat[i+1][i]=1;
		  }
		  opcount=0;
	iscyclic=0;
	connected=0;
	connectivity(mat);
	fprintf(f2,"%d\t%d\n",n,opcount);
	  
}fclose(f1);
fclose(f2);
}


void main()
{
    int choice;
    printf("Enter\n1.Tester\n2.Plotter\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        tester();
        break;
    case 2:
        plotter();
        break;
    default:
        printf("Invalid choice");
    }
}
