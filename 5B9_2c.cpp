//Program to perform fibonacci search
#include<iostream>
using namespace std;
int min(int x, int y) 
{ 
    return (x<=y)? x : y; 
} 
int fibonacci(int n, int arr[], int k)
{
    int a=0,b=1,c=0;
    while(c<n)
    {
        c=a+b;
        a=b;
        b=c;
    }
    int offset=0; 
    while (c>1) 
    { 
        int i=min(offset+a, n); 
        if (arr[i] < k) 
        { 
            c=b; 
            b=a; 
            a=c-b; 
            offset=i; 
        } 
        else if (arr[i] > k) 
        { 
            c=a; 
            b=b-a; 
            a=c-b; 
        } 
        else return i; 
    } 
    if(arr[offset]==k)
        return offset;
    else
        return -1;
}
int main()
{
    int n,arr[100],i,k,m;
    cout<<"Enter the number of elements in an array : ";
    cin>>n;
    cout<<"Enter the elements in ascending order : ";
    for(i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter the key value : ";
    cin>>k;
    m=fibonacci(n,arr,k);
    if(m==-1)
        cout<<"Element not found";
    else
        cout<<"Found at index "<<m;
}