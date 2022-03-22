#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class HtmlElement
{
    friend class HtmlBuilder;

    string name;
    string text;

    //for formatting spaces between elements
    const int ident_size = 3;
    //for inner html elements (nested)
    vector<HtmlElement> elements;

    HtmlElement(){}
    HtmlElement(const string name, const string text):name(name),text(text){}

public:
    string str(int ident=0) const
    {
        ostringstream oss;
        oss << string(ident_size*ident, ' ') << "<" << name << ">" <<endl;

        if(text.size()>0)
            oss << string(ident_size*(ident+1),' ') << text << endl;

        for(auto ele:elements)
        {
            oss << ele.str(ident+1);
        }

        oss << string(ident_size*ident, ' ') << "</" << name << ">" << endl;

        return oss.str();
    }

};

class HtmlBuilder
{
    HtmlElement root;
    public:
    HtmlBuilder(string root_name)
    {
        root.name = root_name;
    }

    HtmlBuilder& add_child(string name, string text)
    {
        root.elements.push_back(HtmlElement(name,text));
        return *this;
    }

    HtmlBuilder* add_child2(string name, string text)
    {
        root.elements.push_back(HtmlElement(name,text));
        return this;
    }

    string str()
    {
        return root.str();
    }

    static HtmlBuilder build(string name)
    {
        return {name};//return HtmlBuilder(name);
    }

    operator HtmlElement() const
    {
        return root;
    }
};

int main()
{
    //HtmlBuilder builder = HtmlBuilder::build("ul").add_child("li", "Hello").add_child("li", "World");
    //cout << builder.str();

   
    HtmlElement ele = HtmlBuilder::build("ul").add_child("li", "Hello").add_child("li", "World");

    cout << ele.str(2);


    return 0;
}