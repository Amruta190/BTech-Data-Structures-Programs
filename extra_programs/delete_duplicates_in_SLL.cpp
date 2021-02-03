#include<iostream>
using namespace std;
class Node
{
    public:
    int key;
    Node *addr;
};
class SLL
{
    Node *front=NULL,*rear=NULL;
    public:
    void insertatend(Node*);
    void delete_duplicates(SLL);
    void print();
};
void SLL ::insertatend(Node *tmp)
{
    if(front==NULL&&rear==NULL)
        front=rear=tmp;
    else
    {
        rear->addr=tmp;
        rear=tmp;
    }  
}
void SLL :: delete_duplicates(SLL l1)
{
    Node *i=l1.front;
    if(i==NULL)
        return;
    while(i->addr!=NULL)
    {
        if(i->key==i->addr->key)
            i->addr=i->addr->addr;
        else
            i=i->addr;
    }
}
void SLL :: print()
{
    if(front==NULL)
        cout<<"Empty";
    else
    {
        Node *tmp=NULL;
        tmp=front;
        while(tmp!=NULL)
        {
            cout<<tmp->key<<" ";
            tmp=tmp->addr;
        }
    }
}
int main()
{
    int n,i;
    SLL l1;
    Node *tmp=NULL;
    cout<<"Enter the no.of values into the list : ";
    cin>>n;
    cout<<"Enter the elements into the list : ";
    for(i=0;i<n;i++)
    {
        tmp=new Node();
        cin>>tmp->key;
        tmp->addr=NULL;
        l1.insertatend(tmp);
    }
    l1.delete_duplicates(l1);
    cout<<"The final list is : ";
    l1.print();
}
