//出现次数最多的数字
#include<iostream>
#include<cstring>
#include<list>
#include<vector>
#include<math.h>
#include<map>
using namespace std;

int main()
{
    int n;
    cin>>n;
    map<int,int> M;
    for(int i=0;i<n;i++)
    {
        int item;
        cin>>item;
        M[item]++;
    }
    int ans=0;
    int a=0;
    for(map<int,int>::iterator it=M.begin();it!=M.end();it++)
    {
        if(it->second>a)
        {
            a=it->second;
            ans=it->first;
        }
    }
    cout<<ans<<endl;
    return 0;
}
