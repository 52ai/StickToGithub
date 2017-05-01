#include <iostream>
using namespace std;

class A{
public:
	virtual void Print(){cout << "This is class A."<<endl;}
};

class B{
public:
	virtual void Print(){cout << "This is class B."<<endl;}
};

class C : public A, public B{
public:
	void Print(){cout << "This is class C."<<endl;}
};


int main(int argc, char const *argv[])
{
	A *pA = new C();

	//C *pC = pA;
	//cannot initialize a variable of type 'C *' with an lvalue of type 'A *'
	C *pC = dynamic_cast<C *>(pA);
	if(pC != NULL){
		pC->Print();
	}
	delete pA;//new 与delete ,new [] 与 delete []  成对使用

	return 0;
}