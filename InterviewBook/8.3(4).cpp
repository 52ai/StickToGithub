#include <iostream>
#include <stdio.h>

void histogram(char *src){
	int i;
	int  hist[256];
	for(i=0;i<256;i++){
		hist[i]=0;
	}
	while(*src != '\0'){
		hist[*src] ++;//*src字符隐式转为ascii值作为数组的坐标，++表示ascii从48开始累加
		src++;
	} 

	for(i=0;i<256;i++){
		if(hist[i]) printf("ascii值：%d,字符：%c,出现次数：%d\n",i,i,hist[i]);
		//整型数组坐标i通过%c格式化输出可以输出其对应的字符形式
	}

}


int main(int argc, char const *argv[])
{
	char *src = "aaaabcde12345567";
	histogram(src);
	return 0;
}