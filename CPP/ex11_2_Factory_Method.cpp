#include <iostream>

using namespace std;

enum eVechileType {VT_TwoWheeler, VT_ThreeWheeler, VT_FourWheeler};
class Vehicle
{
    public:
    virtual void print()=0;

    static Vehicle* Factory(eVechileType type);
};

class TwoWheeler:public Vehicle
{
    private:
    TwoWheeler(){}

    public:
    void print()
    {
        cout<<"This is two wheeler"<<endl;
    }

    friend class Vehicle;
};


class ThreeWheeler:public Vehicle
{
    private:
    ThreeWheeler(){}

    public:
    void print()
    {
        cout<<"This is three wheeler"<<endl;
    }

    friend class Vehicle;
};

class FourWheeler:public Vehicle
{
    private:
    FourWheeler(){}
    
    public:
    void print()
    {
        cout<<"This is Four wheeler"<<endl;
    }

    friend class Vehicle;
};

Vehicle* Vehicle::Factory(eVechileType type)
{
    Vehicle* base = NULL;
    switch(type)
    {
        case VT_TwoWheeler:
            base = new TwoWheeler();
            break;
        case VT_ThreeWheeler:
            base = new ThreeWheeler();
            break;
        case VT_FourWheeler:
            base = new FourWheeler();
            break;
        default:
        cout<<"Invalid Vehicle Type"<<endl;
        break;
    }

    return base;
}

int main()
{
    Vehicle* obj1 = Vehicle::Factory(VT_TwoWheeler);
    obj1->print();

    Vehicle* obj2 = Vehicle::Factory(VT_ThreeWheeler);
    obj2->print();

    Vehicle* obj3 = Vehicle::Factory(VT_ThreeWheeler);
    obj3->print();
    return 0;
}