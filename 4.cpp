#include<iostream>
using namespace std;
int main ()
{
    int m,n;
    cin>>m>>n;
    int a[1000][1000];
    for (int i=0;i<m+2;i++)
        {
            for (int j=0;j<n+2;j++)
            {
                a[i][j]=0;
            }
        }
        for (int i=1;i<m+1;i++)
            {
                for (int j=1;j<n+1;j++)
                {
                    cin>>a[i][j];
                }
            }
            for (int i=1;i<m+1;i++)
                {
                    for (int j=1;j<n+1;j++)
                    {
                         if (a[i][j]>=a[i][j+1]&&a[i][j]>=a[i][j-1]&&a[i][j]>=a[i-1][j]&&a[i][j]>=a[i+1][j])
                            { cout<<i-1<<" "<<j-1<<endl;
                            }
                    }
                }
                return 0;
}
