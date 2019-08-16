#include<iostream>
#include<string>
#include<list>
#include<map>
using namespace std;
int main()
{
    map<int,list<int>> m;
    int n,nu;
    cin>>n;
    while(n--)
    {
        string operation;
        cin>>operation;
        if(operation=="new")
        {
            int id;
            cin>>id;
            m[id]=list<int>();
        }
        else if(operation=="add")
        {
            int id,nu;
            cin>>id>>nu;
            m[id].push_back(n);
        }
        else if(operation=="merge")
        {
            int id1,id2;
            cin>>id1>>id2;
            m[id1].merge(m[id2]);
        }
        else if(operation=="unique")
        {
            int id;
            cin>>id;
            m[id].sort();
            m[id].unique();
        }
        else if(operation=="out")
        {
            int id;
            cin>>id;
            m[id].sort();
            list<int>::iterator p;
            for(p=m[id].begin();p!=m[id].end();p++)cout<<*p<<" "<<endl;
        }
    }
    return 0;
}
