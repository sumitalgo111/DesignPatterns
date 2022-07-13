/*
Observer Pattern : This pattern defines a one-to-many dependency between objects.
So that when one object changes state, all of its dependents are modified and updated automatically.



*/

#include <iostream>
#include <map>
#include <list>
#include <vector>

using namespace std;

int main()
{
    return 0;
}


//Subject class
class Subject
{
    public:
    virtual void registerObserver(Observer* Obj) = 0;
    virtual void removeObserver(Observer* Obj) = 0;
    virtual void notifyObserver() = 0;
};

//Observer class
class Observer
{
    public:
    virtual void update()=0;

};

//concrect subject class
class ConcreteSubject
{
    private:
    list<Observer*> listSubscriber;

    public:

};
