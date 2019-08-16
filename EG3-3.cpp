#include<iostream>
using namespace std;

float arctan(float x)
{
    float sqr=x*x;
    float e=x;
    float r=0;
    int i=1;
    while (e/i>1e-15)
    {
        float f=e/i;
        r=(i%4==1)?r+f:r-f;
        e=e*sqr;
        i+=2;
    }
    return r;
}

int main()
{
    cout<<"====¼ÆËã¦ĞÖµ===="<<endl;
    float a=16.0*arctan(1/5.0);
    float b=4.0*arctan(1/239.0);
    cout<<"PI="<<a-b<<endl;
    return 0;
}
