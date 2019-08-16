#include<iostream>
using namespace std;

int main()
{
    int i=0,j=0,n;
    cout<<"Please enter a group of numbers(enter 0 to quit):";
    cin>>n;
    while(n!=0)
    {
        if(n>0) i+=1;
        if(n<0) j+=1;
        cin>>n;
    }
    cout<<"Count of positive is:"<<i<<endl;
    cout<<"Count of negative is:"<<j<<endl;
    return 0;
}
