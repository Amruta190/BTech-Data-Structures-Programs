#include<iostream>
using namespace std;
void leftrotate(int a[], int l)
{
    int i,j,first;
    first=a[0];
    for(j=0;j<l-1;j++)
    {
        a[j]=a[j+1];
    }
    a[j]=first;
    cout<<"\nArray after left-rotation is : ";
    for(i=0;i<l;i++)
    {
        cout<<a[i]<<" ";
    }
}
void rightrotate(int a[], int l)
{
    int i,j,last;
    last=a[l-1];
    for(j=l-1;j>0;j--)
    {
        a[j]=a[j-1];
    }
    a[j]=last;
    cout<<"\nArray after right-rotation is : ";
    for(i=0;i<l;i++)
    {
        cout<<a[i]<<" ";
    }
}
int main()
{
    while(true)
    {
        cout<<"\nSelect one option :\n1. Enter array\n2. Left rotate\n3. Right rotate\n4. Exit";
        int p,i,n,l,a[10];;
        cin>>p;
        switch(p)
        {
            case 1 :cout<<"Enter array length : ";
                    cin>>l;
                    cout<<"Enter array elements : ";
                    for(i=0;i<l;i++)
                    cin>>a[i];
                    break;
            case 2 :leftrotate(a,l);
                    break;
            case 3 :rightrotate(a,l);
                    break;
            case 4 :exit(0);
        }
    }
}