#include <iostream>
#include<string>
#include<unordered_map>
enum Type {
	ROBOT_CAT = 0,
	ROBOT_DOG
};

class Robot {
protected:
	std::string  m_prototype_name;
	float m_stateOfCharge;
public:
	//列表初始化 比函数内初始化效率高 或const的无法函数内改 内部相当于赋值这里是初始化
	Robot() = default;
	Robot(std::string name):m_prototype_name(name){
		
	}
	virtual ~Robot() {}
	virtual Robot* clone()const = 0;
	virtual void setStateOfCharge(float) = 0;
};

class RobotCat :public Robot {
private:
	float m_CatValue = 0;
public:
	virtual ~RobotCat(){}
	//拷贝构造函数在以下几种情况中会自动调用：
	//	当创建一个新的 RobotCat 对象并用已有的 RobotCat 对象来初始化它时。
	//	当 RobotCat 对象按值传递给函数或从函数按值返回时。
	//	在某些情况下需要对对象进行深拷贝时（如果 RobotCat 有指针成员，就需要更复杂的拷贝
	//定义：这是一个拷贝构造函数，用于创建 RobotCat 对象的副本。
	//参数：接受一个 const RobotCat& 类型的引用作为参数，表示要复制的源对象。
	//	实现：将源对象的 m_CatValue 赋值给新对象的 m_CatValue 成员。

	RobotCat(const RobotCat& robot) {
		m_CatValue = robot.m_CatValue;
	}
	RobotCat(std::string name, float value) :Robot(name), m_CatValue(value) {
	
	}
	virtual Robot* clone() const override{
		return new RobotCat(*this);
	}
	virtual void setStateOfCharge(float value)override
	{
		m_stateOfCharge = value;
		std::cout << "--" << m_prototype_name << "当前电量：" << m_stateOfCharge << ",m_CatValue:" << m_CatValue << std::endl;
	}
};
class RobotDog :public Robot {
private:
	float m_DogValue = 0;
public:
	virtual ~RobotDog() {}
	RobotDog(const RobotDog& robot) {
		m_DogValue = robot.m_DogValue;
	}
	RobotDog(std::string name, float value) :Robot(name), m_DogValue(value) {

	}
	virtual Robot* clone() const override {
		return new RobotDog(*this);
	}
	virtual void setStateOfCharge(float value)override
	{
		m_stateOfCharge = value;
		std::cout << "--" << m_prototype_name << "当前电量：" << m_stateOfCharge << ",m_DogValue:" << m_DogValue << std::endl;
	}
};
class CloneFactory {
	std::unordered_map<Type, Robot*>m_prototype;
public:
	CloneFactory() {
		m_prototype[ROBOT_CAT] = new RobotCat("机器猫", 5.0);
		m_prototype[ROBOT_DOG] = new RobotDog("机器狗", 8.0);
	}
	~CloneFactory() {
		delete m_prototype[ROBOT_CAT];
		delete m_prototype[ROBOT_DOG];
	}
	Robot* createRobot(Type type) {
		return m_prototype[type]->clone();
	}
};

void clientcode(CloneFactory& cloneFactory) {
	std::cout << "克隆机器猫\n";
	Robot* cloneRobot = cloneFactory.createRobot(ROBOT_CAT);
	cloneRobot->setStateOfCharge(90);
	delete cloneRobot;
	cloneRobot = cloneFactory.createRobot(ROBOT_CAT);
	cloneRobot->setStateOfCharge(80);
	delete cloneRobot;
	std::cout << "克隆机器狗\n";
	cloneRobot = cloneFactory.createRobot(ROBOT_DOG);
	cloneRobot->setStateOfCharge(75);
	delete cloneRobot;

}
int main()
{
	CloneFactory cloneFactory;
	clientcode(cloneFactory);
}