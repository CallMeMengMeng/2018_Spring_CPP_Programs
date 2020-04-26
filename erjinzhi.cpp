#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class CStudent
{
public:
    char szName[20];
    int nScore;
};
int main()
{
    CStudent s;
    ofstream OutFile("students.dat",ios::out|ios::binary);
    while (cin>>s.szName>>s.nScore)
    {
        if(stricmp(s.szName,"exit")==0)
            break;
        OutFile.write((char*) &s,sizeof(s));
    }
    OutFile.close();
    return 0;
}
