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

template <typename T>
class Specification
{
    public:
    virtual bool isSatisfied(T* item) = 0;

  /*  AndSpecification<T> operator && (Specification<T>&& second)
    {
        return AndSpecification<T>(*this, &second);
    }*/
};

template <typename T>
class Filter
{
    public:
    virtual vector<T*> dofilter(vector<T*> items, Specification<T>& spec) = 0;
};

class ColorSpecification : public Specification<Product>{
    Color color;

    public:
    ColorSpecification(Color clr):color(clr){}

    bool isSatisfied(Product* item)
    {
        return (item->color == color);
    }
};

class SizeSpecification : public Specification<Product>
{
    Size size;
    public:
    SizeSpecification(Size siz):size(siz){}

    bool isSatisfied(Product* item)
    {
        return (item->size == size);
    }
};

template <typename T>
class AndSpecification : public Specification<T>
{
    Specification<T>& first;
    Specification<T>& second;
    public:
    AndSpecification(Specification<T>& cspec, Specification<T>& sSpec):first(cspec), second(sSpec){}

    bool isSatisfied(T* item)
    {
        return (first.isSatisfied(item) && second.isSatisfied(item));
    }
};

class ProductFilter : public Filter<Product>{
public:
    vector<Product*> dofilter(vector<Product*> items, Specification<Product>& spec)
    {
        vector<Product*> result;
        for(auto& x:items)
        {
            if(spec.isSatisfied(x))
                result.push_back(x);
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
    ColorSpecification colorSpec(Color::green);
    ProductFilter pf;
    vector<Product*> coloritems = pf.dofilter(items, colorSpec);

    //display filtered items by green color
    cout<<"Green Items : \n";
    for(auto& x:coloritems)
    {
        x->display();
    }

    //now call to filter by size
    SizeSpecification sizeSpec(Size::large);
    vector<Product*> largeitems = pf.dofilter(items, sizeSpec);

    //display filtered items by large size
    cout<<"\nLarge Items :\n";
    for(auto& x:largeitems)
    {
        x->display();
    }

    //now call to filter by color and size both
    AndSpecification colorandsizeSpec(colorSpec, sizeSpec);
    vector<Product*> greenlargeitems = pf.dofilter(items, colorandsizeSpec);

    //display filtered items by large size
    cout<<"\nLarge Items :\n";
    for(auto& x:greenlargeitems)
    {
        x->display(); 
    }

    return 0;
}