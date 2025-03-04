#include <iostream>
#include<string>
#include<map>
using namespace std;
class mystr
{
protected:
    string str;
public:
    mystr(string str)
    {
        this->str = str;
    }
    virtual void get_str() = 0;
};

class hello :public mystr
{
private:
    int id;
public:
    hello(string str, int id):mystr(str)
    {
        this->id = id;
    }
    virtual void get_str()
    {
        cout << "id: " << id << "  对应的str:  " << str << endl;
    }
};

class factory
{
private:
    map<int, hello*>m;
public:
    ~factory()
    {
        while (!m.empty())
        {
            hello* tmp = NULL;
            map<int, hello*>::iterator it = m.begin();
            tmp = it->second;
            m.erase(it);
            delete tmp;
        }
    }
    hello* get_str(int id)
    {
        hello* mtemp;
        map<int, hello*>::iterator it;
        it = m.find(id);
        if (it == m.end())
        {
            string temp;
            cout << "该字符串未找到，请输入字符串：";
            cin >> temp;
            mtemp = new hello(temp, id);
            m.insert(make_pair(id, mtemp));
            return mtemp;
        }
        else
        {
            return it->second;
        }
    }
};


int main()
{
    hello* h1 = NULL, * h2 = NULL;
    factory* f = NULL;
    f = new factory;
    h1 = f->get_str(1);
    h1->get_str();
    h2 = f->get_str(1);
    h2->get_str();

    delete h1;
    delete h2;
    delete f;
}
