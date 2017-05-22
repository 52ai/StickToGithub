#include <iostream>
#include <stdio.h>
#include <math.h>

bool judge_prime(int num){
	bool flag=1;
	for(int i=2;i <= sqrt(num);i++){//注意平方根这，应该是有等号的
		if(num % i == 0) {flag = 0;break;}
	}
	return flag;

}

int main(int argc, char const *argv[])
{
	int n;
	printf("请输入正整数n：");
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		if(judge_prime(i)) printf("%d  ", i);
	}
	printf("\n");
	return 0;
}