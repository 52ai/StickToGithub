#include <iostream>
using namespace std;

template<class T>
//建立一个静态模板类

class Operate{
public:
	static T Judge(T a, T b=1){
		if(a>=0) return a;
		else return a/b;
	}
	static T Add(T a, T b){return a+b;}
	static T Minus(T a, T b){return a-b;}
};

int main(int argc, const char *argv[]){
	int a=1,b=2,c=3,d=4,e=5;

	cout << Operate<int>::Judge(a,b)<<endl;
	cout << Operate<int>::Add(a,b)<<endl;
	cout << Operate<int>::Minus(a,b)<<endl;

	return 0;
}

