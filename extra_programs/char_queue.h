#define max 5
class Queue
{
    int front=-1;
    int rear=-1;
    public:
    char arr[max];
    void insert(char k);
    char delete1();
    void Empty();
};
void Queue :: insert(char k)
{
    if(front==-1)
        front=0;
    arr[++rear]=k; 
}
char Queue :: delete1()
{
    char temp=arr[front];
    for(int i=front;i<=rear;i++)
        arr[i]=arr[i+1];
    rear--;
    if(rear==-1)
        front=-1;  
    return temp;
}
void Queue :: Empty()
{
    while(front!=-1)
        delete1();
}