#include <iostream>
using namespace std;
#include<list>
class Element;

class Visitor//抽象访问者
{
public:
	virtual void visit(Element* e) = 0;
};

class Element//抽象元素
{
public:
	virtual void reception(Visitor* v) = 0;
	virtual string get_name() = 0;
};

class department1 :public Element
{
public:
	virtual void reception(Visitor* v)
	{
		v->visit(this);
	}
	virtual string get_name()
	{
		return "第一事业部";
	}
};

class department2 :public Element
{
public:
	virtual void reception(Visitor* v)
	{
		v->visit(this);
	}
	string get_name()
	{
		return "第二事业部";
	}
};

class president :public Visitor
{
public:
	virtual void visit(Element* e)
	{
		cout << "董事长访问：" << e->get_name() << endl;
	}
};
class Leader1 : public Visitor //分管领导1
{
public:
	virtual void visit(Element* e)
	{
		cout << "第一分管领导访问：" << e->get_name() << endl;
	}
};
class Leader2 : public Visitor //分管领导2
{
public:
	virtual void visit(Element* e)
	{
		cout << "第二分管领导访问：" << e->get_name() << endl;
	}
};
class Group : public Element //整个集团
{
private:
	list<Element*> l;
public:
	virtual void reception(Visitor* v)
	{
		for (list<Element*>::iterator it = l.begin(); it != l.end(); it++)
		{
			(*it)->reception(v);
		}
	}
	void add_element(Element* e)
	{
		l.push_back(e);
	}
	virtual string get_name()
	{
		return "整个集团公司";
	}
};
int main()
{
	Visitor*v1 = new Leader1;
	Visitor* v2 = new Leader2;
	Visitor* v = new president;
	Group* e = new Group;
	Element* e1 = new department1;
	Element* e2 = new department2;
	//e1->reception(v1);
	//e2->reception(v2);
	e->add_element(e1);
	e->add_element(e2);
	//董事长访问;
	e->reception(v);
}

