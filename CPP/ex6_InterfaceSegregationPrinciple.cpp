/*
Interface Segregation Principle :

*/

#include <iostream>

using namespace std;

/*
class IMachine
{
    public:
    virtual void Print() = 0;
    virtual void Scan() = 0;
    virtual void Fax() = 0;
};
class Printer:IMachine{
    public:
    void Print(){
        cout<<"Printer works\n";
    }
    void Scan(){}
    void Fax(){}
};
class Scanner:IMachine{
    public:
    void Print(){}
    void Scan(){
        cout<<"Scanner works\n";
    }
    void Fax(){}
};

int main()
{
    Scanner sobj;
    sobj.Scan();
    sobj.Print();


    Printer pobj;
    pobj.Scan();
    pobj.Print();

    return 0;
}
*/

class IScanner
{
    public:
    virtual void Scan() = 0;
};

class IPrinter
{
    public:
    virtual void Print() = 0;
};

class IMachine : public IScanner, public IPrinter{};

class Scanner:public IScanner
{
    public:
    void Scan(){
        cout<<"Scanner Works\n";
    }
};

class Printer:public IPrinter
{
    public:
    void Print(){
        cout<<"Printer Works\n";
    }
};

class Machine:IMachine
{
    IScanner& scanner;
    IPrinter& printer;
    public:
    Machine(IScanner& scanner, IPrinter& printer):scanner(scanner),printer(printer){}

    void Scan()
    {
        scanner.Scan();
    }
    void Print()
    {
        printer.Print();
    }
};

int main()
{
    Scanner sobj;
    sobj.Scan();

    Printer pobj;
    pobj.Print();

    Machine mobj(sobj,pobj);
    mobj.Scan();
    mobj.Print();

    return 0;
}