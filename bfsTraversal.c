#include<stdio.h>
#include<stdlib.h>

int iscyclic=0,connected=0,istester,n,opcount=0;
int i,j,k;
void bfs(int mat[n][n], int *visit, int source) {
    int queue[n], parent[n];
    int front = -1, rear = -1;

    queue[++rear] = source;
    parent[rear] = -1;
    visit[source] = 1;

    while (rear!=front) {
        int cur = queue[++front];
        int par = parent[front];  // ? Fix: access by node index

        if (istester)
            printf("%d ", cur);

        for ( i = 0; i < n; i++) {
            opcount++;
            if (mat[cur][i] && i!=par && visit[i]  )                 
                    iscyclic = 1;  // ? Detected back edge (cycle)
                 if (!visit[i] && mat[cur][i] ) {
                    queue[++rear] = i;
                    parent[rear] = cur;  // ? Fix: set parent by node
                    visit[i] = 1;
                }
            }
        }
    }



void connectivity(int mat[n][n]){
	int visit[n],k=1;
	for(i=0;i<n;i++)
	  visit[i]=0;
	for(i=0;i<n;i++){
		if(!visit[i]){
			connected++;
			if(istester)
			  printf(" Connected component %d \n",k++);
			bfs(mat,&visit[0],i);
		}
	}
	  
}

void tester(){
	istester=1;
	printf("\n Enter the number of vertices");
	scanf("%d",&n);
	int adjmat[n][n];
	printf("\n Enter the matrix elements");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&adjmat[i][j]);
		}
	}
	connected = 0;
iscyclic = 0;
opcount = 0;

	connectivity(adjmat);
	printf("\n The number of conneceted components %d",connected);
	if(iscyclic==1)
	  printf("\n The graph is cyclic");
	else
	 printf("\n The graph is not cyclic");
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

void main(){
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
