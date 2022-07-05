#include<iostream>
using namespace std;
int v;
int select_min_vertex(bool selected[],int value[])
{
    int minn=999,vertex;
    for(int i=0;i<v;i++)
    
        if(selected[i]==false && value[i]<=minn)
        {
            minn=value[i];
            vertex=i;
        }
    
    return vertex;
}
int main()
{
    int u;
    cout<<"Enter number of vertices:-";
    cin>>v;
    int G[v][v],i,j,value[v];
    bool selected[v];
    for(i=0;i<v;i++)
        selected[i]=false,value[i]=999;
    cout<<"Enter adjacency matrix:-";
    for(i=0;i<v;i++)
        for(j=0;j<v;j++)
            cin>>G[i][j];
    value[0]=0;
    for(i=0;i<v-1;i++)
    {
        u=select_min_vertex(selected,value);
        selected[u]=true;
        for(j=0;j<v;j++)
        {
            if(!selected[j] && G[u][j] && value[u]!=999 && value[u]+G[u][j]<value[j])
            {
                value[j]=value[u]+G[u][j];
            }
        }
    }
    cout<<"Vertex \tDistance from source\n";
    for(i=0;i<v;i++)
        cout<<i<<"\t"<<value[i]<<"\n";
    return 0;
}