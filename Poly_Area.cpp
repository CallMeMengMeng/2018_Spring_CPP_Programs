#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
class CShape
{
public:
    virtual double Area()=0;
    virtual void PrintInfo()=0;
};
class CRectangle:public CShape
{
public:
    int w,h;
    virtual double Area();
    virtual void PrintInfo();
};
class CCircle:public CShape
{
public:
    int r;
    virtual double Area();
    virtual void PrintInfo();
};
class CTriangle:public CShape
{
    int a,b,c;
    double p=(a+b+c)/2.0;
    virtual double Area();
    virtual void PrintInfo();
};
double CRectangle::Area(){return w*h;}
  void CRectangle::PrintInfo(){cout<<"Rectangle:"<<Area()<<endl;}
double CCircle::Area(){return 3.1415*r*r;}
  void CCircle::PrintInfo(){cout<<"Circle:"<<Area()<<endl;}
double CTriangle::Area(){return sqrt(p*(p-a)*(p-b)*(p-c));}
  void CTriangle::PrintInfo(){cout<<"Triangle:"<<Area()<<endl;}
CShape * pShapes[1000];
int MyCompare(const void * s1,const void * s2);
int main()
{
    int i,n;
    CRectangle *pr;
    CCircle *pc;
    CTriangle *pt;
    cin>>n;
    for(i=0;i<n;i++)
}
