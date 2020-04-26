#include <iostream>
#include <cstring>
using namespace std;

class Matrix {
public:
	int ** p;
 int r,c;
    friend istream & operator >>(istream &in,Matrix &a)
    {
        in>>a.r>>a.c;
        a.p=new int *[a.r];
        for (int i=0;i<a.r;i++)
        {
            a.p[i]=new int [a.c];
        for(int j=0;j<a.c;j++)
        {
            in>>a.p[i][j];
        }
        return in;
        }
    }
    friend Matrix & operator * (Matrix &a,const Matrix &b)
    {
        int **t;
        t=new int *[a.r];
        for(int i=0;i<a.r;i++)
        {
            t[i]=new int [b.c];
            for (int k=0;k<b.c;k++)
            {
                t[i][k]=0;
            }
        }
    for (int i=0;i<a.r;i++)
    {
        for (int j=0;j<b.c;j++)
        {
            for(int k=0;k<a.c;k++)
            {
                t[i][k]+=b.p[k][j]*a.p[i][k];
                for(int i=0;i<a.r;i++)
                {
                    for(int k=0;k<b.c;k++)
                    {
                        a.p[i][j]=t[i][k];
                        a.c=b.c;
                        return a;
                    }
                }
            }
        }
    }
}
friend ostream & operator << (ostream &o, const Matrix &a){
		for(int i = 0;i < a.r;i ++){
			for(int j = 0;j < a.c;j ++) o << a.p[i][j] << " ";
			o << endl;
		}
		return o;
	}
};

int main() {
	Matrix a, b;
	cin >> a >> b;
	cout << a * b << endl;
    return 0;
}
