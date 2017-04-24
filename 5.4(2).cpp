#include <stdio.h>

//大端存储，是指对于一个跨多个字节的数据，其高端存放在高地址中，其低端位放在低地址中
//小端存储则与大端存储相反，高位放在低地址中，低位放在高地址中
//无符号数，高位补0
//有符号数，高位补1

int main(int argc, char const *argv[]){
	unsigned int a = 0xddFFFFcc;
	unsigned char i= (unsigned char)a;//强制转换
	char* b =(char *)&a;//把&a强制转换为char*指针，这时候会发生截断，截断后指针指向0xcc(小端存储，低地址放低位数据)

	printf("%08x, %08x\n",i,*b);//区别在于i为无符号数，*b为有符号数
	char c;
	short x = 0x2233;
	c = ((char*)&x)[0];//用长度为1B的char类型去截断长度为2B的short类型，看看其低地址放的是short类型的高位还是低位
	printf("%08x\n",c);


}