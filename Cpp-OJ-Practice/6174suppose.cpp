#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t,n,a[4],n1,n2,s;
    cout<<"Please enter a digital:"<<endl;
    cin>>n;
        s=0;
        while(n!=6174)
        {
            a[0]=n%10;
            a[3]=n/1000;
            a[1]=n/10%10;
            a[2]=n/100%10;
            sort(a,a+4);
            n1=1000*a[3]+100*a[2]+10*a[1]+a[0];
            n2=1000*a[0]+100*a[1]+10*a[2]+a[3];
            n=n1-n2;
            cout<<n1<<"-"<<n2<<"="<<n<<endl;
            s++;
        }
        cout<<s<<endl;
    return 0;
}
