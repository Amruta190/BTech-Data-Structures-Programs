#include<iostream>
using namespace std;
int main()
{
    int n,arr[102][102],i,j,k=1,flag=0;
    char ch;
    cout<<"Enter number : ";
    cin>>n;
    for(i=1;i<=100;i++)
        for(j=1;j<=100;j++)
            arr[i][j]=0;
    i=j=50;
    arr[i][j]=k++;
    ch='r';
    switch(ch)
    {
        case 'r':if(k<=n)
                {
                    j+=1;
                    arr[i][j]=k++;
                }
        case 'd':if(k<=n)
                {
                    i+=1;
                    arr[i][j]=k++;
                }
        case 'l':if(k<=n)
                {
                    j-=1;
                    arr[i][j]=k++;
                }
        case 'u':if(k<=n)
                {
                    j-=1;
                    arr[i][j]=k++;
                }
    }
    while(k<=n)
    {
        ch='u';
        switch(ch)
        {
            case 'u':if(k<=n)
            {
                i-=1;
                while(k<=n&&arr[i][j+1]!=0)
                {
                    arr[i][j]=k++;
                    i-=1;
                }
                if(k<=n)
                {
                    arr[i][j]=k++;
                }
            }
            case 'r':if(k<=n)
            {
                j+=1;
                while(k<=n&&arr[i+1][j]!=0)
                {
                    arr[i][j]=k++;
                    j+=1;
                }
                if(k<=n)
                {
                    arr[i][j]=k++;
                }
            }
            case 'd':if(k<=n)
            {
                i+=1;
                while(k<=n&&arr[i][j-1]!=0)
                {
                    arr[i][j]=k++;
                    i+=1;
                }
                if(k<=n)
                {
                    arr[i][j]=k++;
                }
            }
            case 'l':if(k<=n)
            {
                j-=1;
                while(k<=n&&arr[i-1][j]!=0)
                {
                    arr[i][j]=k++;
                    j-=1;
                }
                if(k<=n)
                {
                    arr[i][j]=k++;
                }
            }
        }
    }
    for(i=1;i<=100;i++)
    {
        for(j=1;j<=100;j++)
        {
            if(arr[i][j]!=0)
            {
                cout<<arr[i][j]<<"    ";
                flag=1;
            }
        }
        if(flag!=0)
        {
            cout<<"\n";
            flag=0;
        }
    }
}