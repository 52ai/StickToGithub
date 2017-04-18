#include <iostream>
#include <stdio.h>
#include <stdlib.h> 


int main(int argc, char const *argv[])
{
	int number=123456789,num,i=0,j=0;
	char temp[20],str[20];
	num = number;
	while(num){//整数转字符串，可采用+‘0’再逆序的办法
		temp[i]=num%10 + '0';
		i++;
		num=num/10;
	}
	i=i-1;
	for(j=0;j<i;j++,i--){//就地交换，没有另外申请辅助数组
		char tempch;
		tempch = temp[j];
		temp[j]=temp[i];
		temp[i]=tempch;
	}
	printf("temp=%s\n",temp);

	/*
	printf("i=%d\n",i);
	while(i>0){//把刚刚字符串再逆序过来
		str[j++]=temp[--i];
	}

	printf("str=%s\n",str);*/

	//如果使用itoa函数的话，则问题就简单多了,mac/linux 没有itoa函数，它不是标准的C库，可使用sprintf打印到字符串中
	/*
	num=number;
	itoa(num, str, 10);
	printf("interger = %d string = %s\n",num,str);*/
	num = number;
	sprintf(str,"%d",num);
	printf("str=%s\n",str);

	char str1[20]={'1','2','3','4','5','6','\0'};
	int sum=0;
	i=0;
	while(str1[i]){//字符串转整型可采用，每个字符-'0'然后*10再累加的结果
		sum = sum*10 + (temp[i]-'0');
		i++;
	}
	printf("sum=%d\n",sum);

	const char *str2="abcdef";
	i=0;
	while(str2[i]!='\0'){//%08X表示16进制,域宽为8，用0填充
		printf("0X%08X(%c)        ",str2[i],str2[i]);
		i++;
		if(i%3 == 0){printf("\n");}
	}
	printf("\n");

	/**
	d 有符号10进制整数
	i 有符号10进制整数 　　
	o 无符号8进制整数 　　
	u 无符号10进制整数 　　
	x 无符号的16进制数字，并以小写abcdef表示 　　
	X 无符号的16进制数字，并以大写ABCDEF表示
	**/



	return 0;
}