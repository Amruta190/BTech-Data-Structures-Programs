//Program to perform quick sort
#include<iostream>
using namespace std;
void interchange(int* a, int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int a[], int p, int q)
{
    int pivot,i,j;
    pivot=a[q];
    i=p-1;
    for(j=p;j<=q-1;j++)
    {
        if(a[j]<pivot)
        {
            i++;
            interchange(&a[i],&a[j]);
        }
    }
    interchange(&a[i+1],&a[j]);
    return (i+1);
}
void QuickSort(int a[], int p,int q)
{
    int j;
    if(p<q)
    {
        j=partition(a,p,q);
        QuickSort(a,p,j-1);
        QuickSort(a,j+1,q);
    }
}
int main()
{
    int n,a[100],i,p,q;
    cout<<"Enter the size of the array : ";
    cin>>n;
    cout<<"Enter the array elements : ";
    for(i=0;i<n;i++)
        cin>>a[i];
    p=0;
    q=n-1;
    QuickSort(a,p,q);
    cout<<"The sorted array is : ";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
}