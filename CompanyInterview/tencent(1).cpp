#include <stdio.h>
/**

确认机器是大端还是小端

大端是指高字节放在低位，由高向低
小端是指高字节放在高位，由低向高
**/

int main(int argc, char const *argv[]){

	char a;
	short b = 0x1122;

	a = ((char*)&b)[0];//低位
	if(a == 0x11) printf("大端!\n");
	if(a == 0x22) printf("小端!\n");

	return 1;
}