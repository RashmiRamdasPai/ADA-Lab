#include<stdio.h>
#include<stdlib.h>

int n,indegree[20],opcount=0,queue[20],front=-1,rear=-1;
int i,j;
int k;
int bfs(int mat[n][n]){
	int count=0;
	front=-1,rear=-1;
	for(i=0;i<n;i++){
	 
	  if(indegree[i]==0){
	  	queue[++rear]=i;
	  }
	
}
while(front!=rear){
	count++;
	int cur=queue[++front];
	for(i=0;i<n;i++){
		opcount++;
		if(mat[cur][i]){
			indegree[i]--;
			if(!indegree[i])
			  queue[++rear]=i;
		}
	}
}return count!=n;
}

void tester(){
	printf("\n Enter the number of vertices");
	scanf("%d",&n);
	int mat[n][n];
	for(i=0;i<n;i++)
	
	  indegree[i]=0;
	printf("\n Enter the adjacency matrix");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&mat[i][j]);
			if(mat[i][j])
			  indegree[j]++;
		}
	}
	if(bfs(mat)){
		printf("\n Cycle exists...");
		exit(0);
	}
	else{
		printf("\n Topological order:");
		for(i=0;i<=rear;i++)
		  printf("%d->",queue[i]);
		
	}
	
}

void plotter(){
	FILE *f2=fopen("sourceworst.txt","a");
	FILE *f1=fopen("sourcebest.txt","a");
	for(k=1;k<=10;k++){
		n=k;
		int mat[n][n];
		for(i=0;i<n;i++)
		  indegree[i]=0;
		  //worst case
	 for(i=0;i<n;i++)
	   for(j=0;j<n;j++)
	      mat[i][j]=0;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			mat[i][j]=1;
			indegree[j]++;
		}
	}
	opcount=0;
	bfs(mat);
	fprintf(f2,"%d\t%d\n",n,opcount);
		for(i=0;i<n;i++)
		  indegree[i]=0;
		  //worst case
	 for(i=0;i<n;i++)
	   for(j=0;j<n;j++)
	      mat[i][j]=0;
	for(i=0;i<n-1;i++){
	     mat[i][i+1]=1;
			indegree[i+1]++;
		}
			opcount=0;
	bfs(mat);
	fprintf(f1,"%d\t%d\n",n,opcount);
	}
	
	
	fclose(f1);
	fclose(f2);
}

void main(){
	int ch;
	for(;;){
		printf("\n Enter ur choice 1.to test 2.to plot 3.exit");
		scanf("%d",&ch);
		switch(ch){
			case 1:tester();
			        break;
			case 2:plotter();
			        break;
			default:printf("\n Invalid choice");
		}
	}
}
	
