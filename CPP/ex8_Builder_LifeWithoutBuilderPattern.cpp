/*
Following example is without builder pattern.
Example of HTML Element Output

The problem is there is no proper identation/alignment of elements while print output.
creating elements with their tag one by one is not good.
Mean to say it's not scalable
*/

#include <iostream>
#include <sstream>
using namespace std;


int main()
{

    auto text = "Hello";
    string str;
    str += "<P>";
    str += text;
    str += "</P>";
    cout << str << endl;


    string words[] = {"Hello", "World"};

    ostringstream oss;
    oss << "<ul>";
    for(auto w:words)
        oss << "  <li>" << w << "</li>  ";

    oss << "</ul>";
    cout << oss.str()<<endl;
    


    return 0;
}