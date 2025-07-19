#include<stdio.h>
 #include<stdlib.h>
 #define INF 999
 
 int count=0,i,j;
 
 void dijkstra(int n,int cost[15][15],int source,int dist[15]){
 	int num;
 	int visited[15]={0},i,j,min,u;
 	
 	for(i=1;i<=n;i++){
 		dist[i]=cost[source][i];
	 }
	 visited[source]=1;
	 dist[source]=0;
	 //dikstras core loop
	for( num=2;num<=n;num++){
		min=INF;
		for(j=1;j<=n;j++){
			if(visited[j]==0 && dist[j]<min){
				min= dist[j];
				u=j;
			}
		}
		visited[u]=1;
		for(j=1;j<=n;j++){
			count++;
				if(visited[j]==0 && dist[j]>dist[u]+cost[u][j]){
					dist[j]=dist[u]+cost[u][j];
				}
		}
	}
	
 }
 void tester(){
 	int n,cost[15][15],i,j,source,dist[15];
 	printf("\n Enter the number of vertices");
 	scanf("%d",&n);
 	printf("\n Enter the cost matrix");
 	for(i=1;i<=n;i++){
 		for(j=1;j<=n;j++){
 			scanf("%d",&cost[i][j]);
		 }
	 }
	 printf("\n Enter the source vertex");
	 scanf("%d",&source);
	 dijkstra(n,cost,source,dist);
	 printf("Vertex\tDestination\tCost\n");
	 for(i=1;i<=n;i++)
	   printf("%d\t %d\t\t %d\n",source,i,dist[i]);
 }
 void plotter(){
 	int v;
 	
 	FILE *f = fopen("dijkstra.txt","a");
 	for( v=2;v<=10;v++){
 		int cost[15][15];
 		int dist_p[15];
 		for(i=1;i<=v;i++){
 			for(j=1;j<=v;j++){
 				if(i==j)
 				  cost[i][j]=0;
 				else
 				  cost[i][j]=rand()%10+1;
			 }
		 }
		 count=0;
		 dijkstra(v,cost,1,dist_p);
		 fprintf(f,"%d\t%d\n",v,count,dist_p);
	 }
 }
 int main(){
 	int ch;
 		while(ch!=3){
 	printf("\n Enter ur choice");
 	printf("\n1.To test \n2.To plot \n0.Exit");
 	scanf("%d",&ch);
 
	 
 	switch(ch){
 		case 1:tester();
 		break;
 		case 2:plotter();
 		break;
 		case 0:exit(0);
 		default:break;
	 }}
 }
