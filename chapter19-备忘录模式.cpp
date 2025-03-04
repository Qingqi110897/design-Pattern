#include <iostream>
using namespace std;

class Memento//备忘录
{
private:
	string str;
public:
	Memento(string str)
	{
		this->str = str;
	}
	string get_str()
	{
		return this->str;
	}
};

class originator
{
private:
	string str;
public:
	void set_str(string str)
	{
		this->str = str;
	}
	Memento* get_memo()
	{
		return new Memento(this->str);
	}
	void print_str()
	{
		cout << this->str << endl;
	}
	void recover(Memento* memo)
	{
		this->str = memo->get_str();
	}
};

class caretaker
{
private:
	Memento* memo;
public:
	void set_memo(Memento* memo)
	{
		this->memo = memo;
	}
	Memento* get_memo()
	{
		return this->memo;
	}
};
int main()
{
	originator* ori = NULL;
	caretaker* care = NULL;
	care = new caretaker;


	ori = new originator;
	ori->set_str("原始状态");
	ori->print_str();
	care->set_memo(ori->get_memo());

	ori->set_str("状态改变");
	ori->print_str();

	ori->recover(care->get_memo());
	ori->print_str();
	delete care;
	delete ori;
}

