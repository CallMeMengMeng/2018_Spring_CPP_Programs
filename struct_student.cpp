#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

struct student
{
    int num;
    string name;
    char sex;
    int age;
};

int main()
{
    student stu={9007,"Lin",'F',18};
    cout<<"NUM:    "<<stu.num<<endl;
    cout<<"NAME:  "<<stu.name<<endl;
    cout<<"SEX:     "<<stu.sex<<endl;
    cout<<"AGE:    "<<stu.age<<endl;
    return 0;
}
