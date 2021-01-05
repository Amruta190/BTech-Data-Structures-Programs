//Program to perform queue
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
    if(rear==max-1)
    {
        cout<<"Queue is full";
    }
    else 
    {
        if(front==-1)
            front=0;
        arr[++rear]=k;
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
        for(int i=front;i<=rear;i++)
            arr[i]=arr[i+1];
        rear--;
        if(rear==-1)
            front=-1;
    }    
}
void Queue :: print()
{
    if(front==-1)
    {
        cout<<"No elements available in queue";
    }
    else
    {
        cout<<"Elements in the queue are : ";
        for(int i=front;i<=rear;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
}
int main()
{
    Queue q1;
    int n,k;
    while(true)
    {
        cout<<"\n1. Insert    2. Delete   3. Print    4. Exit";
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