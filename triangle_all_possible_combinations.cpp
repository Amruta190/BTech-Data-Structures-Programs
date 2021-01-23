#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int a,b,c,count=0,d=0;
    for(a=1;a<100;a++)
    {
        for(b=1;b<100;b++)
        {
            for(c=1;c<100;c++)
            {
                if(pow(c,2)==pow(a,2)+pow(b,2))
                {
                    cout<<a<<" "<<b<<" "<<c<<"\n";
                    count++;
                }
            }
        }
    }
    cout<<count<<"\n";
}