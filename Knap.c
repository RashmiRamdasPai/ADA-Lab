#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int t[MAX][MAX],v[MAX],w[MAX],n,m,i,j,k,count=0;

int max(int a,int b){
	return (a>b)?a:b;
}

int knap(){
	for(i=0;i<n+1;i++){
		for(j=0;j<m+1;j++){
			if(i==0||j==0)
			  t[i][j]=0;
			else{
				count++;
				if(j<w[i])
				t[i][j]=t[i-1][j];
			    else
			     t[i][j]=max(t[i-1][j],v[i]+t[i-1][j-w[i]]);
			   
			}
		}
	}
	return t[n][m];
}

void tester(){
	printf("\n Number of items");
	scanf("%d",&n);
	printf("\n Sack capacity");
	scanf("%d",&m);
	printf("Weight \t Value \n");
	for(i=1;i<=n;i++)
	  scanf("%d %d",&w[i],&v[i]);
	printf("\n Max value %d ",knap());
	for(i=0;i<n+1;i++){
		for(j=0;j<m+1;j++)
		  printf("%d  ",t[i][j]);
		printf("\n");
	}
	printf("\n Composition\n");
	for(i=n;i>0;i--){
		if(t[i][m]!=t[i-1][m]){
			printf("%d\t",i);
			m=m-w[i];
		}
	}
	printf("\n");
}

void plotter(){
	FILE *f2 = fopen("knap.txt","a");
	for(k=1;k<=10;k++){
		n=n*2;
		m=m*5;
		for(i=1;i<=n;i++){
			w[i]=rand()%m+1;
			v[i]=rand()%50+1;
		}
		knap();
		fprintf(f2,"%d\t%d\n",n,count);
		
	}
	fclose(f2);
}

int main(){
	int ch;
	printf("\n Enter your choice 1.test 2.plotter \n");
	scanf("%d",&ch);
	switch(ch){
		case 1:tester();
		        break;
		case 2:plotter();
		       break;
		default:printf("Invalid input\n");
	}
	return 0;
}
