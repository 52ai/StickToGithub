#include <iostream>
using namespace std;

/**
dynamic_cast 主要用于多态的时候，它循序在运行时刻进行类型转换，从而使程序能在一个类的层次结构中安全的转换类型个
把基类指针（引用）转换为派生类的指针（引用）。
**/

class A{
public:
	virtual void Print(){cout << "This is class A."<<endl;}
};

class B: public A{
public:
	void Print(){cout << "This is class B."<<endl;}
};

class C: public A{
public:
	void Print(){cout << "This is class C."<<endl;}
};

void Handle( A *a){
	if(dynamic_cast<B*>(a)){
		cout << "I am a B truly."<<endl;
	}
	else if(dynamic_cast<C*>(a)){
		cout << "I am a C truly."<<endl;
	}
	else{
		cout << "I am alone."<<endl;
	}
}

int main(int argc, char const *argv[])
{
	A *pA = new B();
	Handle(pA);
	
	pA = new C();
	Handle(pA);
	return 0;
}