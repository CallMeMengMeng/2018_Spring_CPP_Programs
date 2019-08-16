#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
// 在此处补充你的代码
class MyString
{public:
char p[100] = {'\0'};
int len = 0;
 MyString & operator=(const MyString & t)
{
len = t.len;
strcpy(p,t.p);
return *this;
}

MyString(){}
MyString(const char * t){
                len = strlen(t);
                strcpy(p,t);
            }
~MyString(){}
friend ostream & operator<<(ostream & os, const MyString & t){
                os << t.p;
                return os;
            }
MyString operator+(const MyString & temp){
                MyString r;
                r.len = len + temp.len;
                strcpy(r.p,p);
                strcat(r.p,temp.p);
                return r;
            }
char & operator[](int n){
                return p[n];
            }
MyString & operator+=(const char * t){
                len += strlen(t);
                strcat(p,t);
                return *this;
            }
friend MyString operator+(const char* t, MyString & m){
                MyString r;
                r.len = strlen(t) + m.len;
                strcpy(r.p,t);
                strcat(r.p,m.p);
                return r;
            }
MyString & operator=(const char * t){
                for (int i = 0; i < len; i++)
                    p[i] = '\0';
                len = strlen(t);
                strcpy(p,t);
                return * this;
            }
            int operator < (const MyString & t)
            {   int i=strcmp(p,t.p);
            if(i==-1)return 1;
            else return 0;
            }
            int operator > (const MyString & t)
            {    int i=strcmp(p,t.p);
                 if(i==1)return 1;
                 else return 0;

            }
int operator== (const MyString & t){
            int i=strcmp(p,t.p);
            if(i==0)return 1;
            else return 0;
            }
MyString operator()(int x, int y){
                MyString r;
                for (int i = x, j = 0; j< y; i++, j++)
                    r.p[j] = p[i];
                return r;
            }

};

int main() {
    MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
    MyString SArray[4] = {"big","me","about","take"};
    cout << "1. " << s1 << s2 << s3<< s4<< endl;
    s4 = s3;    s3 = s1 + s3;
    cout << "2. " << s1 << endl;
    cout << "3. " << s2 << endl;
    cout << "4. " << s3 << endl;
    cout << "5. " << s4 << endl;
    cout << "6. " << s1[2] << endl;
    s2 = s1;    s1 = "ijkl-";
    s1[2] = 'A' ;
    cout << "7. " << s2 << endl;
    cout << "8. " << s1 << endl;
    s1 += "mnop";
    cout << "9. " << s1 << endl;
    s4 = "qrst-" + s2;
    cout << "10. " << s4 << endl;
    s1 = s2 + s4 + " uvw " + "xyz";
    cout << "11. " << s1 << endl;
    sort(SArray,SArray+4);
    for( int i = 0;i < 4;++i )
        cout << SArray[i] << endl;
    //输出s1从下标0开始长度为4的子串
    cout << s1(0,4) << endl;
    //输出s1从下标为5开始长度为10的子串
    cout << s1(5,10) << endl;
    return 0;
}
