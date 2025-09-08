
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int t[MAX][MAX],v[MAX],w[MAX],i,j,k;
int n,m;
int count=0;
int max(int a,int b){
	return (a>b)?a:b;
}
int knap(){
	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++){
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
int tester(){
	printf("\n Enter the number of items");
	scanf("%d",&n);
    printf("\n Enter the sack capacity");
    scanf("%d",&m);
    printf("\n Enter the weight and value\n");
    for(i=1;i<=n;i++)
      scanf("%d %d",&w[i],&v[i]);
    printf("\n Maximum profit is %d ",knap());
    for(i=0;i<=n;i++){
	
     for(j=0;j<=m;j++)
      printf("%d ",t[i][j]);
      printf("\n");
  }
    printf("\n Composition :\n");
    for(i=n;i>0;i--){
    	if(t[i][m]!=t[i-1][m]){
		
    	  printf("%d ",i);
    	m=m-w[i];}
	}}
void plotter(){
	FILE *f=fopen("knap1.txt","a");
	for(k=1;k<=10;k++){
		n=k*2;
		m=k*5;
		for(i=1;i<=n;i++)
		{
			w[i]=rand()%m+1;
			v[i]=rand()%50+1;
		}
	
	count=0;
	knap();
	fprintf(f,"%d\t%d\n",n,count);
}
fclose(f);
}
    
int main(){
	int ch;
	for(;;){
	
	printf("\n Enter your choice 1.test 2.plotter 3.Exit \n");
	scanf("%d",&ch);
	switch(ch){
		case 1:tester();
		        break;
		case 2:plotter();
		       break;
		case 3:exit(0);
		default:printf("Invalid input\n");
	}}
	return 0;
}
