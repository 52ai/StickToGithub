//01：赋值运算符函数
//题目：如下为类型CMyString的声明，请为该类型个添加赋值运算符函数

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

class CMyString{
public:
	CMyString(char* pData=NULL);
	CMyString(const CMyString& str);
	~CMyString(void);

	CMyString& operator = (const CMyString& str);

	void Print();
private:
	char* m_pData;
};

//构造函数
CMyString::CMyString(char *pData){
	if(pData == NULL){
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else{
		int length = strlen(pData);
		m_pData = new char[length+1];
		strcpy(m_pData,pData);
	}
}

//复制构造函数
CMyString::CMyString(const CMyString &str){
	int length = strlen(str.m_pData);
	m_pData = new char[length+1];//申请空间
	strcpy(m_pData,str.m_pData);
}

//析构函数
CMyString::~CMyString(){
	delete[] m_pData;
}

//赋值运算符函数
CMyString& CMyString::operator = (const CMyString& str){
	if(this == &str) return *this;//如果传入的参数和当前实例（*this）是同一个实例，则直接返回

	delete[] m_pData;
	m_pData = NULL;
	m_pData=new char[strlen(str.m_pData)+1];//如果内存不足失败怎么办，那m_pData是一个空指针？
	strcpy(m_pData, str.m_pData);
	return *this;
}

void CMyString::Print(){
	printf("%s",m_pData);
}


void Test1(){
	char* text = "Hello world";
	CMyString str1(text);
	CMyString str2;
	str2 = str1;
	printf("The expected result is:%s.\n",text);
	printf("The actual result:");
	str2.Print();
	printf(".\n");
}

void Test2(){
	char* text = "Hello world";
	CMyString str1(text);
	str1 = str1;
	printf("The expected result is:%s.\n",text);
	printf("The actual result:");
	str1.Print();
	printf(".\n");
}

void Test3(){
	char* text = "Hello world";
	CMyString str1(text);
	CMyString str2,str3;
	str3=str2 = str1;

	printf("The expected result is:%s.\n",text);
	printf("The actual result:");
	str2.Print();
	printf(".\n");

	printf("The expected result is:%s.\n",text);
	printf("The actual result:");
	str3.Print();
	printf(".\n");

}



int main(int argc, char const *argv[])
{
	Test1();
	Test2();
	Test3();
	return 0;
}