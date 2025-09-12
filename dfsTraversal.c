#include<stdio.h>
#include<stdlib.h>


int iscyclic=0,connected=0,istester=0,count=0;
int source,par,n;
void dfs(int mat[n][n],int *vis,int source,int par){
        vis[source]=1;

         if(istester)
                 printf("%d ",source);
         for(int i=0;i<n;i++){
                 count++;
                 if(mat[source][i] && vis[i] && i!=par)
                         iscyclic=1;
                 else if(mat[source][i] && !vis[i])
                         dfs(mat,vis,i,source);
         }}
void connectivity(int mat[n][n]){
        int vis[n],k=1;
        for(int i=0;i<n;i++)
                vis[i]=0;
        for(int i=0;i<n;i++){
                if(!vis[i]){
                        connected++;
                        if(istester)
                                printf("\n Component %d:",k++);
                        dfs(mat,&vis[0],i,-1);
                }}}
void tester(){
       printf("\n Enter the number of vertices");
       scanf("%d",&n);
       int mat[n][n];
       printf("\n Enter the adjacency matrix:");
       for(int i=0;i<n;i++)
         for(int j=0;j<n;j++)
            scanf("%d",&mat[i][j]);
       istester=1;
       connectivity(mat);
       printf("\n The number of connected components %d ",connected);
       if(iscyclic)
               printf("\n Cycle exists");
       else
               printf("\n No cycle exists");
}
void plotter(){
        istester=0;
   FILE *f1=fopen("dfsbest.txt","a");
   FILE *f2=fopen("dfsworst.txt","a");
   for(int k=1;k<=10;k++){
         n=k;
         int mat[n][n];
         //best case
         count=0;
         for(int i=0;i<n;i++)
                 for(int j=0;j<n;j++)
                         mat[i][j]=0;
         for(int i=0;i<n-1;i++)
                 mat[i][i+1]=1;
         connectivity(mat);
         fprintf(f1,"%d\t%d\n",n,count);
         //worst case
         count=0;
         for(int i=0;i<n;i++)
                 for(int j=0;j<n;j++)
                         mat[i][j]=0;
         for(int i=0;i<n;i++)
                 for(int j=i+1;j<n;j++)
                         mat[i][j]=1;
         connectivity(mat);
         fprintf(f2,"%d\t%d\n",n,count);
   }fclose(f1);
   fclose(f2);
}

int main(){
        tester();
        plotter();
}
~                                                                                                                                                                                                                                                                                                                                                                                       ~            
