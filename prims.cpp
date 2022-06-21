#include<iostream>
using namespace std;
int main()
{
    int min,no_of_edges=0,x,y,v,i,j,s=0;
    cout<<"\nEnter the no. of vertices:";

    cin>>v;
    int G[v][v],selected[v];
    cout<<"\nEnter the cost adjacency matrix:\n";

    for(i=0;i<v;i++) 

        for(j=0;j<v;j++) 
            cin>>G[i][j];
    for(i=0;i<v;i++)
        selected[i]=false;
    selected[0]=true;
    while(no_of_edges<v-1)
    {
        min=10000;
        x=0; y=0;
        for(i=0;i<v;i++)
        {
            if(selected[i]==true)
            {
                for(j=0;j<v;j++)
                {
                    if(selected[j]==false && G[i][j]!=0)
                    {
                        if(min>G[i][j])
                        {
                            min=G[i][j];
                            x=i;
                            y=j;
                        }
                    }
                }
            }
        }
        cout<<x<<" - "<<y<<" : "<<G[x][y]<<"\n";
        s=s+G[x][y];
        selected[y]=true;
        no_of_edges++;
    }
    cout<<"Minimun cost is "<<s;
    return 0;
}