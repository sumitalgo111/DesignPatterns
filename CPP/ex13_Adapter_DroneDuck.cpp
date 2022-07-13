#include <iostream>

using namespace std;

//Here we want to implement an adapter for Drone class, so that Duck object can use Drone features
//Simulator class to test
class AdapterExample
{
    public:
    static void testDuck(Duck& ObjDuck)
    {
        ObjDuck.fly();
        ObjDuck.quack();
    }

    int main()
    {
        //Use AdapterDrone, when Duck wants to use Drone functions
        Duck* pObjDuck = new AdapterDrone(new SuperDrone());
        testDuck(*pObjDuck);

        return 0;
    }
};

class AdapterDrone : Duck
{
    public:
    Drone* pObjDrone;
    AdapterDrone(Drone* pObj)
    {
        pObjDrone = pObj;
    }

    void quack()
    {
        if(!pObjDrone)
            return;

        pObjDrone->beep();
    }

    void fly()
    {
        if(!pObjDrone)
            return;

        pObjDrone->spin_rotors();
        pObjDrone->take_off();
    }
};


//Following is a Drone Interface
class Drone
{
    public:
    virtual void beep()=0;
    virtual void spin_rotors()=0;
    virtual void take_off()=0;
};
//SuperDrone class implements Drone Interface
class SuperDrone : Drone
{
    public:
    void beep()
    {
        cout<<"beep beep beep\n";
    }
    void spin_rotors()
    {
        cout<<"Rotors are spinning\n";
    }
    void take_off()
    {
        cout<<"Taking off\n";
    }
};

//Following is a Duck interface
class Duck
{
    public:
    virtual void fly()=0;
    virtual void quack()=0;
};
//MallardDuck class implements Duck Interface
/*class MallardDuck : Duck
{
    public:
    void fly()
    {
        cout<<"Flying\n";
    }
    void quack()
    {
        cout<<"quack quack quack\n";
    }
};*/
