#include <iostream>
using namespace std;

class A{
public:
	virtual void Print(){cout << "This is class A."<<endl;}
};

class B : public A{
public:
	void Print(){cout <<"This is class B."<<endl;}
};

struct C
{
	void Print(){cout << "This is struct C."<<endl;}
};


int main(int argc, char const *argv[])
{
	short s=2;
	short s1=3;
	unsigned ui=10;
	int i=10;
	char ch='a';
	wchar_t wch=L'b';
	float f=1.0f;
	double d = 2;

	cout << typeid(s).name()<<endl;
	cout << typeid(ui).name()<<endl;
	cout << typeid(i).name()<<endl;
	cout << typeid(ch).name()<<endl;
	cout << typeid(wch).name()<<endl;
	cout << typeid(f).name()<<endl;
	cout << typeid(d).name()<<endl;

	cout <<typeid(s).before(typeid(ui))<<endl;//判断s是否在ui之前出现的bool值
	cout <<(typeid(s) == typeid(s1))<<endl;//判断s与s1的类型是否相同，相同则返回1

	//typeid的主要作用是让用户知道当前的变量是什么类型
	//typeid实际上是一个返回类型为type_info类型的函数
	//type_info类提供了public虚析构函数，以便用户可以用其作为基类
	//但他的默认构造函数和复制构造函数及其赋值操作符都定义为private，所以不能定义或复制type_info类型的对象
	//程序中创建type_info对象的唯一方法就是使用typeid操作符
	//如果把type_id看做函数的话，其应该是type_info类的友元
	//不过具体怎么实现，则由编译器的实现所决定，标准只要求实现为每个类型返回唯一的字符串

	A *pA = new A();
	A a2;

	cout << typeid(pA).name()<<endl;
	cout << typeid(a2).name()<<endl;

	B *pB = new B();
	cout << typeid(pB).name()<<endl;



	C *pC = new C();
	C c2;

	cout << typeid(pC).name()<<endl;
	cout << typeid(c2).name()<<endl;

	A *pA1 = new B();
	cout << typeid(pA1).name()<<endl;
	cout << typeid(*pA1).name()<<endl;//当A类中存在虚函数，则是动态类型，否则就是编译时期的事是静态类型




	return 0;
}