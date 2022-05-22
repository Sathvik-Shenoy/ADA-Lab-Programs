#include<iostream>
using namespace std;
int partition(int a[],int f,int l)
{
    int pivot=a[f];
    int i=f;
    int j=l,t;
    while(i<j)
    {
        do
        {
            i++;
        }while(a[i]<=pivot);
        do
        {
            j--;
        }while(a[j]>pivot);
        if(i<j)
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    t=a[f];
    a[f]=a[j];
    a[j]=t;
    return j;
}
void quicksort(int a[],int f,int l)
{
    if(f<l)
    {
    int j=partition(a,f,l);
    quicksort(a,f,j);
    quicksort(a,j+1,l);
    }
}
int main()
{
    int a[]={4,3,2,1};
    quicksort(a,0,4);
    for(int i=0;i<4;i++)
        cout<<a[i];
    return 0;
}
