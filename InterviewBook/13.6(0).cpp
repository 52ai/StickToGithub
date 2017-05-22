#include <stdio.h>
#include <stdlib.h>

int g1=0,g2=0,g3=0;

//char *p1;
int main(int argc, char const *argv[]){
	char* p3 = "123456";
	//char* p1 = (char*)malloc(10);
	char *p1 = "123456";
	printf("p3:%s,%08x\n",p3,&p3);
	printf("p1:%s,%08x\n",p1,&p1);

	int v1=0,v2=0,v3=0;
	static int s1=0,s2=0,s3=0;
	//static 直接搞到静态数据区,区别去const
	//const 在C中的意思是一个不能被改变的普通变量，它总是占用内存，而且它的名字是全局符（外部链接）但C++默认为内部链接
	//C编译器不能把const看成一个编译期间的常量。
	//const bufsize 在C中可以看成声明，这个声明指明在别的地方有内存分配，但是在C++中是不对的，因为C++默认const为内部链接
	//如果硬是要在C++完成C中同样的事情，必须用extern 把内部链接改成外部链接
	//extern const bufsize;//declaration only

	//mutable 是为了突破const的限制而设置的


	printf("-----栈区-----\n");
	printf("0x%08x\n",&v1);
	printf("0x%08x\n",&v2);
	printf("0x%08x\n",&v3);
	printf("-----全局区（静态区）-----\n");
	printf("0x%08x\n",&g1);
	printf("0x%08x\n",&g2);
	printf("0x%08x\n",&g3);
	printf("-----静态区-----\n");
	printf("0x%08x\n",&s1);
	printf("0x%08x\n",&s2);
	printf("0x%08x\n",&s3);


}