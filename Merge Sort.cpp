#include<iostream>
#include<ctime>
using namespace std;
void merge(int a[],int f,int mid,int l)
{
    int n1=mid-f+1;
    int n2=l-mid;
    int t1[10],t2[10],i=0,j=0,k=f,c[10];
    for(int i=0;i<n1;i++)
        t1[i]=a[i+f];
    for(int i=0;i<n2;i++)
        t2[i]=a[mid+1+i];
    i=0,j=0;
    while(i<n1 && j<n2)
    {
        if(t1[i]<=t2[j])
            c[k++]=t1[i++];
        else
            c[k++]=t2[j++];
    }
    while(i<n1)
        c[k++]=t1[i++];
    while(j<n2)
        c[k++]=t2[j++];
    for(i=0;i<=l;i++)
        a[i]=c[i];
}
void mergesort(int a[],int f,int l)
{   
    if(f<l)
    {
        int mid=(f+l)/2;
        mergesort(a,f,mid);
        mergesort(a,mid+1,l);
        merge(a,f,mid,l);
    }
}
int main()
{
     int n=10000;
    int i,k=1;
    double time;
    while(k<=50)
    {
        int a[n];
        for(i=0;i<n;i++)
            a[i]=rand()%1000;
        clock_t start=clock();
        mergesort(a,0,n);
        clock_t end=clock();
        time=(double)(end-start)/CLOCKS_PER_SEC;
        cout<<n<<"\t"<<time<<"\n";
        n=n+10000;
        k++;
    }
    return 0;  
}