#include<fstream>
using namespace std;

int main()
{
    ofstream outFile("test.txt");
    outFile<<"123\r\n";
    outFile<<"321\r\n";
    outFile.close();
    return 0;
}
