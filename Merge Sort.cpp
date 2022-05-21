#include<iostream>
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
    int i=0,j=0;
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
    int a[]={4,3,2,1};
    mergesort(a,0,3);
    for(int i=0;i<4;i++)
        cout<<a[i];   
}