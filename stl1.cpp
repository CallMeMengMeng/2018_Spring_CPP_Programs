#include<vector>
#include<iostream>
using namespace std;
int main()
{
    vector<int>v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    vector<int>::const _iterator i;
    for(i=v.begin();i!=v.end();++i)
        cout<<*i<<",";
    cout<<endl;
    vector<int>::reverse_iterator r;
    for(r=v.begin();r!=v.end;r++)
        cout<<*r<<",";
    cout<<endl;
    vector<int>::iterator j;
    for(j=v.begin();j!=v.end();j++)
        *j=100;
    for(i=v.begin();i!=v.end();i++)
        cout<<*i<<",";
}
