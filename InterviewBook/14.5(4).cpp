#include <iostream>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	const char *str = "i come from tianjin.";
	char tmp[1000];
	char *p,*q,*r,swap_tmp;
	int lenStr = strlen(str);
	printf("lenStr:%d\n",lenStr);
	int j=0;
	for(int i=lenStr-1;i>=0;i--){
		tmp[j++] = str[i];//先把str按字母倒序放进tmp
	}
	tmp[j]='\0';//结尾符

	//对tmp中的按单词正序过来，具体以空格作为标记
	p=tmp;
	q=tmp;
	while(*p!='\0'){
		if(*p == ' '){//当p指针在扫描的过程中碰到空格，则进行正序操作
			r=p-1;//从p的上一个字符开始往回扫
			while(r>q){//交换
				swap_tmp = *r;
				*r = *q;
				*q = swap_tmp;
				q++;r--;
			}
			q=p+1;//重置单词首位置
		}
		p++;//p继续向右扫描
	}

	printf("%s\n",tmp);
	return 0;
}