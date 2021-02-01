#include<iostream>
using namespace std;
class Node
{
    public:
    int key;
    Node*next;
};
class LinkedList
{
    Node *front=NULL;
    Node *rear=NULL;
    public:
    void insertatend(Node *);
    void merge(LinkedList, LinkedList);
    void print();
};
void LinkedList ::insertatend(Node *tmp)
{
    if(front==NULL&&rear==NULL)
        front=rear=tmp;
    else
    {
        rear->next=tmp;
        rear=tmp;
    }  
}
void LinkedList ::merge(LinkedList l1, LinkedList l2)
{
    Node *prev=NULL, *curr=NULL, *tmp=NULL;
    curr=l1.front;
    Node *head1=l1.front, *head2=l2.front;
    if(head1->key>head2->key)
        front=head2;
    else
        front=head1;
    while(curr->next!=NULL || head2->next!=NULL)
    {
        if(curr->key<=head2->key)
        {
            prev=curr;
            if(curr->next==NULL)
            {
                curr->next=head2;
                break;
            }
            curr=curr->next;
        }
        else
        {
            if(head2->next==NULL)
            {
                prev->next=head2;
                head2->next=curr;
                break;
            }
            tmp=head2;
            head2=head2->next;
            if(prev==NULL)
            {
                tmp->next=curr;
                prev=tmp;
            }    
            else
            {
                prev->next=tmp;
                tmp->next=curr;
                prev=prev->next;
            }
        }
    }
    if(curr->key>head2->key)
    {
        prev->next=head2;
        head2->next=curr;
    }
    else
        curr->next=head2;
}
void LinkedList :: print()
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
            tmp=tmp->next;
        }
    }
}
int main()
{
    int n,n1;
    LinkedList l1,l2,l;
    cout<<"\nInsert 1st linkedlist : ";
    while(n!=2)
    {
        cout<<"\n1.Insert  2.Stop\n";
        cin>>n;
        switch(n)
        {
            case 1:
            {
                int k;
                Node *tmp=NULL;
                cout<<"Enter key value : ";
                cin>>k;
                tmp=new Node();
                tmp->key=k;
                tmp->next=NULL;
                l1.insertatend(tmp);
            }
                break;
            case 2:break;
        }
    }
    cout<<"\nInsert 2nd linkedlist : ";
    while(n1!=2)
    {
        cout<<"\n1.Insert  2.Stop\n";
        cin>>n1;
        switch(n1)
        {
            case 1:
            {
                int k;
                Node *tmp=NULL;
                cout<<"Enter key value : ";
                cin>>k;
                tmp=new Node();
                tmp->key=k;
                tmp->next=NULL;
                l2.insertatend(tmp);
            }
                break;
            case 2:break;
        }
    }
    cout<<"\nLinked list after merging is : ";
    l.merge(l1,l2);
    l.print();
}