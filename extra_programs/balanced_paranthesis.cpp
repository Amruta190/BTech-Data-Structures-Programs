#include<iostream>
#include"int_stack.h"
using namespace std;
#define max 100
class Stack
{
    char arr[max];
    int top=0;
    public :
    void push(int k);
    char pop();
    int isEmpty();
    char peek();
};
void Stack :: push(int k)
{
    arr[++top]=k;
}
char Stack :: pop()
{
    int temp=arr[top];
    --top;
    return temp;
}
char Stack :: peek()
{
    return arr[top];
}
int Stack :: isEmpty()
{
    if(top==0)
        return 1;
    else
        return 0;
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
        case '(':return 1;
        case '[':return 1;
        case '{':return 1;
    }
}
void evaluationOfPostfix(char str[])
{
    Stacks s1;
    int i=0,k;
    cout<<"It's postfix expression is : ";
    puts(str);
    cout<<"\n";
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
                case '/':if(b==0)
                         {
                            cout<<"Undefined";
                            exit(0);
                         }
                         else
                         {
                            s1.push(a/b);
                            break;
                         }  
            }
        }
        i++; 
    }
    cout<<"Result : "<<s1.pop();
}
void infixToPostfix(char str[])
{
    int i=0,p=0;
    char str1[30];
    Stack s1;
    while(str[i]!='\0')
    {
        if(isOperator(str[i]))
        {
            if(s1.isEmpty())
                s1.push(str[i]);
            else if(s1.peek()=='('||s1.peek()=='['||s1.peek()=='{')
                s1.push(str[i]);
            else
            {
                while(getPriority(str[i])<=getPriority(s1.peek()) && !s1.isEmpty())
                    str1[p++]=s1.pop();
                s1.push(str[i]);
            }
        }
        else if(str[i]=='('||str[i]=='['||str[i]=='{')
        {
            s1.push(str[i]);
        }
        else if(str[i]==')'||str[i]==']'||str[i]=='}')
        {
            if(str[i]==')')
            {
                while(s1.peek()!='(')
                    str1[p++]=s1.pop();
                s1.pop();
            }
            if(str[i]==']')
            {
                while(s1.peek()!='[')
                    str1[p++]=s1.pop();
                s1.pop();
            }
            if(str[i]=='}')
            {
                while(s1.peek()!='{')
                    str1[p++]=s1.pop();
                s1.pop();
            }
        }
        else
        {
            str1[p++]=str[i];
        }
        i++;
    }
    while (!s1.isEmpty())
    {
        str1[p++]=s1.pop();
    }
    str1[p]='\0';
    evaluationOfPostfix(str1);
}
int main()
{
    Stack s1;
    cout<<"Enter the infix expression :";
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
    if(flag==0 && s1.isEmpty())
    {
        cout<<"Balanced\n";
        infixToPostfix(str);
    }
    else
        cout<<"Not balanced";
}