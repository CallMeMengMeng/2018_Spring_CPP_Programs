#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<string.h>
using namespace std;
int island[500][500];
int total=0;
void cal(int x,int y)
{
    int dx[]={1,0,-1,0};
    int dy[]={0,1,0,-1};
    int i;
    for(i=0;i<4;i++)
    {   int nx=x+dx[i];
        int ny=y+dy[i];
        if(island[nx][ny]==0)
            total++;
    }

}
int main()
{
    int n,m,i,j;
    cin>>n>>m;
    memset(island,0,sizeof(0));
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        cin>>island[i][j];
    }

     for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
            if(island[i][j]==1)
                cal(i,j);
            }
            cout<<total<<endl;
            return 0;

}
