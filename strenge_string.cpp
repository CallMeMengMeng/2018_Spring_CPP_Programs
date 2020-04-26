#include<iostream>
#include<cstring>
using namespace std;
class String{
private:
    char *str;
public:
    String():str(NULL) {}
    const char *c_str() {return str;}
    char *operator=(const char *s);
    ~String();
    };
    char *String::operator=(const char*s){
    if(str) delete [] str;
    if(s) {
        str =new char[strlen(s)+1];
        strcpy(str,s);
    }
    else
        str= NULL;
    return str;
    }
    String::~String(){
    if(str) delete [] str;
    };
    int mian(){
    String s;
    s="GOODLUCK,";
    cout<<s.c_str()<<endl;
    s="shenzhou 8!";
    cout<<s.c_str()<<endl;
    return 0;
    }
