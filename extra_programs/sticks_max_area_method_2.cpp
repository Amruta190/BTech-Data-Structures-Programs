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
void max_area(int fc[],int len)
{
    int i,area=1,count=0,flag=0;
    for(i=len-1;i>=0;i--)
    {
        if(fc[i]>3)
        {
            area=i*i;
            flag=1;
            break;
        }
        else if(fc[i]>1)
        {
            count++;
            area=area*i;
            if(count>1)
            {
                flag=1;
                break;
            }
        }
    }
    if(flag==0)
        cout<<"Not Possible";
    else
        cout<<"The maximum area is : "<<area;
}
void frequency_count(int arr[], int k)
{
    int i,j,count=0;
    int n=arr[k-1];
    int fc[n+1];
    for(i=0;i<n+1;i++)
    {
        count=0;
        for(j=0;j<k;j++)
        {
            if(i==arr[j])
            count++;
        }
        fc[i]=count;
    }
    max_area(fc,n+1);
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
    frequency_count(arr,k);
}