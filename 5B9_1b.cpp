//Program to perform towers of hanoi using recursion
#include<iostream>
using namespace std;
int TOH(int n, char s, char d, char i)
{
    if(n==1)
       cout<<"Move disc "<< n <<" from "<<s<<" to "<<d;
    else
    {
        TOH(n-1,s,i,d);
        cout<<"\nMove disc "<< n <<" from "<<s<<" to "<<d<<"\n";
        TOH(n-1,i,d,s);
    }   
}
int main()
{
    int n;
    char s,d,i;
    cout<<"Enter the number of discs : ";
    cin>>n;
    cout<<"Enter the discs\n";
    cin>>s;
    cin>>d;
    cin>>i;
    TOH(n,s,d,i);
}