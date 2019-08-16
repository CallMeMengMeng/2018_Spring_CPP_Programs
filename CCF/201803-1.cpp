//ÌøÒ»Ìø
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;

int main()
{
    int arg[30];
    int m = 0;
    for(int i = 0;i < 30;i++)
    {
        cin>>arg[m];
        m++;
        if(arg[i]==0)break;
    }
    int num = 1;
    int score = 0;
    for(int i = 0; i < m;i++)
    {
        if(arg[i]==1)
        {
            score++;
            num = 1;
        }
        else if(arg[i]==2)
        {
            score+=2*num;
            num++;
        }
    }
    cout<<score<<endl;
    return 0;
}
