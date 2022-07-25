//Topological sort
#include<iostream>
using namespace std;
int main()
{
    int v;
    cout<<"Enter number of vertices:-";
    cin>>v;
    int G[v][v],selected[v],indeg[v],count=0,i,j;
    cout<<"Enter adjacency matrix:-";
    for(int i=1;i<=v;i++)
        for(int j=1;j<=v;j++)
        {
            cin>>G[i][j];
        }
    for(int i=1;i<=v;i++)
        selected[i]=0, indeg[i]=0;
    for(int i=1;i<=v;i++)
        for(int j=1;j<=v;j++)
            if(G[j][i]==1)
                indeg[i]+=1;
    while(count<v)
    {
        for(i=1;i<=v;i++)
        {
            if(indeg[i]==0 && selected[i]==0)
            {   
                cout<<i<<"\t";
                selected[i]=1;
            }
            else{
            for(j=1;j<=v;j++)
            {
                if(G[j][i]==1)
                    indeg[i]--;
            }}
        }
        count++;
    }
    return 0;
}