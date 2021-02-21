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
    void reverse();
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
void LinkedList ::reverse()
{
    if(front==NULL)
        return;
    else
    {
        Node *tmp=NULL, *tmp1=NULL;
        tmp1=rear;
        while(front!=rear)
        {
            tmp=front;
            while(tmp->next!=rear)
                tmp=tmp->next;
            rear->next=tmp;
            rear=tmp;
        }
        rear->next=NULL;
        front=tmp1;
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
            tmp=tmp->next;
        }
    }
}
int main()
{
    int n,i;
    LinkedList l1;
    cout<<"Enter no.of nodes : ";
    cin>>n;
    if(n>0)
    {
        cout<<"Enter "<<n<<" nodes : ";
        for(i=0;i<n;i++)
        {
            Node *tmp=NULL;
            tmp=new Node();
            cin>>tmp->key;
            tmp->next=NULL;
            l1.insertatend(tmp);
        }
    }
    cout<<"\nGiven linked list is : \n";
    l1.print();
    l1.reverse();
    cout<<"\nLinked list after reversing is : \n";
    l1.print();
    // while(true)
    // {
        // cout<<"\nPlease select an option : ";
        // cout<<"\n1.Insert_at_end  2.Reverse and Print  3.Exit\n";
        // cin>>n;
        // switch(n)
        // {
            // case 1:
            // {
    //             int k;
    //             Node *tmp=NULL;
    //             cout<<"Enter key value : ";
    //             cin>>k;
    //             tmp=new Node();
    //             tmp->key=k;
    //             tmp->next=NULL;
    //             l1.insertatend(tmp);
    //         }
    //             break;
    //         case 2:l1.reverse();
    //                 l1.print();
    //                 break;
    //         case 3:exit(0);
    //     }
    // }
}