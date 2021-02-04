#include <iostream>
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
    void swap_values(LinkedList, int);
    void swap_nodes(LinkedList, int);
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
void LinkedList :: swap_values(LinkedList l1, int n)
{
    int temp,k,q,swap=0;
    for(k=0;k<n;k++)
    {
        Node *i=l1.front;
        swap=0;
        for(q=0;q<n-k-1;q++)
        {
            Node *j=i->addr;
            if(i->key>j->key)
            {
                temp=i->key;
                i->key=j->key;
                j->key=temp;
                swap=1;
            }
            i=i->addr;
        }
        if(swap==0)
            break;
    }
    cout<<"The sorted list is : \n";
    l1.print();
}
void LinkedList :: swap_nodes(LinkedList l1, int n)
{
    Node *i,*j,*previ,*prevj,*tmp=NULL;
    int swap=0,k,q;
    for(k=0;k<n;k++)
    {
        i=l1.front;
        swap=0;
        for(q=0;q<n-k-1;q++)
        {
            j=i->addr;
            if(i->key>j->key)
            {
                if(i==l1.front)
                {
                    if(j==i->addr)
                    {
                        tmp=j->addr;
                        j->addr=i;
                        i->addr=tmp;
                        tmp=i;
                        i=j;
                        j=tmp;
                        l1.front=i;
                    }
                    else
                    {
                        prevj=l1.front;
                        while(prevj->addr!=j)
                            prevj=prevj->addr;
                        tmp=j->addr;
                        j->addr=i->addr;
                        prevj->addr=i;
                        i->addr=tmp;
                        tmp=i;
                        i=j;
                        j=tmp;
                        l1.front=i;
                    }
                }
                else
                {
                    if(j==i->addr)
                    {
                        previ=l1.front;
                        while(previ->addr!=i)
                            previ=previ->addr;
                        tmp=j->addr;
                        previ->addr=j;
                        j->addr=i;
                        i->addr=tmp;
                        tmp=i;
                        i=j;
                        j=tmp;
                    }
                    else
                    {
                        previ=l1.front;
                        while(previ->addr!=i)
                            previ=previ->addr;
                        prevj=previ;
                        while(prevj->addr!=j)
                            prevj=prevj->addr;
                        previ->addr=j;
                        tmp=j->addr;
                        j->addr=i->addr;
                        prevj->addr=i;
                        i->addr=tmp;
                        tmp=i;
                        i=j;
                        j=tmp;
                    }
                }
            }
            swap=1;
            i=i->addr;
        }
        if(swap==0)
            break;
    }
    cout<<"The sorted list is : \n";
    l1.print();
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
    int n,ins,i;
    LinkedList l1;
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
    cout<<"Please select an option : ";
    cout<<"\n1.Swap the values to perform sorting\n2.Swap the nodes to perform sorting\n";
    cin>>ins;
    switch(ins)
    {
        case 1 :l1.swap_values(l1,n);
                break;
        case 2 :l1.swap_nodes(l1,n);
                break;
    }
}