#include <iostream>
#include <cmath>
#include <ostream>

#define _USE_MATH_DEFINES

using namespace std;

class Point
{
    private:
    float x, y;
    
    Point(float x, float y):x(x),y(y){}

    public:

    static Point newCartesian(float x, float y)
    {
        return {x, y};
    }

    static Point newPolar(float r, float theta)
    {
        return {r*cos(theta), r*sin(theta)};
    }

    void display()
    {
        cout << "(" << x <<"," << y << ")" << endl;
    }

    friend ostream& operator<< (ostream& os, const Point& p)
    {
        os << "(" << p.x <<"," << p.y << ")" << endl;
        return os;
    }
};


int main()
{
    auto P1 = Point::newPolar(5, M_PI_4);
    cout<<P1;

    auto P2 = Point::newCartesian(5, 4);
    P2.display();

    return 0;
}