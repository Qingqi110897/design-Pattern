#include<iostream>
#include<mutex>
#include<thread>
////懒汉式单例模式
//class SingletonPattern
//{
//private:
//	SingletonPattern()
//	{
//		std::cout << "私有的构造函数" << std::endl;
//	}
//public: //构造函数被私有化了，所以应该提供一个对外访问的方法，来创建对象
//	static SingletonPattern* get_single()
//	{
//		if (single == NULL) //为保证单例，只new一次
//		{					//如果不加这个判断，每次创建对象都会new一个single，这就不是单例了
//			single = new SingletonPattern;
//		}
//		//return this->single;
//		return single; //静态成员属于整个类，没有this指针
//	}
//private: //static 成员，类定义的所有对象共有static成员
//	static SingletonPattern* single; //指针，不能是变量，否则编译器不知道如何分配内存
//};
////懒汉式单例的缺点:
////通过懒汉式单例模式，我们实现了一个类只创建一个实例对象，
////且只有在用到实例对象的时候，才会通过全局访问点去new创建这个对象，节省了资源。
////但是，懒汉式单例模式有一个致命的缺点，就是在C++的构造函数中，不能保证线程安全。
////什么意思呢，也就是说，在多个线程都去创建对象，调用全局访问点get_single()的时候，会面临资源竞争问题，
////假如在类的构造函数中增加一个延迟函数，我们第一个线程调用get_single()的时候，会进入构造函数，
////这时，因为延时的存在，第一个线程可能会在这里卡顿一会，假如正好这时候第二个线程也调用get_single()去创建实例对象，
////而第一个线程还在构造函数中延时，这样在get_single()函数中(single == NULL)这个判断条件依然成立，第二个线程也会进入构造函数。
////这样，两个线程创建的对象就不再是同一个对象了，也就不是单例模式了。
//SingletonPattern* SingletonPattern::single = NULL; //告诉编译器分配内存
//饿汉式单例模式
class SingletonPattern
{
private:
	SingletonPattern()
	{
		printf("私有的构造函数\n");
	}

public:
	static SingletonPattern* get_single()
	{
		return single;
	}
private:
	static SingletonPattern* single;
};

//SingletonPattern* SingletonPattern::single = NULL;
SingletonPattern* SingletonPattern::single = new SingletonPattern; //饿汉式单例，一开始就new了一个对象

//class SingletonPattern
//{
//private:
//	SingletonPattern()
//	{
//		std::cout << "私有的构造函数" << std::endl;
//	}
//public: //构造函数被私有化了，所以应该提供一个对外访问的方法，来创建对象
//	std::mutex cs;
//	static SingletonPattern* get_single()
//	{
//		cs.lock();
//		if (single == NULL) //为保证单例，只new一次
//		{					//如果不加这个判断，每次创建对象都会new一个single，这就不是单例了
//			single = new SingletonPattern;
//		}
//		cs.unlock();
//		return single; //静态成员属于整个类，没有this指针
//	}
//private: //static 成员，类定义的所有对象共有static成员
//	static SingletonPattern* single; //指针，不能是变量，否则编译器不知道如何分配内存
//};
int main()
{
    
}
