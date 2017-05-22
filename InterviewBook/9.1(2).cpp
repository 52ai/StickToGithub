#include <iostream>
#include <vector>
using namespace std;

class CDemo{
public:
	CDemo():str(NULL){}
	~CDemo(){
		if(str) {
			static int i=0;
			cout << "&CDemo"<<i++<<"="<<(int*)this<<",str="<<(int*)str<<endl;
			delete[] str;
		}

	}

	CDemo(const CDemo &cd){//使用深复制技术的复制构造函数之后，问题就解决了
		this->str = new char[strlen(cd.str) + 1];
		strcpy(str,cd.str);
	}

	char* str;
};

int main(int argc, char const *argv[])
{
	CDemo d1;
	d1.str = new char[32];
	strcpy(d1.str, "wayne yu");

	vector<CDemo> *a1 = new vector<CDemo>();
	a1->push_back(d1);
	delete a1;
	//malloc: *** error for object 0x7fe9a0503050: pointer being freed was not allocated 
	//*** set a breakpoint in malloc_error_break to debug
	//重复delete同一片内存，程序崩溃

	//&CDemo0=0x7fd9a8403250,str=0x7fd9a8403210
	//&CDemo1=0x7fff5891e910,str=0x7fd9a8403210

	//发生了两次析构，两次析构str指向同一内存地址空间
	//a1->push_back(d1)会调用CDemo类的复制构造函数，由于没有自定义，因此编译器会为CDemo类构建一个默认的复制构造函数
	//这里需要注意的是编译器构建的默认复制构造函数，使用的是浅复制技术

	//因此解决问题的办法就是添加一个使用深复制的复制构造函数



	return 0;
}