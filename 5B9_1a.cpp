//Program to compute factorial of a given number using recursion
#include<iostream>
using namespace std;
int fact(int n)
{
    if(n<=0)
    return 1;
    else
    return n*fact(n-1);
}
int main()
{
   int n;
   cout<<"Enter the positive number\n";
   cin>>n;
   cout<<"Factorial of "<< n <<" is "<<fact(n);
}
