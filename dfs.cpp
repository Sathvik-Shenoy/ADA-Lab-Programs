//dfs
#include<iostream>
using namespace std;
int G[9][9],v,selected[9];
int dfs(int ver)
{
    selected[ver]=1;
    for(int i=1;i<=v;i++)
            if(selected[i]==0 && G[ver][i]==1)
                dfs(i);
    for(int i=1;i<=v;i++)
        if(selected[i]==0)
            return 0;
    return 1;
}
int main()
{
    cout<<"Enter the number of vertices:-";
    cin>>v;
    int i,j,k,ver,f=0;
    cout<<"Enter the adjacency matrix:-";
    for(i=1;i<=v;i++)
        for(j=1;j<=v;j++)
        {    
            cin>>G[i][j];
        }
    for(i=1;i<=v;i++)
        selected[i]=0;
    cout<<"Enter starting vertex:-";
    cin>>ver;
    f=dfs(ver);
    if(f==0)
        cout<<"Graph is not connected";
    else
        cout<<"Graph is connected";
    return 0;
}