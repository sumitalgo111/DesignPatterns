#pragma once
#include <iostream>
#include <memory>

using namespace std;

class HotDrink
{
    public:
    virtual ~HotDrink() = default;

    virtual void prepare(int vol) = 0;
};

class Tea : HotDrink
{
    public:
    Tea(){}

    void prepare(int vol)
    {
        std::cout<<" Getting Prepared Tea in some time:\n"
                <<"volume = "<<vol<<" ml\n";
    }
};


class Coffee : HotDrink
{
    public:
    Coffee(){}

    void prepare(int vol)
    {
        std::cout<<" Getting Prepared Coffee in some time:\n"
                <<"volume = "<<vol<<" ml\n";
    }
};