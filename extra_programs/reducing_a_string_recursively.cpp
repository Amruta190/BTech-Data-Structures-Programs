#include<iostream>
#include<string.h>
using namespace std;
void reduce_len(char st[])
{
    int i,j,len,l;
    len=strlen(st);
    l=len;
    for(i=0;i<l;i++)
    {
        if(st[i]==st[i+1])
        {
            for(j=i;j<l;j++)
                st[j]=st[j+2];
            l=l-2;
            i--;
        }
    }
    if(strlen(st)!=len)
        reduce_len(st);
    else
    {
        if(st[0]!='\0')
            puts(st);
        else 
            cout<<"Empty String";
    }
}
int main()
{
    char str[100];
    gets(str);
    reduce_len(str);
}