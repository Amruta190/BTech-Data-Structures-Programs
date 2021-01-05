#include<iostream>
using namespace std;
void interchange(int* a, int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void selectionSort(int arr[], int n)
{
    int i,j,k;
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[k])
            k=j;
            interchange(&arr[k],&arr[i]);
        }
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
    selectionSort(arr,n);
    cout<<"The sorted array is : ";
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}