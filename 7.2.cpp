#include <iostream>
using namespace std;
void GetMemory(char **p, int num){
	//此处用的是指向指针的指针来传递动态内存
	//亦可用函数的返回值为指针来传递动态内存
	*p = (char *)malloc(sizeof(char) * num);
};

int main(){
	char *str = NULL;
	GetMemory(&str,100);//这里传的是指针的地址，也就是指针的指针
	strcpy(str,"hello");
	cout << *str<<endl;
	cout << str<<endl;
	cout << &str<<endl;
	return 0;
}