#include<iostream>
using namespace std;
class Node
{
    public:
    int key;
    Node *addr;
};
class LinkedList
{
    Node *head=NULL;
    public:
    void insertatend(Node *);
    void interchange();
    void print();
};
void LinkedList :: insertatend(Node *tmp)
{
    Node *p=head;
    if(head==NULL)
    {
        head=tmp;
        tmp->addr=head;
    }
    else
    {
        while(p->addr!=head)
            p=p->addr;
        p->addr=tmp;
        tmp->addr=head;
    }
}
void LinkedList :: interchange()
{
    cout<<"Enter the key value of node that should swap : ";
    int k,flag=0;
    cin>>k;
    Node *tmp=head->addr,*tmp1=NULL,*tmp2=NULL;
    if(head->key==k)
    {
        tmp1=head->addr;
        head->addr=tmp1->addr;
        tmp1->addr=head;
        tmp2=head;
        while(tmp2->addr!=head)
            tmp2=tmp2->addr;
        tmp2->addr=tmp1;
        head=tmp1;
    }
    else
    {
        while(tmp->addr->addr!=head)
        {
            if(tmp->key==k)
            {
                tmp1=tmp->addr;
                tmp->addr=tmp1->addr;
                tmp1->addr=tmp;
                tmp2=head;
                while(tmp2->addr!=tmp)
                    tmp2=tmp2->addr;
                tmp2->addr=tmp1;
                flag=1;
                break;
            }
            tmp=tmp->addr;
        }
        if(flag==0)
        {
            tmp1=tmp->addr;
            if(tmp->key==k)
            {
                tmp->addr=tmp1->addr;
                tmp1->addr=tmp;
                tmp2=head;
                while(tmp2->addr!=tmp)
                    tmp2=tmp2->addr;
                tmp2->addr=tmp1;
            }
            else if(tmp1->key==k)
            {
                tmp1->addr=head->addr;
                head->addr=tmp1;
                tmp->addr=head;
                head=tmp1;
            }
        }
    }
}
void LinkedList :: print()
{
    Node *temp=head;
    if(temp==NULL)
        cout<<"No nodes available";
    else if(temp->addr==head)
        cout<<temp->key;
    else
    {
        while(temp->addr!=head)
        {
            cout<<temp->key<<" ";
            temp=temp->addr;
        }
        cout<<temp->key;
    }
}
int main()
{
    int n,i;
    LinkedList l1;
    Node *tmp=NULL;
    cout<<"Enter no.of nodes : ";
    cin>>n;
    cout<<"Enter nodes: ";
    for(i=0;i<n;i++)
    {
        tmp=new Node();
        cin>>tmp->key;
        tmp->addr=NULL;
        l1.insertatend(tmp);
    }
    l1.interchange();
    cout<<"After swapping adjacent nodes in circular linked list: \n";
    l1.print();
}