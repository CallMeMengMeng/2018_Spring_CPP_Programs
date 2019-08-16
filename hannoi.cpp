#include<iostream>
using namespace std;

void hannoi(int no, char a, char b, char c, int ns)
{
    if(no==1)
    {
        cout<<"Move plate "<<ns<<" from "<<a<<" to "<<c<<"."<<endl;
    }
    else
    {
        hannoi(no-1,a,c,b,ns-1);
        cout<<"Move plate "<<ns<<" from "<<a<<" to "<<c<<"."<<endl;
        hannoi(no-1,b,a,c,ns-1);
    }
}

int main()
{
    int n;
    cout<<"Please input the count of plate:"<<endl;
    cin>>n;
    hannoi(n,'x','y','z',n);
    return 0;
}
