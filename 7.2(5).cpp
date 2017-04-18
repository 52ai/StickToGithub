#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;

class A{
public:
	A(){m_a =1; m_b=2;}
	~A(){};
	void fun(){printf("%d%d\n",m_a,m_b);}
public:
	int m_a;
	int m_b;
};

class B{
public:
	B(){m_c=3;}
	~B(){};
	void fun(){printf("%d\n",m_c);}
public:
	int m_c;
};

int main(int argc, char const *argv[])
{
	A a;
	B* pb=(B*)(&a);
	cout << &a << endl;//打出a的地址
	cout << &(a.m_a) <<endl;//打出a.m_a的地址
	printf("%p\n",&A::m_a);//打出m_a对于A的内存偏移量
	printf("%p\n",&A::m_b);//打出m_b对于A的内存偏移量
	printf("%p\n",&B::m_c);//打出m_c对于B的内存偏移量
	pb->fun();

	return 0;
}

