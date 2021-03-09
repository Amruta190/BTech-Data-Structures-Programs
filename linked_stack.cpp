#include<iostream>
using namespace std;
class Node
{
    public:
    int key;
    Node*addr;
};
class LinkedList
{
    Node *front=NULL;
    Node *rear=NULL;
    public:
    void insertatend(Node *);
    void deleteatend();
    void print();
};
void LinkedList ::insertatend(Node *tmp)
{
    if(front==NULL&&rear==NULL)
        front=rear=tmp;
    else
    {
        rear->addr=tmp;
        rear=tmp;
    }  
}
void LinkedList ::deleteatend()
{
    if(front==NULL)
        cout<<"No elements available\n";
    else
    {
        Node *tmp=NULL;
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
            tmp=tmp->addr;
        }
    }
}
int main()
{
    int n,ins;
    LinkedList l1;
    while(true)
    {
        cout<<"\nPlease select an option : ";
        cout<<"\n1.Insert  2.Delete  3.Print  4.Exit\n";
        cin>>n;
        switch(n)
        {
            case 1:
            {
                int n;
                Node *tmp=NULL;
                cout<<"Please enter the key value : ";
                cin>>n;
                tmp=new Node();
                tmp->key=n;
                tmp->addr=NULL;
                l1.insertatend(tmp);
            }
            case 2:l1.deleteatend();
                    break;
            case 3:l1.print();
                    break;
            case 4:exit(0);
        }
    }
}