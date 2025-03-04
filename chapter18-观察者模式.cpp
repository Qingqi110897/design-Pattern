#include <iostream>
#include<list>
using namespace std;
class Guard;
class soldier
{
private:
	Guard* guard;
public:
	soldier(Guard* guard)
	{
		this->guard = guard;
	}
	void recv_infor(string info)
	{
		cout << info << ":收到准备战斗" << endl;
	}
};
class Guard
{
private:
	list<soldier*>l;
public:
	void add_observer(soldier* solid)
	{
		l.push_back(solid);
	}
	void send_info(string info)
	{
		for (list<soldier*>::iterator it = l.begin();it!=l.end();it++)
		{
			(*it)->recv_infor(info);
		}
	}
};
int main()
{
	soldier* s1 = NULL, * s2 = NULL, * s3 = NULL;
	Guard* g = NULL;

	g = new Guard;
	s1 = new soldier(g);
	s2 = new soldier(g);
	s3 = new soldier(g);

	g->add_observer(s1);
	g->add_observer(s2);
	g->add_observer(s3);

	string s = "敌人来了";
	g->send_info(s);
}

