/*
Open-Close Principle : Open for Extension/Inheritance, Close for modification                  
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum class Color
{red, green, blue};

enum class Size
{small, medium, large};


class Product{
    public:
    string name;
    Color color;
    Size size;

    Product(string name, Color color, Size size):name(name), color(color), size(size){}

    void display()
    {
        cout<<name<<" is \t";
        switch(color)
        {
            case Color::green:
                cout<<"Green";break;
            case Color::red:
                cout<<"Red";break;
            case Color::blue:
                cout<<"Blue";break;
            default:break;
        }

        cout<<" in Color, \t";        
        
        switch(size)
        {
            case Size::small:
                cout<<"Small";break;
            case Size::medium:
                cout<<"Medium";break;
            case Size::large:
                cout<<"Large";break;
            default:break;
        }
        cout<<" in Size\n";
    }
};

class ProductFilter{
public:
    static vector<Product*> byColor(vector<Product*> items, Color clr)
    {
        vector<Product*> result;
        for(auto& x:items)
        {
            if(x->color == clr)
            {
                result.push_back(x);
            }
        }
        return result;
    }
    
    static vector<Product*> bySize(vector<Product*> items, Size siz)
    {
        vector<Product*> result;
        for(auto& x:items)
        {
            if(x->size == siz)
            {
                result.push_back(x);
            }
        }
        return result;
    }
    
    static vector<Product*> byColorAndSize(vector<Product*> items, Color clr, Size siz)
    {
        vector<Product*> result;
        for(auto& x:items)
        {
            if(x->size == siz && x->color == clr)
            {
                result.push_back(x);
            }
        }
        return result;
    }
};

int main()
{
    Product apple("Apple", Color::green, Size::small);
    Product tree("Tree", Color::green, Size::large);
    Product house("House", Color::blue, Size::large);
    Product ball("Ball", Color::red, Size::medium);

    vector<Product*> items{&apple, &tree, &house, &ball};

    //now call to filter by color
    vector<Product*> greenitems = ProductFilter::byColor(items, Color::green);

    //display filtered items by green color
    cout<<"Green Items : \n";
    for(auto& x:greenitems)
    {
        x->display();
    }

    //now call to filter by size
    vector<Product*> largeitems = ProductFilter::bySize(items, Size::large);

    //display filtered items by large size
    cout<<"\nLarge Items :\n";
    for(auto& x:largeitems)
    {
        x->display();
    }

    //now call to filter by color and size both
    vector<Product*> greenlargeitems = ProductFilter::byColorAndSize(items, Color::green, Size::large);

    //display filtered items by large size
    cout<<"\nLarge Items :\n";
    for(auto& x:greenlargeitems)
    {
        x->display();
    }

    return 0;
}