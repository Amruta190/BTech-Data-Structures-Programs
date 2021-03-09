#include<iostream>
#include<stdlib.h>
#include"char_queue.h"
using namespace std;
class Node
{
    public:
    int coeff;
    int exp;
    Node *next;
};
class Linkedlist
{
    Node *front=NULL;
    Node *rear=NULL;
    public:
    void insertAtEnd(Node*);
    void print();
    void add(Linkedlist,Linkedlist);
};
void Linkedlist :: insertAtEnd(Node *tmp)
{
    if(front==NULL && rear==NULL)
        front=rear=tmp;
    else
    {
        rear->next=tmp;
        rear=tmp;
    }
}
void Linkedlist :: print()
{
    if(front==NULL)
        cout<<"Empty";
    else
    {
        Node *tmp=NULL;
        tmp=front;
        while(tmp->next!=NULL)
        {
            cout<<"("<<tmp->coeff;
            if(tmp->exp!=1 && tmp->exp!=0)
                cout<<"x^"<<tmp->exp<<")+";
            else if(tmp->exp==1)
                cout<<"x)+";
            else if(tmp->exp==0)
                cout<<")+";
            tmp=tmp->next;
        }
        cout<<"("<<tmp->coeff;
        if(tmp->exp!=1 && tmp->exp!=0)
            cout<<"x^"<<tmp->exp<<")";
        else if(tmp->exp==1)
            cout<<"x)";
        else if(tmp->exp==0)
            cout<<")";
    }
}
int isOperator(char ch)
{
    if(ch=='+')
        return 1;
    else if(ch=='-')
        return -1;
    else
        return 0;
}
Linkedlist getpoly(char str[])
{
    Linkedlist l;
    Queue q;
    int i=0;
    while(str[i]!='\0')
    {
        int flag=0;
        Node *tmp=NULL;
        tmp=new Node();
        q.Empty();
        do
        {
            if(str[i]=='-')
            {
                q.insert('-');
                i++;
                if(str[i]=='x')
                {
                    flag=-2;
                    break;
                }
            }
            if(str[i]=='+')
            {
                q.insert('+');
                i++;
                if(str[i]=='x')
                {
                    flag=-1;
                    break;
                }
            }
            q.insert(str[i]);
            i++;
        }while(str[i]!='x' && str[i]!='\0' && str[i]!='+' && str[i]!='-');
        if(str[i]=='x')
            i++;
        if(flag==-2)
            tmp->coeff=-1;
        else if(flag==-1)
            tmp->coeff=1;
        else 
            tmp->coeff=atoi(q.arr);
        q.Empty();
        if(str[i]=='^')
        {
            i++;
            if(isOperator(str[i])==-1)
            {
                q.insert('-');
                i++;
            }
            while(isOperator(str[i])==0 && str[i]!='\0')
            {
                q.insert(str[i]);
                i++;
            }
            tmp->exp=atoi(q.arr);
        }
        else if(str[i]!='^')
        {
            if(str[i-1]=='x')
                tmp->exp=1;
            if(str[i-1]!='x')
                tmp->exp=0;
        }    
        tmp->next=NULL;
        l.insertAtEnd(tmp);
    }
    return l;
}
void Linkedlist :: add(Linkedlist l1,Linkedlist l2)
{
    Linkedlist l;
    if(l1.front==NULL && l2.front==NULL)
        l1.print();
    else if(l1.front==NULL || l2.front==NULL)
    {
        if(l1.front==NULL)
            l2.print();
        else if(l2.front==NULL)
            l1.print();
    }
    else
    {
        Node *tmp1=l1.front,*tmp2=l2.front;
        while(tmp1!=NULL && tmp2!=NULL)
        {
            Node *tmp=new Node();
            if(tmp1->exp>tmp2->exp)
            {
                tmp->exp=tmp1->exp;
                tmp->coeff=tmp1->coeff;
                tmp->next=NULL;
                l.insertAtEnd(tmp);
                tmp1=tmp1->next;
            }
            else if(tmp1->exp<tmp2->exp)
            {
                tmp->exp=tmp2->exp;
                tmp->coeff=tmp2->coeff;
                tmp->next=NULL;
                l.insertAtEnd(tmp);
                tmp2=tmp2->next;
            }
            else
            {
                tmp->exp=tmp1->exp;
                tmp->coeff=tmp1->coeff+tmp2->coeff;
                tmp->next=NULL;
                l.insertAtEnd(tmp);
                tmp1=tmp1->next;
                tmp2=tmp2->next;
            }
        }
        while(tmp1!=NULL || tmp2!=NULL)
        {
            Node *tmp=new Node();
            if(tmp1==NULL)
            {
                tmp->exp=tmp2->exp;
                tmp->coeff=tmp2->coeff;
                tmp->next=NULL;
                l.insertAtEnd(tmp);
                tmp2=tmp2->next;
            }
            else 
            {
                tmp->exp=tmp1->exp;
                tmp->coeff=tmp1->coeff;
                tmp->next=NULL;
                l.insertAtEnd(tmp);
                tmp1=tmp1->next;
            }
        }
        l.print();
    }
}
int main()
{
    Linkedlist l1,l2,l;
    char str[50],str1[50];
    cout<<"Enter expression in this format :\nEg: -14x^3+5x^2+x-6-x^-1+12x^-3\n";
    cout<<"Enter 1st polynomial expression : ";
    gets(str);
    l1=getpoly(str);
    cout<<"Enter 2nd polynomial expression : ";
    gets(str);
    l2=getpoly(str);
    cout<<"Resultant expression : ";
    l.add(l1,l2);
}