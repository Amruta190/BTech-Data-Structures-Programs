//Program for evaluation of Postfix expression
#include<iostream>
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
int isNum(char ch)
{
    return ch-48;
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
    cout<<"Enter the postfix expression : ";
    char str[30];
    gets(str);
    int i=0;
    while(str[i]!='\0')
    {
        if (str[i]>='0'&&str[i]<='9')
        {
            int m=isNum(str[i]);
            s1.push(m);
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