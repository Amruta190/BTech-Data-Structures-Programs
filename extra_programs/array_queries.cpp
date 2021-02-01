#include<iostream>
using namespace std;
void add_to_front(int p, int q,int n,int arr[])
{
    int i,j,tmp;
    while(p!=0)
    {
        for(i=p;i<=q;i++)
        {
            tmp=arr[i];
            arr[i]=arr[i-1];
            arr[i-1]=tmp;
        }
        p--;
        q--;
    }
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
}
void add_to_back(int p,int q, int n,int arr[])
{
    int i,j,tmp;
    while(q!=n-1)
    {
        for(i=q;i>=p;i--)
        {
            tmp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=tmp;
        }
        q++;
        p++;
    }
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
}
int main()
{
    int i,j,n,k,arr[100],a[5];
    cout<<"Enter array length : ";
    cin>>n;
    cout<<"Enter array elements : ";
    for(i=0;i<n;i++)
        cin>>arr[i];
    cout<<"No.of test cases : ";
    cin>>k;
    for(i=0;i<k;i++)
    {
        cout<<"Test case "<<i<<":";
        for(j=0;j<3;j++)
            cin>>a[j];
        if(a[1]<=a[2] && a[2]<n && (a[0]>=1&&a[0]<=2))
        {
            if(a[0]==1)
                add_to_front(a[1],a[2],n,arr);
            else if(a[0]==2)
                add_to_back(a[1],a[2],n,arr);
        }
        else
            cout<<"Invalid input!!\n";
    }
}