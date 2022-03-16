/*
LiskovSubstituionPrinciple : Subtypes should be immediately substituable for the Base type

Following example brokes the LiskovSubstituionPrinciple. Here function Process gives unexpected result for Square object
*/
#include <iostream>

using namespace std;

class Rectangle
{
    protected:
    int length;
    int width;

    public:
    Rectangle(int length, int width):length(length),width(width){}

    int getlength() const{return length;}
    virtual void setLength(int length){Rectangle::length = length;}

    int getWidth() const{return width;}
    virtual void setWidth(int width){Rectangle::width = width;}

    int getArea() const{return length*width;}
};

class Square : public Rectangle
{
    public:
    Square(int size):Rectangle(size, size){}

    void setLength(int size)
    {
        length = width = size;
    }

    void setWidth(int size)
    {
        length = width = size;
    }
};

void Process(Rectangle& rect)
{
    int len = rect.getlength();
    rect.setWidth(10);

    cout<<"Expected Area = "<<len*10 <<", got  = "<<rect.getArea()<<endl;
}


int main()
{
    Rectangle rect(4,3);
    Process(rect);

    Square sq(5);
    Process(sq);

    return 0;
}
