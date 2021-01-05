//Singly Linked List
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
    void insertatbegin(Node *);
    void insertatend(Node *);
    void insertatposition(Node *);
    void deleteatbegin();
    void deleteatend();
    void deleteatposition();
    void print();
};
void LinkedList ::insertatbegin(Node *tmp)
{
    if(front==NULL&&rear==NULL)
        front=rear=tmp;
    else
    {
        tmp->addr=front;
        front=tmp;
    }  
}
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
void LinkedList ::insertatposition(Node *tmp)
{
    int pos;
    Node *tmp1=front;
    cout<<"Please enter the position : ";
    cin>>pos;
    int pos1=1;
    if(front==NULL&&rear==NULL)
        front=rear=tmp;
    else
    {
        while(pos1!=pos-1)
        {
            tmp1=tmp1->addr;
            pos1++;
        }
        tmp->addr=tmp1->addr;
        tmp1->addr=tmp;
    }  
}
void LinkedList ::deleteatbegin()
{
    if(front==NULL)
        cout<<"No elements available\n";
    else
    {
        Node *tmp=NULL;
        tmp=front->addr;
        front->addr=NULL;
        delete front;
        front=tmp;
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
void LinkedList ::deleteatposition()
{
    if(front==NULL)
        cout<<"No elements available\n";
    else
    {
        int pos;
        cout<<"Please enter the position : ";
        cin>>pos;
        Node *tmp=front;
        Node *tmp1=front;
        int pos1=1;
        while(pos1!=pos-1)
        {
            tmp=tmp->addr;
            pos1++;
        }
        pos1=1;
        while(pos1!=pos)
        {
            tmp1=tmp1->addr;
            pos1++;
        }
        tmp->addr=tmp1->addr;
        delete tmp1;
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
                cout<<"1.Insert at Beginning\t2.Insert at the end\t3.Insert at a position\n";
                cin>>ins;
                int n;
                Node *tmp=NULL;
                cout<<"Please enter the key value : ";
                cin>>n;
                tmp=new Node();
                tmp->key=n;
                tmp->addr=NULL;
                switch(ins)
                {
                    case 1:l1.insertatbegin(tmp);
                            break;
                    case 2:l1.insertatend(tmp);
                            break;
                    case 3:l1.insertatposition(tmp);
                            break;
                }
                break;
            }
            case 2:cout<<"\n1.Delete at Beginning\t2.Delete at the end\t3.Delete at a position\n";
            cin>>ins;
            switch(ins)
            {
                case 1:l1.deleteatbegin();
                        break;
                case 2:l1.deleteatend();
                        break;
                case 3:l1.deleteatposition();
                        break;
            }
            break;
            case 3:l1.print();
                    break;
            case 4:exit(0);
        }
    }
}