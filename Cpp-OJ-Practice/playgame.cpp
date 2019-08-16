#include<iostream>
using namespace std;

int main()
{
    int group;
    cin>>group;
    for(int x=0;x<group;x++)
    {
        int M,X;
        cin>>M>>X;
        int a[500]={0};
        for(int i=0;i<M;i++)
        {
            cin>>a[i];
        }
        int temp=a[0];
        for (int i=0;i<X;i++)
        {
            for (int j=0;j<M-1;j++)
            {
                a[j]=(a[j]+a[j+1])%100;
            }
            a[M-1]=(a[M-1]+temp)%100;
            temp=a[0];
        }
        for (int i=0;i<M;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
