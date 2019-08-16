//ISBNºÅÂë
#include<iostream>
#include<cstring>
#include<list>
#include<cmath>
#include<vector>
using namespace std;

int main()
{
    int a[10];
    string s;
    cin >> s;

    a[0] = s[0] - '0';
    a[1] = s[2] - '0';
    a[2] = s[3] - '0';
    a[3] = s[4] - '0';
    a[4] = s[6] - '0';
    a[5] = s[7] - '0';
    a[6] = s[8] - '0';
    a[7] = s[9] - '0';
    a[8] = s[10] - '0';
    a[9] = s[12] - '0';

/*    for(int i = 0; i < 10; i++)
    {
        cout<<a[i]<<endl;
    }*/
    int sum = 0;
    int j = 1;
    for(int i = 0; i < 9; i++)
    {
        sum += a[i]*j;
        j++;
    }
    //cout<<sum<<endl;
    int end = sum % 11;
    char c;
    if(end == 10)
        c = 'X';
    else
        c = end + '0';
    if(c == s[12])
        cout<<"Right"<<endl;
    else
    {
        s[12] = c;
        cout<<s<<endl;
    }
    return 0;
}
