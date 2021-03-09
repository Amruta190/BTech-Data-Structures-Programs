#include<iostream>
using namespace std;
#define infinity 999
class Kruskals
{
    public:
    int n,names[10],cost[10][10],visited[10],src[100],des[100],wei[100],k=0,parent[10];
    void init();
    void kruskal();
    void sort();
    void swap(int*,int*);
};
void Kruskals :: init()
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
            if(i!=j && cost[i][j]==0)
                cost[i][j]=infinity;
        }
    }
    for(i=1;i<=n;i++)
        visited[i]=0;
}
void Kruskals :: kruskal()
{
    int i,j,count=0,p=0,min_cost=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i!=j && cost[i][j]!=infinity)
            {
                src[++k]=names[i];
                des[k]=names[j];
                wei[k]=cost[i][j];
            }
        }
    }
    sort();
    for(i=1;i<=k;i++)
    {
        for(j=i+1;j<=k;j++)
        {
            if(src[i]==des[j] && des[i]==src[j])
            {
                for(p=j;p<=k;p++)
                {
                    src[p]=src[p+1];
                    des[p]=des[p+1];
                    wei[p]=wei[p+1];
                }
                k--;
            }
        }
    }
    cout<<"After sorting edge weights\n";
    cout<<"Src   Des   Weight\n";
    for(i=1;i<=k;i++)
    {
        cout<<src[i]<<"\t"<<des[i]<<"\t"<<wei[i]<<"\n";
    }
    for(i=1;i<=n;i++)
        parent[names[i]]=-1;
    cout<<"Edge\tCost\n";
    i=1;
    while(count<n-1)
    {
        if(parent[des[i]]==-1)
        {
            parent[des[i]]=src[i];
            cout<<src[i]<<"-"<<des[i]<<"\t"<<wei[i]<<"\n";
            min_cost=min_cost+wei[i];
            count++;
        }
        i++;
    }
    cout<<"Minimum Cost = "<<min_cost;
}
void Kruskals :: sort()
{
    int i,j;
    for(i=1;i<=k;i++)
    {
        for (j=1;j<=k-i;j++)
        {
            if (wei[j] > wei[j+1]) 
            {
                swap(&wei[j],&wei[j+1]);
                swap(&src[j],&src[j+1]);
                swap(&des[j],&des[j+1]);
            }
        }
    }
}
void Kruskals :: swap(int *a, int *b)
{   
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int main()
{
    Kruskals k;
    k.init();
    k.kruskal();
}