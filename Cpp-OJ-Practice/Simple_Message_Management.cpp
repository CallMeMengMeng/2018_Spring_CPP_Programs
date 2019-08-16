#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Student {
private:
char name[20];
int age;
char num[20];
double average,y1,y2,y3,y4;
    public:
int x,y;
void input(){
    char a[20];
    cin.getline(a,20,',');
    x=strlen(a);
    for(int i=0;i<x;i++){
name[i]=a[i];
    }
    int b;
    char k;
    cin>>b>>k;
    age=b;
    char c[20];
    cin.getline(c,20,',');
    y=strlen(c);
    for(int i=0;i<y;i++){
num[i]=c[i];
    }
    cin>>y1>>k>>y2>>k>>y3>>k>>y4;
}
void calculate(){
    average=(y1+y2+y3+y4)/4;
}
void output(){
    for(int j=0;j<x;j++){
cout<<name[j];
    }
    cout<<','<<age<<',';
            for(int j=0;j<y;j++){
cout<<num[j];
    }
    cout<<','<<average<<endl;
}
};

int main() {
Student student;        // 定义类的对象
student.input();        // 输入数据
student.calculate();    // 计算平均成绩
student.output();       // 输出数据
}
