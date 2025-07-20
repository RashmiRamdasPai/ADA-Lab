#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count;
int i,j;
void merge(int *arr,int beg,int mid,int end){
	int i,j,k;
	int n1=(mid-beg)+1;
	int n2=end-mid;
	int left[n1],right[n2];
	for(i=0;i<n1;i++)
	  left[i]=arr[beg+i];
	for(j=0;j<n2;j++)
	   right[j]=arr[mid+j+1];
	i=0;
	j=0;
	k=beg;
	while(i<n1 && j<n2){
		count++;
		if(left[i]<=right[j])
		  arr[k]=left[i++];
		else
		  arr[k]=right[j++];
		k++;
	}
	while(i<n1)
	  arr[k++]=left[i++];
	while(j<n2)
	  arr[k++]=right[j++];
}

void mergesort(int *arr,int beg,int end){
	if(beg<end){
		int mid=(beg+end)/2;
		mergesort(arr,beg,mid);
		mergesort(arr,mid+1,end);
		merge(arr,beg,mid,end);
	}
}

void worst(int arr[],int beg,int end){
		if(beg<end){
		int mid=(beg+end)/2;
		int i,j,k;
		int n1=(mid-beg)+1;
		int n2=(end-beg);
		int a[n1],b[n2];
		for(i=0;i<n1;i++)
		  arr[i]=arr[(2*i)];
		for(j=0;j<n2;j++)
		   b[j]=arr[(2*j)+1];
		worst(a,beg,mid);
		worst(b,mid+1,end);
		for(i=0;i<n1;i++)
		   arr[i]=a[i];
		for(j=i;j<n2;j++)
		  arr[j+1]=b[j];
}}
void tester(){
	int n,*arr;
	
	printf("\n Enter the size of the array");
	scanf("%d",&n);
	arr=(int *)malloc(n*sizeof(int));
	printf("\n Enter the array elements");
	for(i=0;i<n;i++)
	  scanf("%d",&arr[i]);
	mergesort(arr,0,n-1);
	printf("\n The array elements after sorting");
	for(i=0;i<n;i++)
	  printf("%d ",arr[i]);
}

void plotter(){
	int *arr,n=2;
	srand(time(NULL));
	FILE *f1=fopen("mergebest.txt","a");
	FILE *f2=fopen("mergeavg.txt","a");
	FILE *f3=fopen("mergeworst.txt","a");
	while(n<=1024){
		arr=(int *)malloc(n*sizeof(int));
		for(i=0;i<n;i++)
		  arr[i]=i+1;
		  count=0;
		mergesort(arr,0,n-1);
		fprintf(f1,"%d\t%d\n",n,count);
		for(i=0;i<n;i++)
		  arr[i]=rand()%n;
		  count=0;
		mergesort(arr,0,n-1);
		fprintf(f2,"%d\t%d\n",n,count);
		worst(arr,0,n-1);
		count=0;
		
		mergesort(arr,0,n-1);
		fprintf(f3,"%d\t%d\n",n,count);
	
		free(arr);
		n=n*2;
	}
	
}
void main(){
	int ch;
	for(;;){
		printf("\n Enter your choice 1.test 2.plot 3.exit");
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
