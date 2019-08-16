#include<iostream>
using namespace std;
class CTyre{};
class CEngine{};
class CCar{
private:
    int price;
    char * id;
    CTyre tyre;
    CEngine engine;
public:
    CCar(int p,char *id):price(p),id(i){}
    void CetPrice(){cout<<price<<endl;}
    void SetPrice(int p){price=p;}
    void GetId(){cout<<id<<endl;}
    void SetId(char * input)
    {
        if (id)
        id=NULL;
        id=new char[strlen(input)+1];
        for(int i=0;i<strlen(input)+1;i++)
            id[i]=input[i];
    }
};
class CBus:public CCar{
private:
    int guests;
public:
    void CarryPassengers(){}
    void StopReporting(){}
    void SetGuests(int g){guests=g;}
    CBus(int p,char * i,int g):CCar(p,i){guests=g;};
};
class CTrack:public CCar{
private:
    int capacity;
public:
    void Load(){}
    void Unload(){}
    void SetCapacity(int c){capacity=c;}
    void CetCapacity()
    {
        cout<<"Capacity="<<capacity<<end;
    }
    CTrack(int p,char * i,int c):CCar(p,i)
    {
        capacity=c;
    };
};
int main()
{
    CBus bus(10,"123456",20);
    bus.CetPrice();
    bus.Getid();
    bus.GetGuests();
    bus.SetId("15628888");
    bus.GetId();
    bus.CarryPassengers();
    bus.StopReporting();
    //car.CetPrice();
    return 0;
}
