#include<iostream>
using namespace std;
#define max 10
class Stack
{
    int arr[max+1];
    int topA=0,topB=max+1;
    public :
    void pushA(int k);
    void pushB(int k);
    int popA();
    int popB();
    int peekA();
    int peekB();
    void printA();
    void printB();
};
void Stack :: pushA(int k)
{
    if(topA+1==topB)
        cout<<"Stack Overflow";
    else
    {
        arr[++topA]=k;
        cout<<"The value "<<k<<" is inserted into the stack-A";
    }
}
void Stack :: pushB(int k)
{
    if(topA+1==topB)
        cout<<"Stack Overflow";
    else
    {
        arr[--topB]=k;
        cout<<"The value "<<k<<" is inserted into the stack-B";
    }
}
int Stack :: popA()
{
    if(topA==0)
    {
        cout<<"Stack empty";
    }
    else
    {
        int temp,i;
        temp=arr[topA];
        --topA;
        cout<<"The value "<<temp<<" is deleted from the stack-A";   
    }
}
int Stack :: popB()
{
    if(topB==max+1)
    {
        cout<<"Stack empty";
    }
    else
    {
        int temp,i;
        temp=arr[topB];
        ++topB;
        cout<<"The value "<<temp<<" is deleted from the stack-B";   
    }
}
int Stack :: peekA()
{
    if(topA==0)
    {
        cout<<"Stack empty";
    }
    else
    {
        cout<<arr[topA]<<" is the peek value";
    }  
}
int Stack :: peekB()
{
    if(topB==max)
    {
        cout<<"Stack empty";
    }
    else
    {
        cout<<arr[topB]<<" is the peek value";
    }  
}
void Stack :: printA()
{
    if(topA==0)
    {
        cout<<"Stack empty";
    }
    for(int i=topA;i>0;i--)
    {
        cout<<arr[i]<<" ";
    }
}
void Stack :: printB()
{
    if(topB==max)
    {
        cout<<"Stack empty";
    }
    for(int i=topB;i<=max;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int val;
    Stack s1;
    while(1)
    {
        cout<<"\n1. Push\t2. Pop\t3. Peek\t4. Print\t5. Exit\n";
        cout<<"Select a choice to perform an Operation : ";
        cin>>val;
        switch (val)
        {
            int val1;
            case 1 :cout<<"1.Stack-A\t2.Stack-B\n";
                    cin>>val;
                    switch(val)
                    {
                        case 1:cout<<"Enter the value to insert into the stack-A : ";
                               cin>>val1;
                               s1.pushA(val1);
                               break;
                        case 2:cout<<"Enter the value to insert into the stack-B : ";
                               cin>>val1;
                               s1.pushB(val1);
                               break;
                    }
                    break;
            case 2 :cout<<"1.Stack-A\t2.Stack-B\n";
                    cin>>val;
                    switch(val)
                    {
                        case 1:s1.popA();
                               break;
                        case 2:s1.popB();
                               break;
                    }
                    break;
            case 3 :cout<<"1.Stack-A\t2.Stack-B\n";
                    cin>>val;
                    switch(val)
                    {
                        case 1:s1.peekA();
                               break;
                        case 2:s1.peekB();
                               break;
                    }
                    break;
            case 4 :cout<<"1.Stack-A\t2.Stack-B\n";
                    cin>>val;
                    switch(val)
                    {
                        case 1:s1.printA();
                               break;
                        case 2:s1.printB();
                               break;
                    }
                    break;
            case 5 : exit(0);
        }
    }
}