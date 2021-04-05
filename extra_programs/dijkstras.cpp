#include<iostream>
using namespace std;
#define infinity 99
class dijkstras
{
    public:
    int n,cost[10][10],visited[10],dis[10],names[10],source,predecesser[10];
    void init();
    void distance();
    void distance_next();
    int minimum(int []);
    int min(int,int);
};
int dijkstras :: min(int x,int y)
{
    return (x<=y)?x:y;
}
int dijkstras :: minimum(int dis[])
{
    int i,u;
    int min=infinity;
    for(i=2;i<=n;i++)
    {
        if(min>=dis[i]&&visited[i]==0)
        {
            min=dis[i];
            u=i;
        }
    }
    return u;
}
void dijkstras :: init()
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
    for(i=1;i<=n;i++)
        dis[i]=0;
    for(i=1;i<=n;i++)
        predecesser[i]=1;
}
void dijkstras :: distance()
{
    int i,j;
    cout<<"Enter source vertex : ";
    cin>>source;
    for(i=1;i<=n;i++)
    {
        if(source==names[i])
        {
            visited[i]=1;
            for(j=2;j<=n;j++)
                dis[j]=cost[i][j];
            distance_next();
        }
    }
}
void dijkstras :: distance_next()
{
    int i,u,j;
    for(j=1;j<n;j++)
    {
        u=minimum(dis);
        visited[u]=1;
        for(i=1;i<=n;i++)
        {
            if(visited[i]==0)
            {
                int k=min(dis[i],dis[u]+cost[u][i]);
                if(k==dis[u]+cost[u][i])
                    predecesser[i]=u;
                dis[i]=k;
            }
        }  
    }
}
int main()
{
    int i,j,arr[10]={0},k,p;
    dijkstras d;
    d.init();
    d.distance();
    cout<<"\nSource\tDestination\tShortest-distance\tShortest-path";
    for(i=2;i<=d.n;i++)
    {
        cout<<"\n"<<" "<<d.source<<"\t\t";
        cout<<d.names[i]<<"\t";
        cout<<"\t"<<d.dis[i]<<"\t\t";
        cout<<d.source;
        j=i;k=1;arr[0]=j;
        while(d.predecesser[j]!=1)
        {
            arr[k]=d.predecesser[j];
            k++;
            j=d.predecesser[j];
        }
        for(p=k-1;p>=0;p--)
            cout<<"-"<<arr[p];
    }
}