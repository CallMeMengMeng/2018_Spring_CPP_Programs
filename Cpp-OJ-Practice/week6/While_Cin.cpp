#include <iostream>
using namespace std;
class MyCin
{
// 在此处补充你的代码
private:
    bool Flag=1;
public:
    MyCin & operator>>(int &is)
    {
        if(Flag){cin>>is;}
        if(is==-1){Flag=0;}
        return *this;
    }
    operator bool(){return Flag;}
};
int main()
{
    MyCin m;
    int n1,n2;
    while( m >> n1 >> n2)
        cout  << n1 << " " << n2 << endl;
    return 0;
}
