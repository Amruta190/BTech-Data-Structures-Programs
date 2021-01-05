//Doubly Linked List
#include<iostream>
using namespace std;
class Node
{
    public:
    int key;
    Node *left,*right;
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
    void forwardprint();
    void backwardprint();
};
void LinkedList :: insertatbegin(Node *tmp)
{
    if(front==NULL&&rear==NULL)
        front=rear=tmp;
    else
    {
        tmp->right=front;
        front->left=tmp;
        front=tmp;
    }  
}
void LinkedList :: insertatend(Node *tmp)
{
    if(front==NULL&&rear==NULL)
        front=rear=tmp;
    else
    {
        rear->right=tmp;
        tmp->left=rear;
        rear=tmp;
    }  
}
void LinkedList :: insertatposition(Node *tmp)
{
    int pos;
    Node *tmp2=front;
    cout<<"Please enter the position : ";
    cin>>pos;
    int pos1=1;
    if(front==NULL&&rear==NULL)
        front=rear=tmp;
    else
    {
        while(pos1!=pos-1)
        {
            tmp2=tmp2->right;
            pos1++;
        }
        tmp->right=tmp2->right;
        tmp2->right->left=tmp;
        tmp2->right=tmp;
        tmp->left=tmp2;
    }  
}
void LinkedList :: deleteatbegin()
{
    if(front==NULL)
        cout<<"No elements available\n";
    else
    {
        Node *tmp=NULL;
        tmp=front->right;
        front->right=NULL;
        delete front;
        front=tmp;
    }
}
void LinkedList :: deleteatend()
{
    if(front==NULL)
        cout<<"No elements available\n";
    else
    {
        Node *tmp=NULL;
        tmp=rear->left;
        rear->left->right=NULL;
        delete rear;
        rear=tmp;
    }
}
void LinkedList :: deleteatposition()
{
    if(front==NULL)
        cout<<"No elements available\n";
    else
    {
        int pos;
        cout<<"Please enter the position : ";
        cin>>pos;
        Node *tmp=front;
        int pos1=1;
        while(pos1!=pos)
        {
            tmp=tmp->right;
            pos1++;
        }
        tmp->left->right=tmp->right;
        tmp->right->left=tmp->left;
        delete tmp;
    }
}
void LinkedList :: forwardprint()
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
            tmp=tmp->right;
        }
    }
}
void LinkedList :: backwardprint()
{
    if(rear==NULL||front==NULL)
        cout<<"Empty";
    else
    {
        Node *tmp=NULL;
        tmp=rear;
        while(tmp!=NULL)
        {
            cout<<tmp->key<<" ";
            tmp=tmp->left;
        }
    }
}
int main()
{
    int op,ins;
    LinkedList l1;
    while(true)
    {
        cout<<"\nPlease select an option : ";
        cout<<"\n1.Insert  2.Delete  3.Print  4.Exit\n";
        cin>>op;
        switch(op)
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
                tmp->left=NULL;
                tmp->right=NULL;
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
            case 3:cout<<"\n1.Forward Print \t 2.Backward Print\n";
            cin>>ins;
            switch(ins)
            {
                case 1:l1.forwardprint();
                        break;
                case 2:l1.backwardprint();
                        break;
            }
            break;
            case 4:exit(0);
        }
    }
}