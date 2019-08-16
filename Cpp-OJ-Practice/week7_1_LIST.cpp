#include<iostream>
#include<map>
#include<list>
#include<string>
using namespace std;
int main()
{
    map <int,list<int> > m;
    int N,n;
        cin>>N;

             while(N--)
            {
                string option;
                cin>>option;
                if(option=="new")
                {    int id;
                    cin>>id;
                    m[id]=list<int>();
                }
                if(option=="add")
                {
                    int id,n;
                    cin>>id>>n;
                    m[id].sort();
                    m[id].push_back(n);
                }
                if(option=="merge")
                {
                    int id1,id2;
                    cin>>id1>>id2;
                    m[id1].merge(m[id2]);
                }
                if(option=="unique")
                {
                    int id;
                    cin>>id;
                    m[id].sort();
                    m[id].unique();
                }
                if(option=="out")
                {
                    int id;
                    cin>>id;
                    m[id].sort();
                    list<int>::iterator p;
                    for(p=m[id].begin();p!=m[id].end();p++)
                        cout<<*p<<" ";
                    cout<<endl;
                }
            }
    return 0;

}
