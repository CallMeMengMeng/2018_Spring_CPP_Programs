#include<iostream>
#include<stdio.h>
using namespace std;
 inline char* Atest(int a)
 {
     return (a%2>0)? "��":"ż";
 }

 int main()
 {
     int i;
     for(i=1;i<100;i++){printf("i:%d   ��ż��:%s \n",i,Atest(i));}
     return 0;
 }
