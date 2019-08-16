#include<iostream>
#include<string>
#include<set>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int UN[10000];
    multiset<int>S;
    while(n--)
    {
        string operation;
        cin>>operation;
        if(operation=="add")
        {
            int num;
            cin>>num;
            S.insert(num);
            UN[num]=1;
            cout<<S.count(num)<<endl;
        }
        else if(operation=="del")
        {
            int num;
            cin>>num;
            cout<<S.count(num)<<endl;
            S.erase(num);
        }
        else if(operation=="ask")
        {
            int num;
            cin>>num;
            set<int>::iterator i;
            i=S.find(num);
            if(UN[num]==1)cout<<"1";
            else cout<<"0";
            cout<<" "<<S.count(num)<<endl;
        }
    }
    return 0;
}
