#include<iostream>
using namespace std;
void sort(int arr[], int k)
{
    int temp,i,j;
    for (i=0;i<k;i++) 
    {
        for (j=i+1;j<k;j++)
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
void max_area(int arr[], int k)
{
    int i,j,a=0,b=0,count=0,flag=0;
    for(i=k-1;i>=0;i--)
    {
        if(arr[i]==arr[i-1])
        {
            while(arr[i]==arr[i-1])
            {
                i--;
                count++;
            }
            if(count>=3)
            {
                a=arr[i];
                flag=1;
                break;
            }
            else
            {
                a=arr[i];
                break;
            }
        }
    }
    for(j=i;j>=0;j--)
    {
        if(arr[j]==arr[j-1])
        {
            b=arr[j];
            break;
        }
    }
    if(flag==1)
        cout<<"The maximum area is : "<<a*a;
    else
    {
        if(a*b==0)
            cout<<"Not Possible\n";
        else
            cout<<"The maximum area is : "<<a*b;
    }
}
int main()
{
    int k,arr[100],i;
    cout<<"Enter array length : ";
    cin>>k;
    cout<<"Enter array values : ";
    for(i=0;i<k;i++)
        cin>>arr[i];
    sort(arr,k);
    max_area(arr,k);
}