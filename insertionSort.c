#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count,i,j;

void insertionsort(int *arr,int n){
	count=0;
	for(i=1;i<n;i++){
		int value=arr[i];
		j=i-1;
		while(j>=0 && ++count && value<arr[j]){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=value;
	}
}

void plotter(){
	int *arr,n;
	srand(time(NULL));
	FILE *f1,*f2,*f3;
	f1=fopen("insertionbest.txt","a");
	f2=fopen("insertionavg.txt","a");
	f3=fopen("insertionworst.txt","a");
	n=10;
	while(n<=30000){
		arr=(int *)malloc(n*sizeof(int));
		for(i=0;i<n;i++){
			*(arr+i)=i+1;
		
		}
		insertionsort(arr,n);
		fprintf(f1,"%d\t%d\n",n,count);
		for(j=0;j<n;j++)
		  *(arr+j)=rand()%n;
		  insertionsort(arr,n);
		fprintf(f2,"%d\t%d\n",n,count);
		for(j=0;j<n;j++)
		  *(arr+j)=n-j;
		  insertionsort(arr,n);
		fprintf(f3,"%d\t%d\n",n,count);
		if(n<10000)
		  n=n*10;
		else
		  n=n+10000;
		free(arr);
	}
	fclose(f1);
	fclose(f2);
	fclose(f3);
}
	void tester(){
		int n,*arr;
		arr=(int *)malloc(n*sizeof(int));
		printf("\n Enter the size of the array");
		scanf("%d",&n);
		printf("\n Enter the array elements");
		for(i=0;i<n;i++)
		  scanf("%d",&arr[i]);
		insertionsort(arr,n);
		for(i=0;i<n;i++)
		  printf("%d",arr[i]);
	}

void main(){
	int ch;
	for(;;){
		printf("\n Enter your choice 1.Test 2.Plot 3.Exit");
		scanf("%d",&ch);
		switch(ch){
			case 1:tester();
			        break;
		  case 2:plotter();
		         break;
		  case 3:exit(0);
		  
		}
	}
}
	
