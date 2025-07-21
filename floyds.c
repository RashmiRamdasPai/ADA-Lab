#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>

int n,opcount,dist[100][100];
int i,j,k;
int floyds(int mat[n][n],int n){
	opcount=0;
	for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
	     if(mat[i][j]==-1)
	        dist[i][j]=INT_MAX;
	     else
	        dist[i][j]=mat[i][j];
	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			int temp=dist[i][k];
		for(j=0;j<n;j++){
			if(dist[i][j]>temp){
				opcount++;
			if(dist[k][j]!=INT_MAX && dist[i][j]>temp+dist[k][j])
			  dist[i][j]=temp+dist[k][j];
			  			}
		}
		}
	}}
void tester(){
printf("\n Enter the number of vertices");
scanf("%d",&n);
int matrix[n][n];
printf("\n Enter the matrix");
for(i=0;i<n;i++)
  for(j=0;j<n;j++)
     scanf("%d",&matrix[i][j]);
floyds(matrix,n);
for(i=0;i<n;i++)
 {
 	for(j=0;j<n;j++)
 	  printf("%d",dist[i][j]);
 	printf("\n");
 }
	
			
		}
		

	

	         
	



void plotter(){
	FILE *f1 =  fopen("floyd.txt","a");
	
	for(k=2;k<12;k++){
		n=k;
		int mat[n][n];
	  for(i=0;i<n;i++)
	  	for(j=0;j<n;j++)
	  		if(i!=j)
	  		  mat[i][j]=rand()%n;
	  		else 
	  		  mat[i][j]=0;
		  floyds(mat,n);
		  
		fprintf(f1,"%d\t%d\n",n,opcount);
	  
	}
	fclose(f1);
	
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
}}
