//Program to perform bubble sort
#include<iostream>
using namespace std;
int main()
{
    int n,arr[20],i,j,temp;
    cout<<"Enter the no.of elements required : ";
    cin>>n;
    cout<<"Enter "<<n<<" array elements : ";
    for(i=0;i<n;i++)
    {
       cin>>arr[i];
    }
    for (i=0;i<n;i++) 
    {
        for (j=0;j<n-i;j++)
        {
            if (arr[j] > arr[j+1]) 
            {
                temp  =  arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    cout<<"Elements after sorting : ";
    for(i=0;i<n;i++)
    {
       cout<<arr[i]<<" ";
    }
}