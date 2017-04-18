#include <iostream>
#include <stdio.h>
using namespace std;

const char* mystr(const char* string, const char* substr){
	if(NULL == substr || NULL == string) throw "invalid arguments(s)";
	const char *p,*q,*start;

	static char reStr[1000];//没有static 否则返回的时候会有警告
	
	char *tmp;
	p=string;//指向母串的头指针
	q=substr;//指向子串的头指针
	start=p;//记录这一轮开始匹配的位置
	while(*p!='\0'){
		if(*p == *q){
			p++;
			q++;
		}
		else{
			p++;//没有匹配上则搜索串后移一位
			q=substr;//模式串中的匹配位置初始化为第一个字符
			start=p;//重置新一轮匹配位位置
		}

		if(*q == '\0'){//找到模式串,将要求的字符串写到reStr中
			tmp = reStr;
			while(*start != '\0'){
				*tmp=*start;
				tmp++;
				start++;
			}
			*tmp = '\0';
			return reStr;
		} 
	}

	printf("没有匹配到目标字符串！\n");
	return reStr;
}

int main(int argc, char const *argv[])
{
	const char *string = "12345678";
	const char *strCharSet = "45";
	printf("string:%s\n",string);
	printf("strCharSet:%s\n",strCharSet);
	printf("return:%s\n",mystr(string,strCharSet));
	return 0;
}
