#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int key[100],vis[100],parent[100],mat[100][100],n,c=0;
int source;
int i,j;
int count=0;
void create(int n){
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==j)
			  mat[i][j]=0;
			else
			 mat[i][j]=rand()%100+1;
		}
	}
}

void prims(int source){
	int i,w,u,min,nums;
	for( i=1;i<=n;i++){
		key[i]=9999;
		vis[i]=0;
		parent[i]=-1;
	}
	key[source]=0;
	for(i=1;i<=n;i++){
		u=-1;
		min=9999;//find unvisited vertex with min key
		for(w=1;w<=n;w++){
			count++;
			if(vis[w]==0 && key[w]<min){
                  min=key[w];
				  u=w;				
			}
		}
		if(u==-1)
		 break;
		vis[u]=1; //vertex with the minimun key is visited now
		for(w=1;w<=n;w++){
			count++;
			if(mat[u][w]!=0 && vis[w]==0 && mat[u][w]<key[w] ){
				parent[w]=u;
				key[w]=mat[u][w];
			}
		}
	}
}  

void tester(){
	int v;
	int total_cost=0;
	printf("\n Enter the total number of vertices");
	scanf("%d",&n);
	printf("\n Enter the cost matrix:");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&mat[i][j]);
			if(mat[i][j]==999)
			  mat[i][j]=0;
		}
	}
	printf("\n Enter the source:");
	scanf("%d",&source);
	count=0;
	prims(source);
	for(i=1;i<=n;i++){
		if(parent[i]!=-1)
		printf("%d-%d\t\t%d\n",parent[i],i,key[i]);
		total_cost+=key[i];
	}
	printf("Min cost %d\n",total_cost);
	
}

void plotter(){
	FILE *fp=fopen("prim.txt","w");
	srand(time(NULL));
	for(i=2;i<=10;i++){
		n=i;
		count=0;
		create(n);
		prims(1);
		fprintf(fp,"%d\t%d\n",n,count);
	}
	fclose(fp);
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
