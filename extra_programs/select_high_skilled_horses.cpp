#include<iostream>
#include<cstdlib>
using namespace std;
void sort(int arr[], int n)
{
    int temp,i,j;
    for (i=0;i<n;i++) 
    {
        for (j=i+1;j<n;j++)
        {
            if (arr[i] > arr[j]) 
            {
                temp  =  arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void skilled_horses(int arr[],int diff[],int n)
{
    int min=diff[0],a[n-1],i,j=0;
    for(i=0;i<n-1;i++)
        a[i]=-1;
    for(i=1;i<n-1;i++)
    {
        if(min>diff[i])
        {
            min=diff[i];
        }
    }
    for(i=0;i<n-1;i++)
    {
        if(min==diff[i])
        {
            a[j]=i;
            j++;
        }
    }
    i=0;
    while(a[i]!=-1)
    {
        cout<<"The skill numbers of two horses are : "<<arr[a[i]]<<" and "<<arr[a[i]+1]<<"\n";
        i++;
    }
}
void adjacent_value_difference(int arr[], int n)
{
    int diff[n-1],i;
    for(i=0;i<n-1;i++)
    {
        diff[i]=abs(arr[i]-arr[i+1]);
    }
    skilled_horses(arr,diff,n);
}
int main()
{
    int n,arr[100],i;
    cout<<"Enter array length : ";
    cin>>n;
    cout<<"Enter array values : ";
    for(i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,n);
    adjacent_value_difference(arr,n);
}