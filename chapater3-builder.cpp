#include <iostream>
#include<string>
#include<vector>
class simpleHouse {
public:
    std::vector<std::string>m_parts;
    void printParts()const {
        std::cout << "simpleHouse 包括：\n";
        for (int i = 0; i < m_parts.size(); ++i) {
            std::cout << m_parts[i] << std::endl;
        }
        std::cout << "------------------\n";
    }
};

class builder {
public:
    virtual ~builder() {};
    virtual void reset() = 0;
    virtual void makeBasehouse() = 0;
    virtual void makeGarage() = 0;
    virtual void makePool() = 0;
};

class simpleHouseBuilder:public builder {
private:
    simpleHouse* simplehouse;
public:
    simpleHouseBuilder()
    {
        reset();
    }
    void reset()override{ simplehouse = new simpleHouse(); }
    ~simpleHouseBuilder() { delete simplehouse; }
    virtual void makeBasehouse()override {
        simplehouse->m_parts.push_back("BaseHouse");
    }
    virtual void makeGarage() override{
        simplehouse->m_parts.push_back("garage");
    }
    virtual void makePool() override {
        simplehouse->m_parts.push_back("pool");
    }

    simpleHouse* getresult()
    {
        simpleHouse* result = simplehouse;
        reset();
        return result;
    }
};

class director {
private:
    builder* m_builder;
public:
    void setBuilder(builder* builder) {
        m_builder = builder;
    }
    void makesimplehouse() {
        m_builder->makeBasehouse();
        m_builder->makeGarage();
    }
    void makefullFunchouse() {
        m_builder->makeBasehouse();
        m_builder->makeGarage();
        m_builder->makePool();
    }
};
void client(director*director)
{
    std::cout << "客户自己设计流程:--------------------\n";
    simpleHouseBuilder* Builder = new simpleHouseBuilder;
    Builder->makeBasehouse();
    Builder->makeGarage();
    simpleHouse* simplehouse = Builder->getresult();
    simplehouse->printParts();
    std::cout << "主管负责设计流程---------------------\n";
    director->setBuilder(Builder);
    director->makefullFunchouse();
    simplehouse = Builder->getresult();
    simplehouse->printParts();
    delete simplehouse;
    delete Builder;
}
int main()
{
    director director;
    client(&director);
}


