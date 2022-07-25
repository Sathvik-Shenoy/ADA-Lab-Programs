//djikstras
#include<iostream>
using namespace std;
int v;
int G[9][9],value[9];
bool selected[9];
int main()
{
    int u,i,j,count=0,ver,minn;
    cout<<"Enter number of vertices:-";
    cin>>v;
    for(i=1;i<=v;i++)
        selected[i]=false,value[i]=999;
    cout<<"Enter adjacency matrix:-";
    for(i=1;i<=v;i++)
        for(j=1;j<=v;j++)
        {    
            cin>>G[i][j];
            if(G[i][j]==0)
                G[i][j]=999;
        } 
    cout<<"Enter starting vertex:-";
    cin>>ver;  
    for(i=1;i<=v;i++)
    {
        selected[i]=0;
        value[i]=G[ver][i];
    }
    value[ver]=0;
    selected[ver]=true;
    while(count<v)
    {
        minn=999;
        for(i=1;i<=v;i++)
            if(value[i]<minn && selected[i]==0)
            {
                minn=value[i];
                ver=i;
            }
        selected[ver]=true;
        for(i=1;i<=v;i++)
            if(value[i]>value[ver]+G[ver][i])
                value[i]=value[ver]+G[ver][i];
        count++;
    }
    cout<<"Vertex \tDistance from source\n";
    for(i=1;i<=v;i++)
        cout<<i<<"\t"<<value[i]<<"\n";
    return 0;
}