#include<iostream>
using namespace std;

int main()
{
    int i=1,sum=0;
    int n;
    cout<<"Please enter a number:";
    cin>>n;
    while (i<=n) {
        sum +=i;
        i++;
    }
    cout<<"Sum="<<sum<<endl;
    return 0;
}
