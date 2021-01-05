//Binary tree traversals
#include<iostream>
using namespace std;
#include<math.h>
int a[100];
void inorder(int i)
{
    if(a[2*i]!=-1)
        inorder(2*i);
    cout<<a[i]<<" ";
    if(a[2*i+1]!=-1)
        inorder(2*i+1);
}
void preorder(int i)
{
    cout<<a[i]<<" ";
    if(a[2*i]!=-1)
        preorder(2*i);
    if(a[2*i+1]!=-1)
        preorder(2*i+1);
}
void postorder(int i)
{
    if(a[2*i]!=-1)
        postorder(2*i);
    if(a[2*i+1]!=-1)
        postorder(2*i+1);
    cout<<a[i]<<" ";
}
int main()
{
    int i,n,nodes_n,nodes_n1;
    cout<<"Enter no.of levels of tree : ";
    cin>>n;
    nodes_n=pow(2,n)-1;
    nodes_n1=pow(2,n+1)-1;
    for(i=1;i<=nodes_n1;i++)
        a[i]=-1;
    cout<<"Enter "<<nodes_n<<" nodes\n";
    for(i=1;i<=nodes_n;i++)
        cin>>a[i];
    cout<<"Inorder : ";
    inorder(1);
    cout<<"\n";
    cout<<"Preorder : ";
    preorder(1);
    cout<<"\n";
    cout<<"Postorder : ";
    postorder(1);
}