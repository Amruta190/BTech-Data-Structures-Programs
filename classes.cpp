#include<iostream>
using namespace std;
class A
{
    static int i;
    public:
    void init(int x)
    {
        i=x;
    }
    void show()
    {
        cout<<i;
    }
};
int A:: i;
int main()
{
    // A::init(100);
    A a;
    a.init(100);
    a.show();
}