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
public:
    HtmlElement(){}
    HtmlElement(const string name, const string text):name(name),text(text){}

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

    void add_child(string name, string text)
    {        
        root.elements.push_back(HtmlElement(name,text));
    }

    string str(int ident=0)
    {
        return root.str();
    }
};

int main()
{
    /*
    auto text = "Hello";
    string str;
    str += "<P>";
    str += text;
    str += "</P>";
    cout << str << endl;
    */
   
    HtmlElement ele_P("P","Hello");
    cout << ele_P.str();

    string words[] = {"Hello", "World"};
/*
    ostringstream oss;
    oss << "<ul>";
    for(auto w:words)
        oss << "  <li>" << w << "</li>  ";

    oss << "</ul>";
    cout << oss.str()<<endl;
*/

/*    HtmlElement ele_ul("ul","");
    for(auto w:words)
    {
        HtmlElement child("li",w);
        ele_ul.add_child(child);
    }
*/

    HtmlBuilder ele_ul("ul");
    for(auto w:words)
        ele_ul.add_child("li", w);

    cout << ele_ul.str();

    return 0;
}