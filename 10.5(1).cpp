#include <iostream>
using namespace std;

class MyString{
	public:
		//普通构造函数
		MyString(const char *str = NULL);

		//复制构造函数
		MyString(const MyString &other);

		//析构函数
		~MyString(void);

		//赋值函数
		MyString& operator = (const MyString& other);

	public:
		char *m_data;//用于保存字符串

};


MyString::~MyString(void){//析构函数
	cout << "destructed!"<<endl;
	delete []m_data;
}

MyString::MyString(const char *str){//普通构造函数
	cout << "common constructed!" << endl;
	if(str == NULL){
		m_data = new char[1];//申请一个字符大小的堆空间，并让m_data字符指针指向它
		*m_data = '\0';//将m_data字符指针指向的堆空间内容赋值为'\0'
	}
	else{
		int length = strlen(str);
		m_data = new char[length+1];
		strcpy(m_data,str);
	}
}

MyString::MyString(const MyString &other){//复制构造函数
	cout << "copy constructed!" << endl;
	int length = strlen(other.m_data);
	m_data = new char[length+1];
	strcpy(m_data, other.m_data);
}

MyString& MyString::operator = (const MyString& other){//赋值函数

	cout << "evaluation function!"<<endl;
	//检查自赋值
	if(this == &other) return *this;

	//否则释放原有资源
	delete [] m_data;
	//分配新的内存资源，并复制内容
	int length = strlen(other.m_data);
	m_data = new char[length+1];
	strcpy(m_data,other.m_data);

	//返回本对象的引用
	return *this;//返回左操作数的引用

}

int main(int argc, char const *argv[])
{
	MyString str("hello");//调用的是普通构造函数
	cout << "str.m_data:"<<str.m_data<<endl;

	MyString s1("hello");
	cout << "s1.m_data:"<<s1.m_data<<endl;

	MyString s2=s1;//调用的是复制构造函数

	cout << "s2.m_data:"<<s2.m_data<<endl;


	MyString s3("hello");
	cout << "s3.m_data:"<<s3.m_data<<endl;
	MyString s4;
	cout << "s4.m_data:"<<s4.m_data<<endl;

	s3=s4;//调用了赋值函数
	cout << "s4.m_data:"<<s4.m_data<<endl;



	return 0;
}