#include<iostream>
#include"bfsQueue.cpp"
using namespace std;
class FS
{
    int n,adj[20][20],visited[20];
    char first,names[20]; 
    public:
    void initial();
    void dfslogic();
    void dfs(int k);
    void bfslogic(Queue q1);
    void bfs(int k,Queue q1);
};
void FS :: initial()
{
    int i,j;
    cout<<"\nEnter the no.of nodes: ";
    cin>>n;
    cout<<"Enter the names of the nodes: ";
    for(i=1;i<=n;i++)
        cin>>names[i];
    cout<<"Enter the adjacency matrix having "<<n<<" rows and columns\n";
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>adj[i][j];
        }
    }
    for(i=1;i<=n;i++)
        visited[i]=0;
}
void FS :: dfslogic()
{
    cout<<"Enter the starting node : ";
    cin>>first;
    for(int i=1;i<=n;i++)
    {
        if(first==names[i])
        {
            visited[i]=1;
            cout<<names[i]<<" ";
            dfs(i);
            break;
        }
    }
}
void FS :: dfs(int k)
{
    for(int i=1;i<=n;i++)
    {
        if((adj[k][i]==1) && (visited[i]==0))
        {
            visited[i]=1;
            cout<<names[i]<<" ";
            dfs(i);
        }
    }
}
void FS :: bfslogic(Queue q1)
{
    cout<<"Enter the starting node : ";
    cin>>first;
    for(int i=1;i<=n;i++)
    {
        if(first==names[i])
        {
            visited[i]=1;
            cout<<names[i]<<" ";
            bfs(i,q1);
            break;
        }
    }
}
void FS :: bfs(int k, Queue q1)
{
    for(int i=1;i<=n;i++)
    {
        if((adj[k][i]==1) && (visited[i]==0))
        {
            visited[i]=1;
            cout<<names[i]<<" ";
            q1.insert(i);
        }
    }
    if(q1.isEmpty()!=1)
        bfs(q1.delete1(),q1);
}
int main()
{
    FS f1;
    Queue q1;
    while(true)
    {
        cout<<"\nSelect an option :\n1. Depth First Search\n2. Breadth First Search\n3. Exit\n";
        int n1;
        cin>>n1;
        switch(n1)
        {
            case 1: f1.initial();
                    f1.dfslogic();
                    break;
            case 2: f1.initial();
                    f1.bfslogic(q1);
                    break;
            case 3: exit(0);
        }
    }
}