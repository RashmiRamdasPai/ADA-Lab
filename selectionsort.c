#include<stdio.h>
#include<stdlib.h>
int count;
int i,j;
void selection(int *arr,int n){
        int pos,temp;
        for(int i=0;i<n-1;i++){
                pos=i;
                for(int j=i+1;j<n-i-1;j++){
                        count++;
                        if(arr[j]<arr[pos])
                                pos=j;
                }
                if(pos!=i){
                        int temp=arr[i];
                        arr[i]=arr[pos];
                        arr[pos]=temp;
                }}}
void tester(){
        int n,*arr;
        arr=(int *)malloc(n*sizeof(int));
        printf("\n Enter the array size");
        scanf("%d",&n);
        printf("\n Enter the array elements");
        for(i=0;i<n;i++)
         scanf("%d",&arr[i]);
        printf("\n Elements after sorting");
        selection(arr,n);
                for(i=0;i<n;i++)
         printf("%d",arr[i]);

}
void plotter(){
        int *arr,n;
        n=10;
        FILE *f1;
        f1=fopen("sel.txt","a");
    while(n<=30000){
        arr=(int *)malloc(n*sizeof(int));
        for(i=0;i<n;i++)
                *(arr+i)=i;
        count=0;

        selection(arr,n);
        fprintf(f1,"%d\t%d\n",n,count);

        if(n<10000)
         n=n*10;
        else
          n=n+10000;
        }
        fclose(f1);

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

