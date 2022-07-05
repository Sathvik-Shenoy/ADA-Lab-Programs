#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
int binary(int *a,int n,int key)
{
    int c=0,f=0,l=n;
    while(f<l)
    {
        int mid=(f+l)/2;
        c++;
        if(a[mid]==key)
            break;
        else if(a[mid]<key)
            f=mid+1;
        else
            l=mid-1;
    }
    return c;
}
void main()
{
    FILE *f1;
    f1=fopen("binary.txt","w");
    srand(time(0));
    int i,j,key,count;
    for(i=1;i<=100;i++)
    {
        int a[i];
        for(j=0;j<i;j++)
        {
            a[j]=100+(2*j);
        }
        key=a[i/2];
        count=binary(a,i,key);
        fprintf(f1,"%d\t%d\n",i,count);
    }
}