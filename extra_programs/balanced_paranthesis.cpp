#include<iostream>
#include<stdlib.h>
using namespace std;
#define max 100
class Stack
{
    char arr[max];
    int top=0;
    public :
    void push(int k);
    int pop();
    int isEmpty();
};
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
int Stack :: isEmpty()
{
    if(top==0)
        return 1;
    else
        return 0;
}
int main()
{
    Stack s1;
    cout<<"Enter the postfix expression : ";
    char str[30];
    gets(str);
    int i=0,flag=0;
    char a;
    while(str[i]!='\0')
    {
        if (str[i]=='('||str[i]=='['||str[i]=='{')
        {
            s1.push(str[i]);
        }
        else if(str[i]==')'||str[i]==']'||str[i]=='}')
        {
            switch(str[i])
            {
                case ')':
                {
                    a=s1.pop();
                    if(a=='(')
                        break;
                    else
                    {
                        flag=1;
                        break;
                    }
                }
                break;
                case ']':
                {
                    a=s1.pop();
                    if(a=='[')
                        break;
                    else
                    {
                        flag=1;
                        break;
                    }
                }
                break;
                case '}':
                {
                    a=s1.pop();
                    if(a=='{')
                        break;
                    else
                    {
                        flag=1;
                        break;
                    }
                }
                break;
            }
        }
        i++; 
    }
    int k=s1.isEmpty();
    if(flag==0 && k==1)
        cout<<"Balanced";
    else
        cout<<"Not balanced";
}