#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int mat[100][100],key[100],vis[100],source;
int count=0;int n;
int i,j,w;
void create(int n){
        for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                        if(i==j)
                                mat[i][j]=0;
                        else
                                mat[i][j]=rand()%100+1;}}}

void dijkstra(int source){
        int min,u;
   for(int i=1;i<=n;i++)
       {
               vis[i]=0;
               key[i]=mat[source][i];
       }
   key[source]=0;


   //dikstra core loop
   for(i=1;i<=n;i++){
              u=-1;
              min=999;
              for(int w=1;w<=n;w++){
                      
                      if(vis[w]==0 && key[w]<min){
                              u=w;
                              min=key[w];
                      }}
                      
               if(u==-1) break;
           vis[u]=1;
               for(int w=1;w<=n;w++){
                       count++;
                       if(mat[u][w]!=0 && vis[w]==0 && key[w]>key[u]+mat[u][w])
                               key[w]=key[u]+mat[u][w];
               }}}
         void tester(){

        printf("\n Enter the number of vertices");
        scanf("%d",&n);
        printf("\n Enter the cost matrix:\n");
        for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                        scanf("%d",&mat[i][j]);


                }
        }
        printf("\n Enter the source\n");
        scanf("%d",&source);
        dijkstra(source);
        for(int i=1;i<=n;i++)
          printf("%d-%d=%d\n",source,i,key[i]);
}
void plotter(){
        FILE *fp=fopen("dij.txt","w");
        srand(time(NULL));
        for(i=2;i<=10;i++){
                n=i;
                count=0;
                create(n);
                dijkstra(1);
                fprintf(fp,"%d\t%d\n",n,count);
        }
        fclose(fp);
}
void main(){
        tester();
        plotter();
}
~                             
