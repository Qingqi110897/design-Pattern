#include <iostream>
using namespace std;
class Role;
class Mediator
{
public:
	virtual void match() = 0;
	virtual void set_hr(Role* hr) = 0;
	virtual void set_student(Role* student) = 0;
};

class Role
{
protected:
	string name;
	string office;
	Mediator* mediator;
public:
	Role(string name, string office, Mediator* mediator)
	{
		this->name = name;
		this->office = office;
		this->mediator = mediator;
	}
	string get_name()
	{
		return this->name;
	}
	string get_office()
	{
		return this->office;
	}
	virtual void match(Role* role) = 0;
};

class boss :public Mediator
{
private:
	Role* hr;
	Role* student;
public:
	virtual void set_hr(Role* hr)
	{
		this->hr = hr;
	}
	virtual void set_student(Role* student)
	{
		this->student = student;
	}
	virtual void match()
	{
		cout << "=========================" << endl;
		cout << hr->get_name() << " 提供职位：" << hr->get_office() << endl;
		cout << student->get_name() << " 需求职位：" << student->get_office() << endl;
		if (hr->get_office() == student->get_office())
		{
			cout << "***匹配成功***" << endl;
		}
		else
		{
			cout << "***匹配失败***" << endl;
		}
		cout << "=========================" << endl;
	}
};



class student :public Role
{
public:
	student(string name, string office, Mediator* mediator) :Role(name, office, mediator) {};
	virtual void match(Role* role)
	{
		mediator->set_student(this);
		mediator->set_hr(role);
		mediator->match();
	}
};
class HR : public Role
{
public:
	HR(string name, string office, Mediator* mediator) : Role(name, office, mediator) {};
	virtual void match(Role* role)
	{
		mediator->set_hr(this);
		mediator->set_student(role);
		mediator->match();
	}
};
int main()
{
	Role* hr = NULL;
	Role* stu1 = NULL;
	Role* stu2 = NULL;
	Mediator* medi = NULL;
	medi = new boss;

	hr = new HR("七总", "C++", medi);
	stu1 = new student("小明", "Java", medi);
	stu2 = new student("小红", "C++", medi);
	hr->match(stu1);
	hr->match(stu2);

	delete stu2;
	delete stu1;
	delete hr;
}
