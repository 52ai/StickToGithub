#include <stdio.h>
int main(){
	char a;
	char a1;
	int b;
	int c;
	printf("0x%08x\n",&a);
	printf("0x%08x\n",&a1);
	printf("0x%08x\n",&b);
	printf("0x%08x\n",&c);

	/*考虑到内存对齐
	0x57ee4adb char虽然长度为1这个字节，但是分配内存的时候给了四个字节（a a1的话，也还是占四个字节）
	0x57ee4ad4
	0x57ee4ad0
	*/
	return 1;
}