#include<iostream>
using namespace std;
class Node
{
    public:
    int key;
    Node *right,*left;
};
class LinkedList
{
    Node *head=NULL;
    public:
    void insertatbegin(Node *);
    void insertatend(Node *);
    void insertatposition(Node *);
    void deleteatbegin();
    void deleteatend();
    void deleteatposition();
    void print_forward();
    void print_backward();
};
void LinkedList :: insertatbegin(Node *tmp)
{
    Node *p=head;
    if(head==NULL)
    {
        head=tmp;
        tmp->right=head;
        tmp->left=head;
    }
    else
    {
        while(p->right!=head)
            p=p->right;
        p->right=tmp;
        tmp->left=p;
        tmp->right=head;
        head->left=tmp;
        head=tmp;
    }
}
void LinkedList :: insertatend(Node *tmp)
{
    Node *p=head;
    if(head==NULL)
    {
        head=tmp;
        tmp->right=head;
        tmp->left=head;
    }
    else
    {
        while(p->right!=head)
            p=p->right;
        p->right=tmp;
        tmp->left=p;
        tmp->right=head;
        head->left=tmp;
    }
}
void LinkedList :: insertatposition(Node *tmp)
{
    int pos;
    Node *tmp1=head;
    cout<<"Please enter the position : ";
    cin>>pos;
    int pos1=1;
    if(head==NULL)
    {
        head=tmp;
        tmp->right=head;
        tmp->left=head;
    }
    else
    {
        while(pos1!=pos-1)
        {
            tmp1=tmp1->right;
            pos1++;
        }
        tmp->right=tmp1->right;
        tmp1->right->left=tmp;
        tmp1->right=tmp;
        tmp->left=tmp1;
    }  
}
void LinkedList :: deleteatbegin()
{
    if(head==NULL)
        cout<<"No elements available\n";
    else
    {
        Node *tmp=head;
        while(tmp->right!=head)
            tmp=tmp->right;
        head=head->right;
        tmp->right=head;
        head->left=tmp;
    }
}
void LinkedList ::deleteatend()
{
    if(head==NULL)
        cout<<"No elements available\n";
    else
    {
        Node *tmp=head;
        while(tmp->right->right!=head)
        {
            tmp=tmp->right;
        }
        tmp->right=head;
        head->left=tmp;
    }
}
void LinkedList ::deleteatposition()
{
    if(head==NULL)
        cout<<"No elements available\n";
    else
    {
        int pos;
        cout<<"Please enter the position : ";
        cin>>pos;
        Node *tmp=head;
        int pos1=1;
        while(pos1!=pos-1)
        {
            tmp=tmp->right;
            pos1++;
        }
        tmp->right=tmp->right->right;
        tmp->right->left=tmp;
    }
}
void LinkedList :: print_forward()
{
    Node *temp=head;
    if(temp==NULL)
        cout<<"No nodes available";
    else if(temp->right==head)
        cout<<temp->key;
    else
    {
        while(temp->right!=head)
        {
            cout<<temp->key<<" ";
            temp=temp->right;
        }
        cout<<temp->key;
    }
}
void LinkedList :: print_backward()
{
    Node *temp=head;
    if(temp==NULL)
        cout<<"No nodes available";
    else if(temp->left==head)
        cout<<temp->key;
    else
    {
        temp=head->left;
        while(temp!=head)
        {
            cout<<temp->key<<" ";
            temp=temp->left;
        }
        cout<<temp->key;
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
                tmp->right=NULL;
                tmp->left=NULL;
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
            case 3:cout<<"\n1.Forward Print\t2.Backward Print\n";
            cin>>ins;
            switch(ins)
            {
                case 1:l1.print_forward();
                            break;
                case 2:l1.print_backward();
                            break;
            }
            break;
            case 4:exit(0);
        }
    }
}