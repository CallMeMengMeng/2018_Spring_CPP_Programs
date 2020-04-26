#include<iostream>
using namespace std;

class A
{
public:
    virtual ~A(){
    cout<<"A::~A() called"<<endl;
    }
};
class B:public A
{
    char *buf;
public:
    B(int i) {buf=new char[i];}
    virtual ~B()
    {
        delete []buf;
        cout<<"B::~B() called"<<endl;
    }
};
void fun(A *a)
{
    delete a;
}
int main()
{
    A*a=new B(10);
    fun(a);
    return 0;
}
