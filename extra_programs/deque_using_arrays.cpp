#include<iostream>
using namespace std;
#define max 7
class deque
{
    int arr[max];
    int front=-1;
    int rear=-1;
    public:
    void insertatbegin(int k);
    void insertatend(int k);
    void deleteatbegin();
    void deleteatend();
    void print();
};
void deque :: insertatbegin(int k)
{
    if(rear==max-1)
    {
        cout<<"Queue is full";
    }
    else
    {
        if(front==-1&&rear==-1)
        {
            front=rear=0;
            arr[front]=k;
        }
        else
        {
            int i;
            for(i=rear+1;i>=front;i--)
                arr[i]=arr[i-1];
            arr[front]=k;
            rear++;
        }
        
    }

}
void deque :: insertatend(int k)
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
void deque :: deleteatbegin()
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
void deque :: deleteatend()
{
    if(front==-1)
    {
        cout<<"Elements, not available";
    }
    else
    {
        cout<<"\nThe element deleted is : "<<arr[rear];
        rear--;
    }
}
void deque :: print()
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
    deque q1;
    int n,k,ins;
    while(true)
    {
        cout<<"\n1. Insert    2. Delete   3. Print    4. Exit";
        cout<<"\nSelect an option : ";
        cin>>n;
        switch (n)
        {
            case 1: cout<<"1. Insert at beginning   2. Insert at end : ";
                    cin>>ins;
                    switch(ins)
                    {
                        case 1: cout<<"\nEnter the element to insert : ";
                                cin>>k;
                                q1.insertatbegin(k);
                                break;  
                        case 2: cout<<"\nEnter the element to insert : ";
                                cin>>k;
                                q1.insertatend(k);
                                break;  
                    }
                    break;
            case 2: cout<<"1. Delete at beginning   2. Delete at end : ";
                    cin>>ins;
                    switch(ins)
                    {
                        case 1: q1.deleteatbegin();
                                break;  
                        case 2: q1.deleteatend();
                                break;  
                    }
                    break;
            case 3:q1.print();
                    break;
            case 4:exit(0);
        }
    }
}