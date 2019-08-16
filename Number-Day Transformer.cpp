#include<iostream>
using namespace std;

int main() {
int day;
cout<<"====THIS IS NUMBER-DAY TRANSFORMER===="<<endl;
cout<<"Please enter a number(from 0 to 6):";
cin>>day;

switch(day){
case 0:
    cout<<"Sunday"<<endl;
    break;
case 1:
    cout<<"Monday"<<endl;
    break;
case 2:
    cout<<"Tuesday"<<endl;
    break;
case 3:
    cout<<"Wednesday"<<endl;
    break;
case 4:
    cout<<"Thursday"<<endl;
    break;
case 5:
    cout<<"Friday"<<endl;
    break;
case 6:
    cout<<"Saturday"<<endl;
    break;
default:
    cout<<"Sorry, the day out of a week..."<<endl;
    break;
    }
    return 0;
    }
