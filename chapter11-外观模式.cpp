#include <iostream>


class screen
{
public:
    void get_addr()
    {
        std::cout << "screen" << std::endl;
    }
};

class keyboard
{
public:
    void get_addr()
    {
        std::cout << "keyboard" << std::endl;
    }
};

class host
{
public:
    void get_addr()
    {
        std::cout << "host" << std::endl;
    }
};
class facade
{
private:
    screen* m_screen;
    keyboard* m_keyboard;
    host* m_host;
public:
    facade()
    {
        m_screen = new screen;
        m_keyboard = new keyboard;
        m_host = new host;
    }
    void show()
    {
        this->m_screen->get_addr();
        this->m_host->get_addr();
        this->m_keyboard->get_addr();
    }
    ~facade()
    {
        if (m_screen != NULL)
        {
            delete m_screen;
        }
        if (m_keyboard != NULL)
        {
            delete m_keyboard;
        }
        if (m_host != NULL)
        {
            delete m_host;
        }
    }
};
int main()
{
    facade* f = new facade;
    f->show();
    delete f;
}
