#include <stdio.h>

//比较函数

int jug(int x, int y){
	if(x >= 0){return x;}
	else if(y == 0){return x;}
	else return x/y;
}

//求和函数

int sub(int x, int y){
	return (x+y);
}

//求差函数

int minus(int x,int y){
	return (x-y);
}

//函数指针


void test(int (*p)(int ,int ), int a, int b){
	int ret;
	printf("p:0x%x\n",p);
	printf("*p:0x%x\n",*p);
	printf("&p:0x%x\n",&p);//p在栈上，临时分配了空间

	ret = (*p)(a,b);
	printf("a=%d,b=%d  %d\n",a,b,ret);
}

int main(int argc, char const *argv[])
{
	int a=1,b=2,c=3,d=4,e=5;
	printf("sub:0x%x\n",sub);
	printf("&sub:0x%x\n",&sub);

	test(&sub,a,b);//函数指针，把函数作为参数传递 int (*p)(int,int) = &sub;
	test(sub,a,b);//
	test(minus,c,d);
	test(jug,e,b);
	return 0;
}