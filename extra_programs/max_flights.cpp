#include<iostream>
using namespace std;
int main()
{
    int n,p,q,r,i,count=0;
    cout<<"Please enter no.of days : ";
    cin>>n;
    cout<<"Please enter p value : ";
    cin>>p;
    cout<<"Please enter q value : ";
    cin>>q;
    cout<<"Please enter r value : ";
    cin>>r;
    for(i=1;i<=n;i++)
    {
        if(!(i%p==0||i%q==0))
        {
            if(i%r==0)
                count++;
        }
        if(!(i%p==0||i%r==0))
        {
            if(i%q==0)
                count++;
        }
        if(!(i%q==0||i%r==0))
        {
            if(i%p==0)
                count++;
        }
    }
    cout<<"Maximum no.of flights takeoff is : "<<count;
}