//program to implement priority queue
#include<iostream>
using namespace std;
#define max 100
class Queue
{
    int arr[2][max];
    int front=-1;
    int rear=-1;
    public:
    void insert(int k0,int k1);
    int delete1();
    int delete2();
};
void Queue :: insert(int k0,int k1)
{
    if(front==-1)
    {
        front=0;
        arr[0][++rear]=k0;  
        arr[1][rear]=k1;
    }
    else
    {
        int j,found=0;
        for(j=front;j<=rear;j++)
        {
            if(k1>arr[1][j])
            {
                found++;
                for(int i=rear;i>=j;i--)
                {
                    arr[1][i+1]=arr[1][i];
                    arr[0][i+1]=arr[0][i];
                }
                arr[0][j]=k0;
                arr[1][j]=k1;
                rear++;
                break;
            }
        }
        if(found==0)
        {
            arr[0][++rear]=k0;
            arr[1][rear]=k1;
        }
    }
}
int Queue :: delete1()
{
    int temp=arr[0][front];
    for(int i=front;i<rear;i++)
    {
        arr[0][i]=arr[0][i+1];
    }
    rear--;
    if(rear==-1)
        front=-1; 
    return temp;
}
int Queue :: delete2()
{
    int temp1=arr[1][front];
    for(int i=front;i<rear;i++)
    {
        arr[1][i]=arr[1][i+1];
    }
    return temp1;
}
int main()
{
    Queue q1;
    int n,p,arr[2][100],i;
    cout<<"Enter the array size : ";
    cin>>n;
    cout<<"Enter the elements as \n\"element  priority\"\n";
    for(i=0;i<n;i++)
    {
        cin>>arr[0][i]>>arr[1][i];
        q1.insert(arr[0][i],arr[1][i]);
    }
    cout<<"Priority list is:\n";
    cout<<"  Elements:  "<<"Priority:\n";
    for(i=0;i<n;i++)
    {
        cout<<"\t"<<q1.delete1()<<"\t"<<q1.delete2()<<"\n";
    }
}