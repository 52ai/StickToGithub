#include <iostream>
#include <stdio.h>

int mystrlen(char *buf, int N){
	//停止条件（基底情况）
	if(buf[0]=='\0' || N==0 ) return 0;
	else if(N==1) return 1;

	int t=mystrlen(buf, N/2);//折半递归求长度
	if(t<N/2) return t;//如果长度小于输入N的值，那么就取当前长度
	else return(t+mystrlen(buf+N/2, (N+1)/2));
	//如果长度等于当前长度，说明当前长度里面没有结束符，因此取下一个字符并继续递归，并累加上之前的长度



}

int main(int argc, char const *argv[])
{
	char buf[]={'a','b','c','d','e','f','\0','x','y','z'};
	printf("%d\n",mystrlen(buf,5));
	return 0;
}