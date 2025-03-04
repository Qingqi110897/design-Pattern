#include <iostream>
class transport {
public:
    virtual ~transport() {}
    //deliver()定义为纯虚函数（= 0）的目的是将transport类设为抽象基类。
    //抽象基类用于定义接口或行为规范，而不打算直接实例化对象。
    virtual void deliver() = 0;
};
class Truck :public transport{
public:
    void deliver() override{
        std::cout << "卡车运输货物\n";
    }
};
class Ship :public transport {
public:
    void deliver() override {
        std::cout << "轮船运输货物\n";
    }
};
class logistics
{
public:
    virtual ~logistics() {}
    virtual transport *factorymethod()const = 0;
    void doSomething() const{
        transport* transport =factorymethod();
        transport->deliver();
        delete transport;
    }
};
class TruckLogistics :public logistics {
public:
    virtual ~TruckLogistics() {}
    virtual transport* factorymethod()const override {
        return new Truck();
    }
  
};
int main()
{
    logistics* logistic = new TruckLogistics();
    logistic->doSomething();

}
