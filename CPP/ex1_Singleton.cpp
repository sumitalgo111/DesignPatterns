#include <iostream>

using namespace std;


class Singleton
{
    private:
    static Singleton* pObj;
    
    Singleton()
    {}

    public:
    static Singleton* getInstance()
    {
        if(pObj == NULL)
            pObj = new Singleton();

        return pObj;
    }
};



int main()
{
    Singleton* ptr = Singleton::getInstance();

    return 0;
}