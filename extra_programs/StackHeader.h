#define max 100
class Stack
{
    int arr[max];
    int top=0;
    public :
    bool isEmpty();
    void push(int k);
    int pop();
}s;
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