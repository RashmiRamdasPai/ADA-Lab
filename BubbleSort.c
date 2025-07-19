#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count;
int i,j;
void bubblesort(int *arr,int n){
	count=0;
	int flag,temp;
	for(i=0;i<n-1;i++){
		flag=0;
		for(j=0;j<n-i-1;j++){
			count++;
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				flag=1;
			}
		}
		if(flag==0)
		  break;
	}
}

void tester(){
	int n,*arr;
	arr=(int *)malloc(n*sizeof(int));
	printf("\n Enter the array size");
	scanf("%d",&n);
	printf("\n Enter the array elements");
	for(i=0;i<n;i++)
	 scanf("%d",&arr[i]);
	printf("\n Elements after sorting");
	bubblesort(arr,n);
		for(i=0;i<n;i++)
	 printf("%d",arr[i]);
	
}
void plotter(){
	int *arr,n;
	n=10;
	FILE *f1,*f2,*f3;
	f1=fopen("bubblebest.txt","w");
	f2=fopen("bubbleavg.txt","w");
	f3=fopen("bubbleworst.txt","w");
    while(n<=30000){
    	arr=(int *)malloc(n*sizeof(int));
    	for(i=0;i<n;i++)
    		*(arr+i)=i+1;
    	bubblesort(arr,n);
    	fprintf(f1,"%d\t%d\n",n,count);
    	for(i=0;i<n;i++)
    		*(arr+i)=rand()%n;
    	bubblesort(arr,n);
    	fprintf(f2,"%d\t%d\n",n,count);
    	for(i=0;i<n;i++)
    		*(arr+i)=n-i;
    	bubblesort(arr,n);
    	fprintf(f3,"%d\t%d\n",n,count);
    	if(n<10000)
    	 n=n*10;
    	else
    	  n=n+10000;
	}
	fclose(f1);
	fclose(f2);
	fclose(f3);	
}

void main(){
	int ch;
	for(;;){
		printf("\n1.Test 2.Plot 3.Exit");
		printf("\n Enter your choice");
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


