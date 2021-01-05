//Program for number conversion (decimal to binary)
#include<iostream>
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
    cout<<"Enter a decimal number : ";
    int n,k,p;
    cin>>n;
    if(n==0)
        cout<<"The binary format of "<<n<<" is : "<<n;
    else
    {
        k=n;
        p=n;
        while (n!=0)
        {
            k=n%2;
            s1.push(k);
            n=n/2;
        }
        cout<<"The binary format of "<<p<<" is : ";
        while(!s1.isEmpty())
        {
            cout<<s1.pop();
        }
    }
}