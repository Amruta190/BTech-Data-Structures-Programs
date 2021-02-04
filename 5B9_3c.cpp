//Program to perform quick sort
#include<iostream>
using namespace std;
void exchange(int* a, int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int a[], int p, int q)
{
    int pivot,i,j,flag=0;
    pivot=a[p];
    while(flag!=1)
    {
        for(i=p+1;i<=q;i++)
        {
            if(a[i]>pivot)
                break;
        }
        for(j=q;j>=p+1;j--)
        {
            if(a[j]<pivot)
                break;
        }
        if(i<j)
            exchange(&a[i],&a[j]);
        else if(i>=j)
        {
            flag=1;
            exchange(&a[j],&a[p]);
            return (j);
        }
    }
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