#include<iostream>
using namespace std;
int min(int i,int j)
{
    if(i<j)
        return i;
    return j;
}
int main()
{
    int v;
    cout<<"Enter the number of vertices:-";
    cin>>v;
    int a[v][v],d[v][v],i,j,k;
    cout<<"Enter the adjacency matrix:-";
    for(i=0;i<v;i++)
        for(j=0;j<v;j++)
        {    
            cin>>a[i][j];
            d[i][j]=a[i][j];
        }
    for(k=0;k<v;k++)
        for(i=0;i<v;i++)
            for(j=0;j<v;j++)
                if(d[i][j]==1 || d[i][k]==1 && d[k][j]==1)
                    d[i][j]=1;
    cout<<"Final distance matrix is\n";
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
            cout<<d[i][j]<<"\t";
        cout<<"\n";
    }
}