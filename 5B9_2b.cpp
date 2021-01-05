//Program to perform binary search
#include<iostream>
using namespace std;
int main()
{
    int a[100],n,key,i,mid,low=0,high,flag=0;
    cout<<"Enter the number of elements: ";
    cin>>n;
    high=n-1;
    cout<<"Enter the elements in ascending order : ";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter the key value : ";
    cin>>key;
    for ( i = 0; i < n; i++)
    {
       mid=(low+high)/2;
       if(a[mid]==key)
      {
        cout<<"Element found at "<< mid+1 <<"th position";
        flag=1;
        break;
      }
      else if(a[mid]<key)
      {
        low=mid+1;
      }
      else 
      {
        high=mid-1;
      }
    }
    if(flag==0)
    cout<<"Element not found";
}