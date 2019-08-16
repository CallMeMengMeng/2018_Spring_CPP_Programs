/* 输入一个矩形的长和宽，输出矩形的面积以及周长 */
#include<iostream>
using namespace std;

class Rectangle
{
public:
    int width;
    int heigth;
    int Area(){return width*heigth;}
    int Premiere(){return 2*(width+heigth);}
    int Init(int width_,int heigth_)
    {
        width=width_;
        heigth=heigth_;
    }
};

/*int main()
{
    int w,h;
    cout<<"Please input the width and heigth of a rectangle."<<endl;
    cin>>w>>h;
    Rectangle r;
    cout<<sizeof(Rectangle)<<endl;
    r.Init(w,h);
    cout<<"The area is:"<<r.Area()<<endl;
    cout<<"The Premiere is:"<<r.Premiere()<<endl;
    return 0;
}*/

int main()
{
    int w=3,h=2;
    Rectangle r;
    Rectangle *pr1=&r;
    Rectangle &r1=r;
    pr1->Init(w,h);
    pr1->width=10;
    cout<<r.width<<endl;
    cout<<pr1->width<<endl;
    cout<<r1.width<<endl;
    return 0;
}
