#include<iostream>
#include<list>
using namespace std;
void fwrprint(list<int> &l1)
{
    for(auto i=l1.begin();i!=l1.end();i++)
        cout<<*i<<" ";
}
void bwrprint(list<int> &l1)
{
    for(auto i=l1.rbegin();i!=l1.rend();i++)
        cout<<*i<<" ";
}
int main()
{
    int op,ins,n,pos;
    list<int> l1;
    while(true)
    {
        cout<<"\nPlease select an option : ";
        cout<<"\n1.Insert  2.Delete  3.Print  4.Exit\n";
        cin>>op;
        switch(op)
        {
            case 1:
            {
                cout<<"1.Insert at Beginning\t2.Insert at the end\t3.Insert at a position\n";
                cin>>ins;
                cout<<"Please enter the key value : ";
                cin>>n;
                switch(ins)
                {
                    case 1:l1.push_front(n);
                            break;
                    case 2:l1.push_back(n);
                            break;
                    case 3:cout<<"Enter the position : "; 
                            cin>>pos;
                            auto k=l1.begin();
                            int pos1=1;
                            while(pos1!=pos)
                            {
                                k++;
                                pos1++;
                            }
                            l1.insert(k,n);
                            break;
                }
                break;
            }
            case 2:cout<<"\n1.Delete at Beginning\t2.Delete at the end\t3.Delete at a position\n";
            cin>>ins;
            switch(ins)
            {
                case 1:l1.pop_front();
                        break;
                case 2:l1.pop_back();
                        break;
                case 3:cout<<"Enter the position : ";
                        cin>>pos;
                        auto k=l1.begin();
                        int pos1=1;
                        while(pos1!=pos)
                        {
                            k++;
                            pos1++;
                        }
                        l1.erase(k);
                        break;
            }
            break;
            case 3:cout<<"\n1.Forward Print\t2.Backward Print\n";
            cin>>ins;
            switch(ins)
            {
                case 1:fwrprint(l1);
                        break;
                case 2:bwrprint(l1);
                        break;
            }
            break;
            case 4:exit(0);
        }
    }
}