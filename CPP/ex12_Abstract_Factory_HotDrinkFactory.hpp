#pragma once

#include "ex12_Abstract_Factory_HotDrink.hpp"

class HotDrinkFactory
{
    public:
    virtual unique_ptr<HotDrink> make() const = 0;
};

class TeaFactory : HotDrinkFactory
{
    public:
    unique_ptr<HotDrink> make() const override
    {
        return std::make_unique<Tea>();
    }
};


class CoffeeFactory : HotDrinkFactory
{
    public:
    unique_ptr<HotDrink> make() const override
    {
        return std::make_unique<Coffee>();
    }
};