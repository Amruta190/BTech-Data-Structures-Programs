//Program to perform linear search
#include<iostream>
using namespace std;
int main()
{
    int arr[10],i,n,key;
    cout<<"Enter the number of elements : ";
    cin>>n;
    cout<<"Enter the numbers: ";
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the key value : ";
    cin>>key;
    for(i=0;i<n;i++)
    {
        if(key==arr[i])
        cout<<"index "<<i<<" search successful\n";
        else
        cout<<"index "<<i<<" search unsuccessful\n";
    }
}