#include<iostream>
#include<cstdlib>
using namespace std;

//模拟投掷骰子，计算并输出和数；
int rollDice()
{
    int die1=1+rand()%6;
    int die2=1+rand()%6;
    int sum=die1+die2;
    cout<<"player rolled "<<die1<<"+"<<die2<<"="<<sum<<endl;
    return sum;
}

enum GameStatus {WIN, LOSE, PLAYING};

int main()
{
    int sum, myPoint;
    GameStatus status;

    unsigned seed;
    cout<<"====投掷骰子的随机游戏===="<<endl;
    cout<<"Please enter an unsigned integer: ";
    cin>>seed;
    srand(seed);//将种子传给rand();

    sum=rollDice();
    switch (sum)
    {
        case 7:
        case 11:
            status=WIN;
            break;
        case 2:
        case 3:
        case 12:
            status=LOSE;
            break;
        default:
            status=PLAYING;
            myPoint=sum;
            cout<<"point is "<<myPoint<<endl;
            break;
    }

    while (status==PLAYING)
    {
        sum=rollDice();
        if (sum==myPoint)
            status=WIN;
        else if (sum==7)
            status=LOSE;
    }

    if (status==WIN)
        cout<<"player wins!"<<endl;
    else
        cout<<"player loses!"<<endl;

    return 0;
}
