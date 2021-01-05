#include<iostream>
using namespace std;
void insertionSort(int arr[], int n) 
{ 
    int i,j,temp; 
    for(i=1;i<n;i++) 
    { 
        temp=arr[i]; 
        j=i-1; 
        while(j>=0 && arr[j]>temp) 
        { 
            arr[j+1]=arr[j]; 
            j=j-1; 
        } 
        arr[j+1]=temp; 
    } 
} 
int main()
{
    int n,arr[100],i;
    cout<<"Enter array size : ";
    cin>>n;
    cout<<"Enter the elements of the array : ";
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    insertionSort(arr,n);
    cout<<"The sorted array is ";
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}