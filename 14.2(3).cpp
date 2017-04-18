#include <iostream>
#include <stdio.h>
#define MAX_LEN 10000
void LoopMove(char *pStr, int steps){
	char *p;
	if(NULL == pStr || steps < 0) throw "invalid arguments(s)";

	while(steps){
		printf("steps:%d\n",steps );

		p=pStr;//p指向pStr的头指针
		char temp_pre;
		char temp_next;
		temp_pre = *p;
		while(*(p+1)!= '\0'){
			temp_next = *(p+1);//保留后一个值
			*(p+1) = temp_pre;//前一个值覆盖后一个值
			temp_pre = temp_next;//更新前驱
			p++;//指针右移一位
		}
		*pStr = temp_pre;
		steps--;
	}

}

void LoopMove1(char *pStr, int steps){//直接用内置函数实现，使用strcpy字符串拷贝函数，截取再拼接
	int n=strlen(pStr) -steps;
	char tmp[MAX_LEN];
	strcpy(tmp, pStr+n);
	strcpy(tmp+steps,pStr);
	*(tmp + strlen(pStr)) = '\0';
	strcpy(pStr,tmp);


}

void LoopMove2(char *pStr, int steps){//使用memcpy内存拷贝函数，截取在拼接
	int n = strlen(pStr) -steps;
	char tmp[MAX_LEN];
	memcpy(tmp,pStr+n,steps);
	memcpy(tmp+steps, pStr, n);
	memcpy(pStr,tmp,n);

}


int main(int agrc, char const *argv[]){
	//char pStr[9]={'a','b','c','d','e','f','g','h','i'};//这么定义会有错，因为少了结束符'\0'

	char pStr[] = {'a','b','c','d','e','f','g','h','i','\0'};
	char pStr1[] = {'a','b','c','d','e','f','g','h','i','\0'};
	char pStr2[] = {'a','b','c','d','e','f','g','h','i','\0'};


	int steps = 2;

	LoopMove(pStr, steps);
	LoopMove1(pStr1, steps);
	LoopMove1(pStr2, steps);



	//printf("%c\n",*(pStr+1));
	printf("%s\n",pStr);
	printf("%s\n",pStr1);
	printf("%s\n",pStr2);



	return 0;
}