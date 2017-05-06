#include <iostream>
using namespace std;

class A{
private:
	int value;
public:
	A(int n){value = n;}
	A(const A &other){value = other.value;}//复制构造函数不能传值，需要改为常量引用

	void Print(){cout << value << endl;}
};

int main(int argc, char const *argv[])
{
	A a=10;
	A b=a;

	b.Print();
	return 0;
}