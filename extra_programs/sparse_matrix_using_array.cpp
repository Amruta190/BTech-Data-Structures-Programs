#include<iostream>
using namespace std;
int main()
{
    int m,n,i,j,arr[100][100],arr1[3][100],k=1;
    cout<<"Enter no.of rows of sparse matrix : ";
    cin>>m;
    cout<<"Enter no.of columns of sparse matrix : ";
    cin>>n;
    if(n>0 && m>0)
    {
        cout<<"Enter sparse matrix : ";
        for(i=1;i<=m;i++)
            for(j=1;j<=n;j++)
                cin>>arr[i][j];
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(arr[i][j]!=0)
                {
                    arr1[0][k]=i;
                    arr1[1][k]=j;
                    arr1[2][k++]=arr[i][j];
                }
            }
        }
        if(k==1)
            cout<<"Sparse matrix is:\nEmpty";
        else
        {
            cout<<"Sparse matrix is:\n";
            cout<<"Row  Col  Value\n";
            for(i=1;i<k;i++)
            {
                cout<<" "<<arr1[0][i]<<"   ";
                cout<<" "<<arr1[1][i]<<"   "; 
                cout<<" "<<arr1[2][i]<<"\n";
            }
        }
    }
    else
        cout<<"Enter correct input!!";
}