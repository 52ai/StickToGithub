#include <iostream>
using namespace std;


class A{
	int m_nA;
};

class B{
	int m_nB;
};

class C : public A, public B{
	int m_nC;
};



int main(int argc, char const *argv[])
{
	C* pC = new C;
	B* pB = dynamic_cast<B*>(pC);//pB 实际上指向的是对象C中的父类B部分，从地址上跟pC不一样
	A* pA = dynamic_cast<A*>(pC);

	cout << pC<<endl;
	cout << pB<<endl;
	cout << (C*)pB<<endl;//此时与pC是相等的

	if(pC == pB){cout << "euqal"<<endl;}
	else {cout << "not equal"<<endl;}


	cout << pC << endl;
	cout << pB << endl;

	//cout << int(pC)<<endl;
	//cout << int(pB)<<endl;
	//ERROR: cast from pointer to smaller type 'int' loses information

	//解决办法如下：

	cout << uintptr_t(pC)<<endl;
	cout << uintptr_t(pB)<<endl;//pC和pB的值不同，转成int后值也不相同

	//不过uintptr_t(pC) 与 uintptr_t(pB)的值就相同了










	return 0;
}
