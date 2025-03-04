#include <iostream>

class handler
{
protected:
	handler* next;
public:
	virtual void perform() = 0;
	handler* set_next(handler* next)
	{
		this->next = next;
		return this->next;
	}
};

class Task1 :public handler
{
public:
	virtual void perform()override
	{
		std::cout << "task1" << std::endl;
		if (next != NULL)
		{
			next->perform();
		}
	}
};
class Task2 :public handler
{
public:
	virtual void perform()override
	{
		std::cout << "task2" << std::endl;
		if (next != NULL)
		{
			next->perform();
		}
	}
};

class Task3 :public handler
{
public:
	virtual void perform()override
	{
		std::cout << "task3" << std::endl;
		if (next != NULL)
		{
			next->perform();
		}
	}
};
int main()
{
	handler* task1 = NULL;
	handler* task2 = NULL;
	handler* task3 = NULL;

	task1 = new Task1;
	task2 = new Task2;
	task3 = new Task3;

	task1->set_next(task2);
	task2->set_next(task3);
	task3->set_next(NULL);

	task1->perform();

	std::cout << "===================================" << std::endl;

	//改变流程
	std::cout << "任务流程：task3 -> task2 -> task1 -> 结束" << std::endl;
	task1->set_next(NULL);
	task2->set_next(task1);
	task3->set_next(task2);

	task3->perform();
	std::cout << "===================================" << std::endl;
	delete task1;
	delete task2;
	delete task3;
}
