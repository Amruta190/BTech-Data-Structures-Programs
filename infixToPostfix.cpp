#include<iostream>
using namespace std;
#define max 100
class Stack
{
    char arr[max];
    int top=0;
    public :
    bool isEmpty();
    void push(int k);
    char pop();
    char peek();
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
char Stack :: pop()
{
    char temp=arr[top];
    --top;
    return temp;
}
char Stack :: peek()
{
    return arr[top];
}
bool isOperator(char ch)
{
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
        return true;
    else 
        return false;
}
int getPriority(char ch)
{
    switch(ch)
    {
        case '+':return 2;
        case '-':return 2;
        case '*':return 3;
        case '/':return 3;
    }
}
int main()
{
    Stack s1;
    cout<<"Enter the infix expression : ";
    char arr[30];
    gets(arr);
    int i=0;
    while(arr[i]!='\0')
    {
        if(isOperator(arr[i]))
        {
            if(s1.isEmpty())
                s1.push(arr[i]);
            else
            {
                if(getPriority(arr[i])<=getPriority(s1.peek()))
                    cout<<s1.pop();
                s1.push(arr[i]);
            }
        }
        // else if(arr[i]=='(')
        // {
        //    s1.push(arr[i]);
        // }
        // else if(arr[i]==')')
        // {
        //     while(s1.peek()!='(')
        //     {
        //         s1.push(arr[i]);
        //         cout<<s1.pop();
        //     }
        //     s1.pop();
        // }
        else
        {
            cout<<arr[i];
        }
        i++;
    }
    while (!s1.isEmpty())
    {
        cout<<s1.pop();
    }
}