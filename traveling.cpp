//travel
#include<iostream>
int v;
int G[9][9],cost=0,prev_vertex,start;
bool selected[9];
using namespace std;
int find_next_node(int ver)
{
    int minn=999,min_vertex=-1;
    for(int i=1;i<=v;i++)
        if(selected[i]==false && minn>G[ver][i] && G[ver][i]!=0)
        {
            minn=G[ver][i];
            min_vertex=i;
            prev_vertex=i;
        }
    if(minn!=999)
    	cost+=minn; 
    return min_vertex;
}
void TSP(int ver)
{
    selected[ver]=1;
    int n;
    cout<<ver<<" ";
    n=find_next_node(ver);
    if(n==-1)
    {
        int v=0;
        cost+=G[prev_vertex][1];
        cout<<start;
    }
    else
        TSP(n);
}
int main()
{
    int i,j,ver;
    cout<<"Enter number of vertices:-";
    cin>>v;
    for(i=1;i<=v;i++)
        selected[i]=false;
    cout<<"Enter adjacency matrix:-";
    for(i=1;i<=v;i++)
        for(j=1;j<=v;j++)
            cin>>G[i][j];
    cout<<"Enter starting vertex:-";
    cin>>ver;
    start=ver;
    TSP(ver);
    cout<<"Total cost is "<<cost;
    return 0;
}
