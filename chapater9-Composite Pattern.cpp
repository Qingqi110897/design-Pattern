#include <iostream>
#include<vector>
using namespace std;
class component
{
public:
    virtual void display() = 0;////显示当前文件或文件夹名称
    virtual void add(component* node) = 0; //在当前文件夹增加一个文件或文件夹
    virtual void remove(component* node) = 0;//在当前文件夹删除一个文件或文件夹
    virtual vector<component*>* get_child() = 0; //获取文件夹下属文件或文件夹
};

class leaf :public component
{
private:
    string name;
public:
    leaf(string name)
    {
        this->name = name;
    }
    virtual void display()override
    {
        cout << "Leaf: " << this->name << endl;
    }
    virtual void add(component* node)
    {
        cout << "叶子结点，无法加入" << endl;
    }
    virtual void remove(component* node)
    {
        cout << "叶子结点，无此操作" << endl;
    }
    virtual vector<component*>* get_child()
    {
        cout << "叶子结点，无子结点" << endl;
        return NULL;
    }
};

class composite :public component
{
private:
    string name;
    vector<component*>* vec;
public:
    composite(string name)
    {
        this->name = name;
        vec = new vector<component*>;
    }
    ~composite()
    {
        if (vec != NULL)
        {
            delete vec;
            vec = NULL;
        }
    }
    virtual void display()
    {
        cout << "Composite: " << this->name << endl;
    }
    virtual void add(component* node)
    {
        vec->push_back(node);
    }
    virtual void remove(component* node)
    {
        for (vector<component*>::iterator it = vec->begin(); it != vec->end(); it++)
        {
            if (*it == node)
            {
                vec->erase(it);
            }
        }
    }
    virtual vector<component*>* get_child()
    {
        cout << "*" << this->name << " child: " << "*\n";
        for (vector<component*>::iterator it = vec->begin(); it != vec->end(); it++)
        {
            (*it)->display();
        }
        return vec;
    }
};

int main()
{
    component* root;
    leaf* l1;
    leaf* l2;
    composite* dir;

    root = new composite("/root");
    l1 = new leaf("1.cpp");
    l2 = new leaf("2.cpp");
    dir = new composite("/home");

    root->add(dir);
    dir->add(l1);
    dir->add(l2);

    cout << "============" << endl;
    root->display();
    root->get_child();
    dir->get_child();
    cout << "============" << endl;

    delete dir;
    delete l2;
    delete l1;
    delete root;

    system("pause");
    return 0;
}

