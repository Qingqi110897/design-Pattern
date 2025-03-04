#include<iostream>
using namespace std;

class strategy
{
public:
	virtual void sort() = 0;
};

class selectsort :public strategy
{
private:
	strategy* kind;
public:
	virtual void sort()override
	{
		cout << "使用选择排序" << endl;
	}
};

class insertsort :public strategy
{
private:
	strategy* kind;
public:
	virtual void sort()override
	{
		cout << "使用插入排序" << endl;
	}
};

class context
{
private:
	strategy* kind;
public:
	void set_context(strategy* kind)
	{
		this->kind = kind;
	}
	void get_sort()
	{
		this->kind->sort();
	}
};
int main()
{
	strategy* kind = NULL;
	kind = new insertsort;
	context* con = new context;
	con->set_context(kind);
	con->get_sort();
	delete kind;
	kind = new selectsort;
	con->set_context(kind);
	con->get_sort();
}