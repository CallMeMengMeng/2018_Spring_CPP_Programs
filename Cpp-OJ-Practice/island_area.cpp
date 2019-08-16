#include <iostream>
#include<cstring>
using namespace std;
int a[102][102];
int m,n;
int island[][2]={1,0,-1,0,0,1,0,-1};
int main()
{
    int total=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        cin>>a[i][j];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
                if(a[i][j]==1)
            for(int k=0;k<4;k++){
                int nx=i+island[k][0];
                int ny=j+island[k][1];
                if(a[nx][ny]==0)
                    total++;
            }
        }
    }
    cout<<total<<endl;
    return 0;
}

