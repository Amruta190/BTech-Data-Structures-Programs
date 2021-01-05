#define max 20
class Queue
{
    int arr[max];
    int front=-1;
    int rear=-1;
    public:
    void insert(int k);
    int delete1();
    int isEmpty();
};
void Queue :: insert(int k)
{
    if(front==-1)
        front=0;
    arr[++rear]=k;     
}
int Queue :: delete1()
{
    int tmp=arr[front];
    for(int i=front;i<=rear;i++)
        arr[i]=arr[i+1];
    rear--;
    if(rear==-1)
        front=-1;
    return tmp;
}
int Queue :: isEmpty()
{
    if(front==-1)
        return 1;
    else
        return 0;
}
