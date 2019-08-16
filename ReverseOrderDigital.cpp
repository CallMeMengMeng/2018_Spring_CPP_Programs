#include<iostream>
using namespace std;

int main()
{
    int n,right_number,newnum=0;
    cout<<"Please enter a number:";
    cin>>n;

    cout<<"The number in reverse order is:";
    do {
        right_number=n%10;
        cout<<right_number;
        n/=10;
    }while(n!=0);
    cout<<endl;
    return 0;
}
