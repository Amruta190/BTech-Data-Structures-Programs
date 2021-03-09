#define max 100
class Stacks
{
    int arr[max];
    int top=0;
    public :
    void push(int k);
    int pop();
};
void Stacks :: push(int k)
{
    arr[++top]=k;
}
int Stacks :: pop()
{
    int temp=arr[top];
    --top;
    return temp;
}