#include<iostream>
#include<deque>
using namespace std;
void print(deque<int> &dq)
{
    for(auto i=dq.begin();i!=dq.end();i++)
        cout<<*i<<" ";
}
int main()
{
    deque<int> dq;
    int n,k,ins;
    while(true)
    {
        cout<<"\n1. Insert    2. Delete   3. Print    4. Exit";
        cout<<"\nSelect an option : ";
        cin>>n;
        switch (n)
        {
            case 1: cout<<"1. Insert at beginning   2. Insert at end : ";
                    cin>>ins;
                    switch(ins)
                    {
                        case 1: cout<<"\nEnter the element to insert : ";
                                cin>>k;
                                dq.push_front(k);
                                break;  
                        case 2: cout<<"\nEnter the element to insert : ";
                                cin>>k;
                                dq.push_back(k);
                                break;  
                    }
                    break;
            case 2: cout<<"1. Delete at beginning   2. Delete at end : ";
                    cin>>ins;
                    switch(ins)
                    {
                        case 1: dq.pop_front();
                                break;  
                        case 2: dq.pop_back();
                                break;  
                    }
                    break;
            case 3:print(dq);
                    break;
            case 4:exit(0);
        }
    }
}