
#include <iostream>

class chair {
public:
    virtual ~chair(){}
    virtual void siton()const = 0;
};
class modernchair :public chair
{
public:
    virtual ~modernchair(){}
    virtual void siton()const override {
        std::cout << "可以被坐下的Modernchair\n";
    }
};
class chinesechair :public chair
{
public:
    virtual ~chinesechair() {}
    virtual void siton()const override {
        std::cout << "可以被坐下的chinesechair\n";
    }
};
class table {
public:
    virtual ~table() {}
    virtual void puton()const = 0;
};
class moderntable :public table
{
public:
    virtual ~moderntable() {}
    virtual void puton()const override {
        std::cout << "可以用的Moderntable\n";
    }
};
class chinesetable :public table
{
public:
    virtual ~chinesetable() {}
    virtual void puton()const override {
        std::cout << "可以用的chinesetable\n";
    }
};
class Furniturefactory {
public:
    virtual chair* createchair()const = 0;
    virtual table* createtable()const = 0;
};
class modernstylefactory :public Furniturefactory
{
public:
    virtual chair* createchair()const override
    {
        return new modernchair;
    }
    virtual table* createtable()const override
    {
        return new moderntable;
    }
};
class chinesestylefactory :public Furniturefactory
{
public:
    virtual chair* createchair()const override
    {
        return new chinesechair;
    }
    virtual table* createtable()const override
    {
        return new chinesetable;
    }
};
class client {
private:
    Furniturefactory* m_factory;
public:
    client(Furniturefactory* factory) {
        setfactory(factory);
    }
    void buyfurniture()
    {
        chair* chair = m_factory->createchair();
        table* table = m_factory->createtable();
        chair->siton();
        table->puton();
        delete chair;
        delete table;
    }

    void setfactory(Furniturefactory* factory)
    {
        m_factory = factory;
    }
};
int main()
{
    modernstylefactory modernfactory;
    client client(&modernfactory);
    client.buyfurniture();

    chinesestylefactory chinesefactory;
    client.setfactory(&chinesefactory);
    client.buyfurniture();
}