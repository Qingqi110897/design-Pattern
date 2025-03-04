#include <iostream>
using namespace std;
//它的主要特点是把抽象（abstraction）与行为实现（implementation）分离开来，
//从而可以保持各部分的独立性以及应对它们的功能扩展。
//桥接模式可以实现抽象部分与实现部分的解耦合，使得抽象和实现都可以独立的发生变化，
//当通过继承不能实现开闭原则的时候，就可以考虑桥接模式。
//图形和颜色，把图形设计一个抽象类，颜色设计一个抽象类，然后根据需要的图形去实现图形类，
//并根据需要的颜色实现颜色类，通过两个抽象类就可以实现颜色和图形的组合。
class color
{
public:
    virtual void get_color() = 0;
};

class graph
{
protected:
    color* mgraphcolor;
public:
    graph(color* mgraphcolor)
    {
        this->mgraphcolor = mgraphcolor;
    }
    virtual void smear_color() = 0;
};

class Red : public color
{
public:
    virtual void get_color()
    {
        cout << "红色" << endl;
    }
};

class Blue : public color
{
public:
    virtual void get_color()
    {
        cout << "蓝色" << endl;
    }
};

class Yellow : public color
{
public:
    virtual void get_color()
    {
        cout << "黄色" << endl;
    }
};

class circle : public graph
{
public:
    circle(color* mgraphcolor) : graph(mgraphcolor) {};  // 构造函数设为public
    virtual void smear_color()
    {
        cout << "圆形 + ";
        mgraphcolor->get_color();
    }
};

class Triangle : public graph
{
public:
    Triangle(color* mGraphColor) : graph(mGraphColor) {};  // 修正大小写
    virtual void smear_color()
    {
        cout << "三角形 + ";
        mgraphcolor->get_color();
    }
};

int main()
{
    color* m_color = nullptr;

    m_color = new Red;
    circle* m_circle = new circle(m_color);
    m_circle->smear_color();

    delete m_circle; // 删除 circle 对象

    m_color = new Blue;
    Triangle* m_triangle = new Triangle(m_color);
    m_triangle->smear_color();

    delete m_triangle; // 删除 Triangle 对象
    delete m_color;    // 删除颜色对象

    return 0;
}
