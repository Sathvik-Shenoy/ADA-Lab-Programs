/* Sequential search and Binary search algorithms for searching an element in the 
list.*/
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
int linearsearch(int *,int,int);
int binarysearch(int *,int,int);
void main()
{
    int n,a[100],b[100],i,j,best_count=0,worst_count=0,av_count=0,b_key,w_key,a_key;
    FILE *fp1,*fp2,*fp3,*fp4,*fp5,*fp6;
    fp1=fopen("bcase_llsearch.txt","w");
    fp2=fopen("wcase_llsearch.txt","w");
    fp3=fopen("acase_llsearch.txt","w");
    srand(time(0));
    for(i=1;i<100;i++)
    {
        n=i;
        for(j=0;j<n;j++)
        {
            a[j]=rand()%100;
        }
        b_key=a[0];
        best_count=linearsearch(a,i,b_key);
        fprintf(fp1,"%d\t%d\n",n,best_count);
        a_key=a[i/2];
        av_count=linearsearch(a,i,a_key);
        fprintf(fp3,"%d\t%d\n",n,av_count);
        w_key=a[i];
        worst_count=linearsearch(a,i,w_key);
        fprintf(fp2,"%d\t%d\n",n,worst_count);
    }
    //C program to implement to implement binary search
    fp4=fopen("bcase_bsearch.txt","w");
    fp5=fopen("wcase_bsearch.txt","w");
    fp6=fopen("acase_bsearch.txt","w");
    for(i=1;i<100;i++)
    {
        n=i;
        for(j=0;j<n;j++)
        {
            b[j]=100+(2*j);
        }
        b_key=a[i/2];
        best_count=binarysearch(b,i,b_key);
        fprintf(fp4,"%d\t%d\n",n,best_count);
        a_key=a[i/4];
        av_count=binarysearch(b,i,a_key);
        fprintf(fp5,"%d\t%d",n,av_count);
        w_key=a[0];
        worst_count=binarysearch(b,i,w_key);
        fprintf(fp6,"%d\t%d\n",n,worst_count);
    }
}
int linearsearch(int *a,int n,int key)
{
    int i=0,c=0,flag=0;
    for(i = 0; i < n ; i++){
        c++;
        if(a[i] == key){
        flag=1;
        break;
        }
    }
    return c;
}
int binarysearch(int *a,int n,int key)
{
    int top = n-1,bot = 0, mid = (top+bot)/2,c,flag=0;
    while(bot<=top){
        c++;
        if(a[mid] == key){
            flag=1;
            break;
        }else if(a[mid]>key)
            top = mid-1;
        else
            bot = mid+1;
        mid = (top+bot)/2;
    }
}