#include<iostream>
#include<stdlib.h>
using namespace std;
#define max 100
class Stack
{
    int arr[max];
    int top=0;
    public :
    void push(int k);
    int pop();
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
bool isOperator(char ch)
{
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
        return true;
    else 
        return false;
}
int main()
{
    Stack s1;
    cout<<"Enter the postfix expression as characters : ";
    char str[30];
    gets(str);
    int i=0,k=0;
    while(str[i]!='\0')
    {
        if ((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z'))
        {
            cout<<"Enter value for "<<str[i]<<": ";
            cin>>k;
            s1.push(k);
        }
        else if(isOperator(str[i]))
        {
            int b=s1.pop();
            int a=s1.pop();
            switch(str[i])
            {
                case '+':s1.push(a+b);
                            break;
                case '-':s1.push(a-b);
                            break;
                case '*':s1.push(a*b);
                            break;
                case '/':s1.push(a/b);
                            break;
            }
        }
        i++; 
    }
    cout<<"Result : "<<s1.pop();
}