#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int count=0;

int euclid(int m,int n){
        count=0;
        while(n!=0){
                int temp=m%n;
                m=n;
                n=temp;
                count++;}
        return m;
}

int consec(int m,int n){
        count=0;
        int t=m>n?n:m;
        for(int i=t;i>0;i--){
                count++;
                if(m%i ==0){
                        count++;
                        if(n%i ==0)
                                return i;
                }}}
int modified(int m,int n)
{
        if(n==0||m==0)
                return m>n?m:n;
        count=0;
        while(++count && m!=n){
                if(m>n)
                        m-=n;
                else
                        n-=m;
        }
        return n;
}

void tester(){
        int m,n;
        printf("Enter 2 numbers :");
        scanf("%d %d",&m,&n);
        if(m<0 && n<0){
                printf("Cannot find gcd ");
        }
        printf("GCD (euclid):%d\n",euclid(m,n));
        printf("GCD(consec):%d\n",consec(m,n));
         printf("GCD (modified):%d\n",modified(m,n));
}

void plotter(){
        FILE *f1=fopen("euclidbest.txt","a");
        FILE *f2=fopen("euclidworst.txt","a");
        FILE *f3=fopen("consecbest.txt","a");
        FILE *f4=fopen("consecworst.txt","a");
        FILE *f5=fopen("modifiedbest.txt","a");
        FILE *f6=fopen("modifiedworst.txt","a");

        for(int i=10;i<=100;i+=10){
                int min=INT_MAX,max=INT_MIN;
                for(int j=2;j<=i;j++){
                        for(int k=2;k<=i;k++){
                                euclid(j,k);
                                if(count<min)
                                        min=count;
                                if(count>max)
                                        max=count;}}
                fprintf(f1,"%d\t%d\n",i,min);
                fprintf(f2,"%d\t%d\n",i,max);}
        for(int i=10;i<=100;i+=10){
                int min=INT_MAX,max=INT_MIN;
                for(int j=2;j<=i;j++){
                        for(int k=2;k<=i;k++){
                                consec(j,k);
                                if(count<min)
                                        min=count;
                                if(count>max)
                                        max=count;}}
                 fprintf(f3,"%d\t%d\n",i,min);
                fprintf(f4,"%d\t%d\n",i,max);}
         for(int i=10;i<=100;i+=10){
                int min=INT_MAX,max=INT_MIN;
                for(int j=2;j<=i;j++){
                        for(int k=2;k<=i;k++){
                                modified(j,k);
                                if(count<min)
                                        min=count;
                                if(count>max)
                                        max=count;}}
                 fprintf(f5,"%d\t%d\n",i,min);
                fprintf(f6,"%d\t%d\n",i,max);}
}
void main(){
        tester();
        plotter();
}


~                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     ~                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     ~                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     ~                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     ~                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     ~                                                                        
