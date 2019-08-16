#include<iostream>
#include<set>
#include<iterator>

using namespace std;

bool isprime(int n)
{
    for(int i=2;i*i<=n;i++)return 0;
    return 1;
}
int get(int n)
{
    int count=0;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            int k=n/i;
            if(k!=i&&isprime(k))count++;
            if(isprime(i))count++;
        }
    }
    return count;
}
class num
{
public:
    int big,pr;
    num(int n){big=n;pr=get(n);}
    friend bool operator < (num a,num b)
    {
        if(a.pr!=b.pr)
            return a.pr<b.pr;
        else
        return a.big<b.big;
    }
    friend bool operator == (num a,num b){return a.pr==b.pr;}
};
int main()
{
    set<num> s;
    int n;
    cin>>n;
    while(n--)
    {
        for(int i=0;i<10;i++)
        {
            int N;
            cin>>N;
            num temp(N);
            s.insert(temp);
        }
        cout<<s.rbegin()->big<<" "<<s.begin()->big<<endl;
        s.erase(*s.begin());
        s.erase(*s.rbegin());
        return 0;
    }
}
