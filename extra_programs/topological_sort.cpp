#include<iostream>
#include"StackHeader.h"
using namespace std;
class TS
{
    public:
    int n,adj[100][100],visited[10],names[11],visited1[11],stack[11];
    void init();
    void initTS();
    void Tsort(int);
    int isCyclic();
    int Cyclic(int);
};
int TS :: Cyclic(int i)
{
    int j;
    if(visited1[i]==0)
    {
        visited1[i]=1;
        stack[i]=1;
        for(j=1;j<=n;j++)
        {
            if(adj[i][j]==1)
            {
                if(!visited1[j] && Cyclic(j))
                    return 1;
                else if(stack[j])
                    return 1;
            }
        }
    }
    stack[i]=0;
    return 0;
}
int TS :: isCyclic()
{
    int i;
    for(i=1;i<=n;i++)
    {
        visited1[i]=0;
        stack[i]=0;
    }
    for(i=1;i<=n;i++)
        if(Cyclic(i))
            return 1;
    return 0;
}
void TS :: init()
{
    int i,j;
    cout<<"Enter no.of nodes : ";
    cin>>n;
    cout<<"Enter names of nodes : ";
    for(i=1;i<=n;i++)
        cin>>names[i];
    cout<<"Enter adjacency matrix : ";
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            cin>>adj[i][j];
    if(isCyclic())
    {
        cout<<"Cycle exists in graph!!!";
        exit(0);
    }
    cout<<"Topological sort is : ";
}
void TS :: initTS()
{
    int i,j;
    for(i=1;i<=n;i++)
        visited[i]=0;
    for(i=1;i<=n;i++)
    {
        if(visited[i]==0)
            Tsort(i);
    }
    while(!s.isEmpty())
        cout<<s.pop()<<" ";
}
void TS :: Tsort(int k)
{
    int i;
    visited[k]=1;
    for(i=1;i<=n;i++)
    {
        if(adj[k][i]==1 && visited[i]==0)
            Tsort(i);
    }
    s.push(names[k]);
}
int main()
{
    TS t;
    t.init();
    t.initTS();
}