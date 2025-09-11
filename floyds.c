#include<stdio.h>
#include<stdlib.h>

int mat[100][100],n;
int count=0;
void create(int n){
        for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                        if(i==j)
                                mat[i][j]=0;
                        else
                                mat[i][j]=rand()%100+1;}}}

void floyds(int mat[100][100],int n){
        for(int k=0;k<n;k++){
                for(int i=0;i<n;i++){
                        for(int j=0;j<n;j++){
                                count++;
                                if(mat[i][k]!=99 && mat[k][j]!=99 && mat[i][k]+mat[k][j]<mat[i][j])
                                        mat[i][j]= mat[i][k]+mat[k][j];}}}}
void tester(){
        printf("\n Enter the number of vertices");
        scanf("%d",&n);
        printf("\n Enter the cost matrix:");
        for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                        scanf("%d",&mat[i][j]);
        floyds(mat,n);
        printf("\n All pair shortest path:\n");
        for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                        if(mat[i][j]==99)
                                printf("INF ");
                        else
                                printf("%d ",mat[i][j]);

                }printf("\n");}
}

void plotter(){
      FILE *fp=fopen("floyds.txt","a");
      for(int k=2;k<=10;k++){
              n=k;
              count=0;
              create(n);
              floyds(mat,n);
              fprintf(fp,"%d\t%d\n",n,count);}
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

	         
	



