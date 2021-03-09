#include<iostream>
using namespace std;
template<class L>
class Node
{
    public:
    L key;
    Node<L> *addr;
};
template<class L>
class LinkedList
{
    Node<L> *front=NULL;
    Node<L> *rear=NULL;
    public:
    void insertatend(Node<L> *);
    void deleteatend();
    void print();
};
template<class L>
void LinkedList<L> ::insertatend(Node<L> *tmp)
{
    if(front==NULL&&rear==NULL)
        front=rear=tmp;
    else
    {
        rear->addr=tmp;
        rear=tmp;
    }  
}
template<class L>
void LinkedList<L> ::deleteatend()
{
    if(front==NULL)
        cout<<"No elements available\n";
    else
    {
        Node<L> *tmp=NULL;
        tmp=front;
        while(tmp->addr!=rear)
        {
            tmp=tmp->addr;
        }
        tmp->addr=NULL;
        delete rear;
        rear=tmp;
    }
}
template<class L>
void LinkedList<L> :: print()
{
    if(front==NULL)
        cout<<"Empty";
    else
    {
        Node<L> *tmp=NULL;
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
    LinkedList<int> l1;
    Node<int> *tmp=NULL;
    cout<<"Integer Linked List\n";
    cout<<"Enter no.of nodes : ";
    cin>>n;
    cout<<"Please enter the key values : ";
    for(i=0;i<n;i++)
    {
        tmp=new Node<int>();
        cin>>tmp->key;
        tmp->addr=NULL;
        l1.insertatend(tmp);
    }
    cout<<"The given integer linked list is :\n";
    l1.print();
    cout<<"\nFloat linked list\n";
    LinkedList<float> l2;
    Node<float> *temp=NULL;
    cout<<"Enter no.of nodes : ";
    cin>>n;
    cout<<"Please enter the key values : ";
    for(i=0;i<n;i++)
    {
        temp=new Node<float>();
        cin>>temp->key;
        temp->addr=NULL;
        l2.insertatend(temp);
    }
    cout<<"The given float linked list is :\n";
    l2.print();
    cout<<"\nString linked list\n";
    LinkedList<string> l3;
    Node<string> *temp1=NULL;
    cout<<"Enter no.of nodes : ";
    cin>>n;
    cout<<"Please enter the key values : ";
    for(i=0;i<n;i++)
    {
        temp1=new Node<string>();
        cin>>temp1->key;
        temp1->addr=NULL;
        l3.insertatend(temp1);
    }
    cout<<"The given string linked list is :\n";
    l3.print();
}