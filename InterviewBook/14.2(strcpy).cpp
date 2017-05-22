#include <iostream>
#include <stdio.h>
#include <assert.h>

char *strcpy(char *strDest, const char *strSrc){//实现字符串复制函数
	//利用断言，判断两个字符串
	//如果条件不成立，则assert会终止程序，assert一般用于调试程序的逻辑错误
	//assert((strDest!=NULL) && (strSrc != NULL));
	if( NULL == strDest || NULL == strSrc) throw "invalid arguments(s)";
	char *address = strDest;//保存strDest的头指针

	/*(方法1)
	int i=0;
	while(strSrc[i]!='\0'){
		strDest[i]=strSrc[i];
		i++;
	}
	strDest[i] = '\0';*/

	while((*strDest++ = *strSrc++) != '\0') NULL;

	return address;
}

int main(int argc, char const *argv[]){
//argv 表示参数的个数，0号是函数名，argv数组存的是参数的具体值（char *）
//const 在*号的左侧，用来修饰指针所指向的变量为常量，不允许对指针所指向的内容进行更改操作
//const 在*号的右侧，用来修饰指针本身，指针本身是常量，但它所指向的内容可以被修改
	char const *str1 = "my name is wayne!";
	char str2[100];
	char *str3;

	str3 = strcpy(str2,str1);

	printf("str1:%s\n",str1);
	printf("str2:%s\n",str2);
	printf("str3:%s\n",str3);






}