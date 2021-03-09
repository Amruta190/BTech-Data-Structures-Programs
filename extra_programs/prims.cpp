#include<iostream>
using namespace std;
#define infinity 9999
class Prims
{
    public:
    int n,names[10],cost[10][10],visited[10],arr[10];
    void init();
    void prim();
};
void Prims :: init()
{
    int i,j;
    cout<<"Enter no.of nodes : ";
    cin>>n;
    cout<<"Enter names of nodes : ";
    for(i=1;i<=n;i++)
        cin>>names[i];
    cout<<"Enter cost matrix : ";
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            cin>>cost[i][j];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i!=j&&cost[i][j]==0)
                cost[i][j]=infinity;
        }
    }
    for(i=1;i<=n;i++)
        visited[i]=0;
}
void Prims :: prim()
{
    cout<<"\nEdge\tCost\n";
    int i,j,min=infinity,k=0,p,q,sum=0,count=0,x;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i!=j && min>=cost[i][j])
            {
                min=cost[i][j];
                x=i;
            }
        }
    }   
    visited[x]=1;
    while(count<n-1)
    {
        min=infinity;
        p=0,q=0;
        for(i=1;i<=n;i++)
        {
            if(visited[i]==1)
            {
                for(j=1;j<=n;j++)
                {
                    if(visited[j]==0 && cost[i][j])
                    {
                        if(min>cost[i][j])
                        {
                            min=cost[i][j];
                            p=i;
                            q=j;
                        }
                    }
                }
            }
        }
        cout<<names[p]<<"-"<<names[q]<<"\t"<<cost[p][q]<<"\n";
        visited[q]=1;
        arr[k]=cost[p][q]; 
        k++;
        count++;
    }
    cout<<"\nMinimum cost = ";
    for(i=0;i<k;i++)
        sum=sum+arr[i];
    cout<<sum;
}
int main()
{
    Prims p;
    p.init();
    p.prim();
}