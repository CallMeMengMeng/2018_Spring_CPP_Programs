#include<iostream>
using namespace std;

const float PI=3.141593;
const float Fence_Price=35;
const float Concrete_Price=20;

class Circle
{
public:
    Circle(float r);
    float circumference();
    float area();

private:
    float radius;
};

Circle::Circle(float r)
{
    radius=r;
}

float Circle::circumference()
{
    return 2*radius*PI;
}

float Circle::area()
{
    return PI*radius*radius;
}

int main()
{
    float radius;
    cout<<"Enter the radius of the pool:"<<endl;
    cin>>radius;
    Circle pool(radius);
    Circle poolRim(radius+3);

    float fenceCost=poolRim.circumference()*Fence_Price;
    cout<<"Fencing Cost is $"<<fenceCost<<endl;

    float concreteCost=(poolRim.area()-pool.area())*Concrete_Price;
    cout<<"Concrete Cost is $"<<concreteCost<<endl;

    return 0;
}
