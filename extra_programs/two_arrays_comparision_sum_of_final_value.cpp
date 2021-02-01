#include<iostream>
using namespace std;
void sort(int arr[], int n)
{
    int i,j,temp;
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
int main()
{
    int i,j,a[100],b[100],m,n,flag=0,c[100],count=0,sum=0,k,r=0;
    cout<<"Length of 1st array : ";
    cin>>m;
    cout<<"Elements of 1st array : ";
    for(i=0;i<m;i++)
        cin>>a[i];
    sort(a,m);
    cout<<"Length of 2nd array : ";
    cin>>n;
    cout<<"Elements of 2nd array : ";
    for(i=0;i<n;i++)
        cin>>b[i];
    sort(b,n);   
    for(i=0;i<m;i++)
    {
        flag=0;
        for(j=0;j<n;j++)
        {
            if(a[i]==b[j])
                flag++;
        }
        if(flag==0)
        {
            cout<<a[i]<<" ";
            c[count]=a[i];
            count++;
        }
    }
    for(j=0;j<n;j++)
    {
        flag=0;
        for(i=0;i<m;i++)
        {
            if(b[j]==a[i])
                flag++;
        }
        if(flag==0)
        {
            cout<<b[j]<<" ";
            c[count]=b[j];
            count++;
        }
    }
    cout<<"\n";
    for(i=0;i<count;i++)
        sum=sum+c[i];
    cout<<sum<<"\n";
    while(sum>0)
    {
        k=sum%10;
        r=r+k;
        sum=sum/10;
    }
    cout<<r<<"\n";
}