#include<iostream>
using namespace std;
class Node
{
    public:
    int row,col,key;
    Node *right,*down;
};
class LinkedList
{
    Node *rightRear=NULL;
    Node *downRear=NULL;
    public:
    Node *first;
    void firstNode(int,int);
    void rightInsert(int);
    void downInsert(int);
    void insert(int,int,int);
    void print();
};
void LinkedList :: firstNode(int m,int n)
{
    first=new Node();
    first->row=m;
    first->col=n;
    first->key=0;
    first->right=NULL;
    first->down=NULL;
}
void LinkedList :: rightInsert(int j)
{
    if(first->right==NULL)
        rightRear=first;
    Node *tmp=new Node();
    tmp->row=0;
    tmp->col=j;
    tmp->key=0;
    tmp->right=NULL;
    tmp->down=NULL;
    rightRear->right=tmp;
    rightRear=tmp;
}
void LinkedList :: downInsert(int i)
{
    if(first->down==NULL)
        downRear=first;
    Node *tmp=new Node();
    tmp->row=i;
    tmp->col=0;
    tmp->key=0;
    tmp->right=NULL;
    tmp->down=NULL;
    downRear->down=tmp;
    downRear=tmp;
}
void LinkedList :: insert(int i, int j, int value)
{
    Node *tmp=new Node();
    tmp->row=i;
    tmp->col=j;
    tmp->key=value;
    tmp->right=NULL;
    tmp->down=NULL;
    Node *tmp1=first->right;
    while(tmp1->col!=j)
        tmp1=tmp1->right;
    if(tmp1->down==NULL)
        tmp1->down=tmp;
    else
    {
        while(tmp1->down!=NULL)
            tmp1=tmp1->down;
        tmp1->down=tmp;
    }
    tmp1=first->down;
    while(tmp1->row!=i)
        tmp1=tmp1->down;
    if(tmp1->right==NULL)
        tmp1->right=tmp;
    else
    {
        while(tmp1->right!=NULL)
            tmp1=tmp1->right;
        tmp1->right=tmp;
    }
}
void LinkedList :: print()
{
    Node *tmp=first;
    if(tmp->right==NULL && tmp->down==NULL)
        cout<<"Empty";
    else
    {
        cout<<"Row  Col  Value\n";
        tmp=tmp->down;
        while(tmp!=NULL)
        {
            Node *tmp1=tmp;
            tmp1=tmp1->right;
            while(tmp1!=NULL)
            {
                cout<<" "<<tmp1->row<<"   ";
                cout<<" "<<tmp1->col<<"   ";
                cout<<" "<<tmp1->key<<"\n";
                tmp1=tmp1->right;
            }
            tmp=tmp->down;
        }
    }
}
int main()
{
    LinkedList l;
    int m,n,i,j,arr[100][100],count=0;
    cout<<"Enter no.of rows of sparse matrix : ";
    cin>>m;
    cout<<"Enter no.of columns of sparse matrix : ";
    cin>>n;
    if(m>0 && n>0)
    {
        cout<<"Enter sparse matrix : ";
        for(i=1;i<=m;i++)
            for(j=1;j<=n;j++)
                cin>>arr[i][j];
        l.firstNode(m,n);
        for(j=1;j<=n;j++)
        {
            count=0;
            for(i=1;i<=m;i++)
            {
                if(arr[i][j]!=0)
                    count=1;
            }
            if(count==1)
                l.rightInsert(j);
        }
        for(i=1;i<=m;i++)
        {
            count=0;
            for(j=1;j<=n;j++)
            {
                if(arr[i][j]!=0)
                    count=1;
            }
            if(count==1)
                l.downInsert(i);
        }
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(arr[i][j]!=0)
                {
                    l.insert(i,j,arr[i][j]);
                }
            }
        }
        cout<<"Sparse matrix is :\n";
        l.print();
    }
    else
        cout<<"Enter correct input!!";
}