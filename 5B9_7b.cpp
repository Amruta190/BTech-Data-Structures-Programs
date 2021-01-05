//program to implement circular queue
#include<iostream>
using namespace std;
#define max 7
class Queue
{
    int arr[max];
    int front=-1;
    int rear=-1;
    public:
    void insert(int k);
    void delete1();
    void print();
};
void Queue :: insert(int k)
{
    if((front==0 && rear==max-1)||(front==rear+1))
        cout<<"Queue is full\n";
    else 
    {
        if(front==-1)
            front=0;
        rear=(rear+1)%max;
        arr[rear]=k;
    }   
}
void Queue :: delete1()
{
    if(front==-1)
    {
        cout<<"Elements, not available";
    }
    else
    {
        cout<<"\nThe element deleted is : "<<arr[front];
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front=(front+1)%max;
        }
    }   
}
void Queue :: print()
{
    int i;
    if(front==-1)
    {
        cout<<"No elements available in queue";
    }
    else
    {
        cout<<"Elements in the queue are : ";
        for(i=front;i!=rear;i=(i+1)%max)
            cout<<arr[i]<<" ";
        cout<<arr[i];
    }
}
int main()
{
    Queue q1;
    int n,k;
    while(true)
    {
        cout<<"\n1. Insert    2. Delete   3. Print     4. Exit";
        cout<<"\nSelect an option : ";
        cin>>n;
        switch (n)
        {
            case 1:cout<<"\nEnter the element to insert : ";
                    cin>>k;
                    q1.insert(k);
                    break;
            case 2:q1.delete1();
                    break;
            case 3:q1.print();
                    break;
            case 4:exit(0);
        }
    }
}
