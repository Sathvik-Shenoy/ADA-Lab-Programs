#include<iostream>
using namespace std;
int w[20],x[20],n,sum=0,m,b=0;
void sumofsub(int s,int k,int r)
{
        x[k]=1;   
        if(s+w[k]==m)
        {
            cout<<"\nSubset "<<b++<<"\n";
            for(int j=1;j<=k;j++)
                if(x[j]==1)
                    cout<<w[j]<<" ";
        }
        else if(s+w[k]+w[k+1]<=m)
            sumofsub(s+w[k],k+1,r-w[k]);
        if((s-w[k]+r>=m)&& (s+w[k+1])<=m)
        {   
            x[k]=0;
            sumofsub(s,k+1,r-w[k]);
        }
}
int main()
{
    
    cout<<"Enter the number of weights:-";
    cin>>n;
    
    cout<<"Enter the weights";
    for(int i=1;i<=n;i++)
    {
        cin>>w[i];
        sum=sum+w[i];
    }    
    cout<<"Enter maximum weight:-";
    cin>>m;
    sumofsub(0,1,sum);
    return 0;
}