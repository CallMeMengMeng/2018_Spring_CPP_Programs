#include<iostream>
//#include<cstdio>
#include<string.h>
using namespace std;
int main()
{
    char s1[100020];
    char s2[100020];
    cin>>s1;
    cin>>s2;
    int len1=strlen(s1);
    int len2=strlen(s2);
    int i,j;
    int n1=0,n2=0;
    int count=1;
    int num1=0;
    int s1_num[100020];
    for(i=0;i<len1;i++)
    {
        if(s1[i+1]=='.'||i==len1-1){
                count=1;
        for(j=i;s1[j]!='.'&&j>=0;j--)
        {
            s1_num[num1]+=(s1[j]-'0')*count;
            count*=10;
        }
        num1++;
    }

    }
 count=1;
   int num2=0;
  int s2_num[100020];
    for(i=0;i<len2;i++)
    {
        if(s2[i+1]=='.'||i==len2-1){
                count=1;
        for(j=i;s2[j]!='.'&&j>=0;j--)
        {
            s2_num[num2]+=(s2[j]-'0')*count;
            count*=10;
        }
        num2++;}
    }
    //for(i=0;i<num1||i<num2;i++)
    //    cout<<s1_num[i]<<" "<<s2_num[i]<<endl;
    for(i=0;i<num1||i<num2;i++)
    {
        if(s1_num[i]!=s2_num[i])break;
    }
    if(s1_num[i]>s2_num[i])
        cout<<s1<<endl;
    else
        cout<<s2<<endl;;
    return 0;

}
