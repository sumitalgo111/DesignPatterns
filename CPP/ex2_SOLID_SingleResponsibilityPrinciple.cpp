/*
This excercise is for explaining Single-Responsibilty Principle

Robert C. Martin said "A class should have only one responsibility (reason to change)"

Example : 
Real World - Suppose I am a programmer, somebody given me work to make coffee.
             I shouldn't be doing that because my primary responsibility to write program.

Complile & Print - consider a module that compiles and prints a report. Imagine such a module can be changed for two reasons.
                 First, the content of the report could change. Second, the format of the report could change. 
                 These two things change for different causes. The single-responsibility principle says that 
                 these two aspects of the problem are really two separate responsibilities, and should,
                  therefore, be in separate classes or modules. It would be a bad design to couple two things that change for 
                  different reasons at different times.

*/

/*Follwing example

*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


class Journal
{
    public:
    string title;
    vector<string> entries;

    public:
    Journal(const string& title) : title(title) {}

    void add_entry(const string& entry)
    {
        static int nofEntries = 1;
        entries.push_back(to_string(nofEntries++) + " : " + entry);
    }

//following function breaks the "Single-Responsibility" Principle
//so, to follow principle I will keep out of this class.
/*
    void save(const string& fileName)
    {
        ofstream ofs(fileName);
        for(auto entry:entries)
        {
            ofs << entry << endl;
        }
        ofs.close();
    }
*/
};

class PersistentManager
{
    public:
    static void save(const Journal& J, const string& fileName)
    {
        ofstream ofs(fileName);
        for(auto entry : J.entries)
        {
            ofs << entry << endl;
        }
        ofs.close();
    }
};


int main()
{
    Journal jn("My Diary");
    jn.add_entry("My name is Sumit.");
    jn.add_entry("Welcome to the world of adventure");

    //jn.save(jn.title+".txt");
    PersistentManager::save(jn, jn.title+".txt");

    return 0;
}