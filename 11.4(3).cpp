#include <iostream>
#include <stdio.h>
using namespace std;

class A{
	public:
		void foo(){cout <<"this foo() belongs to A"<<endl;};
};

class B{
	public:
		void foo(){cout <<"this foo() belongs to B"<<endl;};

};

class C : public A, public B{

};

class D : public A{

};


int main(int argc, char const *argv[])
{
	C c;
	D d;
	//c.foo()  这么写是有问题的，因为C 是多继承于A和B,C中有两个foo()函数，因此需要通过以下方法访问
	c.A::foo();
	c.B::foo();

	d.foo();//由于D是单继承于A，因此可以这么写

	return 0;
}