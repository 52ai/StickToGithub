#include <iostream>
using namespace std;

class B{
	private:
		int data;
	public:
		B(){cout << "default constructor"<<endl;}
		~B(){cout << "destructed"<<endl;}

		B(int i):data(i){cout << "constructed by parameter"<<data<<endl;}//带参数的构造函数

};

B Play(B b){
	return b;
}


int main(int argc, char const *argv[])
{
	B temp = Play(5);//单个参数的构造函数如果不添加explicit 关键字，会定义一个隐含的类型转换（从参数类型转换到自己）

	return 0;
}