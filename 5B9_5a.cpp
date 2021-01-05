//Program to perform stack
#include<iostream>
using namespace std;
#define max 5
class Stack
{
    int arr[max];
    int top=0;
    public :
    void push(int k);
    int pop();
    int peek();
    void print();
};
void Stack :: push(int k)
{
    if(top==max)
        cout<<"Stack Overflow";
    else
    {
        arr[top++]=k;
        cout<<"The value "<<k<<" is inserted into the stack";
    }
}
int Stack :: pop()
{
    if(top==0)
    {
        cout<<"Stack empty";
    }
    else
    {
        int temp,i;
        temp=arr[top-1];
        --top;
        cout<<"The value "<<temp<<" is deleted from the stack";   
    }
}
int Stack :: peek()
{
    if(top==0)
    {
        cout<<"Stack empty";
    }
    else
    {
        cout<<arr[top-1]<<" is the peek value";
    }  
}
void Stack :: print()
{
    if(top==0)
    {
        cout<<"Stack empty";
    }
    for(int i=top-1;i>=0;i--)
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
        cout<<"\n1. Push\n2. Pop\n3. Peek\n4. Print\n5. Exit\n";
        cout<<"Select a choice to perform an Operation : ";
        cin>>val;
        switch (val)
        {
            int val1;
            case 1 : cout<<"Enter the value to insert into the stack : ";
                     cin>>val1;
                     s1.push(val1);
                     break;
            case 2 : s1.pop();
                     break;
            case 3 : s1.peek();
                     break;
            case 4 : s1.print();
                     break;
            case 5 : exit(0);
        }
    }
}