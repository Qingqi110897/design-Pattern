#include <iostream>
using namespace std;


//以办理银行业务为例，首先创建一个银行职员作为命令接收者，他可以执行存款取款操作。
class banker
{
public:
	void saving_money()
	{
		cout << "办理存款业务" << endl;
	}
	void withdraw_money()
	{
		cout << "办理取款业务" << endl;
	}
};
//创建一个命令抽象类，并通过继承实现一个存款命令类和一个取款命令类，
//这两个具体命令方法分别可以调用命令执行者的存款操作和取款操作。
class Command
{
public:
	virtual void conduct_business() = 0;
};

class save :public Command
{
private:
	banker* bker;
public:
	save(banker* bker)
	{
		this->bker = bker;
	}
	virtual void conduct_business()override
	{
		this->bker->saving_money();
	}

};

class withdraw :public Command
{
private:
	banker* bker;
public:
	withdraw(banker*bker)
	{
		this->bker = bker;
	}
	virtual void conduct_business()override
	{
		this->bker->withdraw_money();
	}
};

//创建一个命令调用者，它可以调用命令对象
class manager
{
private:
	Command* com;
public:
	manager(Command*com)
	{
		this->com = com;
	}
	void order()
	{
		com->conduct_business();
	}
};

int main()
{
	manager* m_manager = NULL;
	Command* com = NULL;
	banker* bker = NULL;
	bker = new banker;
	com = new save(bker);
	m_manager = new manager(com);
	m_manager->order();
	delete com;
	delete m_manager;
	com = new withdraw(bker); //取款命令
	m_manager = new manager(com);
	m_manager->order();

	delete m_manager;
	delete com;
	delete bker;

}
