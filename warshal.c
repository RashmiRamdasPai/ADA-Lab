#include<stdio.h>
#include<stdlib.h>

int n,opcount,paths[100][100];
int i,j,k;
int warshall(int adj[n][n],int n){
	opcount=0;
	for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
	     paths[i][j]=adj[i][j];
	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			if(paths[i][k]){
				for(j=0;j<n;j++){
					opcount++;
					paths[i][j]=paths[i][j]||paths[i][k] && paths[k][j];
				}
			}
		}
	}
}

void tester(){
	printf("\n Enter the number of vertices:");
	scanf("%d",&n);
	int mat[n][n];
	printf("\n Enter the adjacency matrix");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&mat[i][j]);
		}
	}
	warshall(mat,n);
	printf("\n Transitive closure:");
	for(i=0;i<n;i++){
	
	  for(j=0;j<n;j++)
	     printf("%d",paths[i][j]);
	printf("\n");}
}

void plotter(){
	FILE *f1 =  fopen("warshalbest.txt","a");
	FILE *f2 =  fopen("warshalworst.txt","a");
	for(k=1;k<=10;k++){
		n=k;
		int mat[n][n];
	  for(j=0;j<n;j++)
	  	for(i=0;i<n;i++)
	  		if(i!=j)
	  		  mat[i][j]=1;
	  		else 
	  		  mat[i][j]=0;
		  warshall(mat,n);
		  fprintf(f2,"%d\t%d\n",n,opcount);
		  for(i=0;i<n;i++)
		    for(j=0;j<n;j++)
		       mat[i][j]=0;
		for(i=0;i<n-1;i++)
		  mat[i][i+1]=1;
		mat[n-1][0]=1;
		warshall(mat,n);
		fprintf(f1,"%d\t%d\n",n,opcount);
	  
	}
	fclose(f1);
	fclose(f2);
}

void main(){
	int ch;
	for(;;){
	
	printf("\n 1.Tester 2.Plotter 3.Exit \n");
	printf("\n Enter your choice");
	scanf("%d",&ch);
	switch(ch){
		case 1:tester();
		       break;
		case 2:plotter();
		      break;
		case 3:exit(0);
	    default:printf("\n Inavlid choice");
	}
}
}
