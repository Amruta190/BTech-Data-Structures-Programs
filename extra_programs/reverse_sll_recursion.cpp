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
    public:
    Node *front=NULL;
    Node *rear=NULL;
    void insertatend(Node *);
    Node* reverse(Node *);
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
Node* LinkedList ::reverse(Node *head)
{
    if(head==NULL||head->next==NULL)
        return head;
    Node *tmp=reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return tmp;
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
    if(n<0)
    {
        cout<<"Please enter correct input!!";
        exit(0);
    }
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
    l1.rear=l1.front;
    l1.front=l1.reverse(l1.front);
    cout<<"\nLinked list after reversing is : \n";
    l1.print();
}