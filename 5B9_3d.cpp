//Program to perform merge sort
#include<iostream>
using namespace std;
void Merge(int low, int mid, int high, int arr[])
{
    int i,j,k;
    int p=mid-low+1;
    int q=high-mid;
    int st[p],str[q];
    for(i=0;i<p;i++)
      st[i]=arr[low+i];
    for(j=0;j<q;j++)
      str[j]=arr[mid+1+j];
    i=0;j=0;k=low;
    while(i<p&&j<q)
    {
        if(st[i]<=str[j])
        {
            arr[k]=st[i];
            i++;
        }
        else
        {
            arr[k]=str[j];
            j++;
        }
        k++;
    }
    while(i<p)
    {
        arr[k]=st[i];
        i++;
        k++;
    }
    while(j<q)
    {
        arr[k]=str[j];
        j++;
        k++;
    }
}
void MergeSort(int low, int high, int arr[])
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        MergeSort(low,mid,arr);
        MergeSort(mid+1,high,arr);
        Merge(low,mid,high,arr);
    }
}
int main()
{
    int n,arr[100],i,low,mid,high;
    cout<<"Enter array size :";
    cin>>n;
    cout<<"Enter the elements of the array :";
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    low=0;
    high=n-1;
    mid=(low+high)/2;
    MergeSort(low,high,arr);
    cout<<"The sorted array is : ";
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}