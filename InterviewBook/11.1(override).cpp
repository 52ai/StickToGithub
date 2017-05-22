#include <iostream>
using namespace std;

class A{
	protected:
		int m_data;

	public:
		A(int data=0){m_data=data;}

		int GetData(){return doGetData();}

		virtual int doGetData(){return m_data;}

};


class B:public A{
	protected:
		int m_data;
	public:
		B(int data=1){m_data=data;}
		int doGetData(){return m_data;}
};

class C:public B{
	protected:
		int m_data;
	public:
		C(int data=2){m_data=data;}
};


int main(int argc, char const *argv[])
{
	C c(10);
	cout << c.GetData()<<endl;//1
	cout << c.A::GetData()<<endl;//1
	cout << c.B::GetData()<<endl;//1
	cout << c.C::GetData()<<endl;//1
	cout << c.doGetData()<<endl;//1
	cout << c.A::doGetData()<<endl;//0（直接调用了A的doGetData()函数，所以输出为0）
	cout << c.B::doGetData()<<endl;//1（直接调用了B的doGetData()函数，所以输出为1）
	cout << c.C::doGetData()<<endl;//1（由于C类中未重新定义该接口，所以调用B类中的doGetData()(这里存在一个就近调用)）

	return 0;
}