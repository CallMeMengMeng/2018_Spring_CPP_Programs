#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
template <class T>
class CArray3D
{
// 在此处补充你的代码
    class CArray2D
    {
    private:
        T *p;
        int i,j;
    public:
        CArray2D(){}
        void getset(int _i,int _j){i=_i;j=_j;p=new T[i*j];}
        ~CArray2D(){delete []p;}
        T* operator[](int _i){return p + _i*j;}
        operator T*() {return this->p;}

    };
    private:
        CArray2D* a;
    public:
        ~CArray3D(){delete []a;}
        CArray3D(int _k,int _i,int _j)
        {
            a=new CArray2D[_k];
            for(int i=0;i<_k;i++)a[i].getset(_i,_j);
        }
        CArray2D& operator[](int _k){return a[_k];}

};

CArray3D<int> a(3,4,5);
CArray3D<double> b(3,2,2);
void PrintA()
{
    for(int i = 0;i < 3; ++i) {
        cout << "layer " << i << ":" << endl;
        for(int j = 0; j < 4; ++j) {
            for(int k = 0; k < 5; ++k)
                cout << a[i][j][k] << "," ;
            cout << endl;
        }
    }
}
void PrintB()
{
    for(int i = 0;i < 3; ++i) {
        cout << "layer " << i << ":" << endl;
        for(int j = 0; j < 2; ++j) {
            for(int k = 0; k < 2; ++k)
                cout << b[i][j][k] << "," ;
            cout << endl;
        }
    }
}

int main()
{

    int No = 0;
    for( int i = 0; i < 3; ++ i ) {
        a[i];
        for( int j = 0; j < 4; ++j ) {
            a[j][i];
            for( int k = 0; k < 5; ++k )
                a[i][j][k] = No ++;
            a[j][i][i];
        }
    }
    PrintA();
    memset(a[1],-1 ,20*sizeof(int));
    memset(a[1],-1 ,20*sizeof(int));
    PrintA();
    memset(a[1][1],0 ,5*sizeof(int));
    PrintA();

    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 2; ++j )
            for( int k = 0; k < 2; ++k )
                b[i][j][k] = 10.0/(i+j+k+1);
    PrintB();
    int n = a[0][1][2];
    double f = b[0][1][1];
    cout << "****" << endl;
    cout << n << "," << f << endl;

    return 0;
}
