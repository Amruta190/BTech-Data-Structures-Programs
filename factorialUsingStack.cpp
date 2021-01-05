#include<iostream>
#include"StackAsHeader.cpp"
using namespace std;
#define max 100
class Stack
{
    int arr[max];
    int top=0;
    public :
    bool isEmpty();
    void push(int k);
    int pop();
};
bool Stack :: isEmpty()
{
    if(top==0)
        return true;
    else
        return false;
}
void Stack :: push(int k)
{
    arr[++top]=k;
}
int Stack :: pop()
{
    int temp=arr[top];
    --top;
    return temp;
}
int main()
{
    Stack s1;
    cout<<"Enter the number to find out its factorial : ";
    int n,p,i,a,b;
    cin>>n;
    p=n;
    if(n==0||n==1)
        cout<<"The factorial of "<<p<<" is 1";
    else
    {
        for(i=n;i>0;i--)
        {
            s1.push(i);
        }
        a=s1.pop();
        b=s1.pop();
        while(!s1.isEmpty())
        {
            s1.push(a*b);
            a=s1.pop();
            b=s1.pop();
        }
        cout<<"The factorial of "<<p<<" is "<<a*b;
    }
}