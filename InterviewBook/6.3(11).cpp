#include <iostream>
#include <memory.h>
#include <assert.h>

using namespace std;

class A{

};

class A2{

};

class B:public A{

};

class C:public virtual B{

};

class D:public A,public A2{

};

int main(int argc, char *argv[]){

	cout << sizeof(A)<<endl;//一个空类所占空间为1
	cout << sizeof(B)<<endl;//单一继承的空类空间也为1
	cout << sizeof(C)<<endl;//虚继承这里设计到虚表（虚指针）程序输出为8
	cout << sizeof(D)<<endl;//多重继承的空类所占空间为1

	return 0;

}