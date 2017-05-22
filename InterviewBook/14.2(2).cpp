#include <iostream>
#include <stdio.h>

int main(int argc, char const *argv[]){

	char res[] = "123456789";
	char des[] = "123";

	printf("0X%08X\n",&res);
	printf("0X%08X\n",&des);

	strcpy(des,res);
	printf("res=%s\ndes=%s\n",res,des);

	printf("0X%08X\n",&res);
	printf("0X%08X\n",&des);

	//动态分配内存
	int count, *array;

	if((array = (int *)malloc(10*sizeof(int))) == NULL){
	//分配10个整型的连续的存储空间
	//并返回一个指向其起始地址的整型指针array
		printf("不能成功分配存储空间！\n");
		exit(1);
	}

	for(count=0;count < 10;count++) array[count] = count;//给数组赋值

	for(count=0;count < 10;count++) printf("%2d",array[count]);
	printf("\n");
	printf("array[0]:%d\n",*array);
	//用malloc申请的动态空间，不用的话，可以把它free掉
	free(array);
	printf("array[0]:%d\n",*array);//尽管被free掉了，但是array的指向并没有改变，free的结果只是说明该空间是空闲可以重新分配
	//此时的array被称为悬浮指针
	char *ch;
	if((ch = (char*)malloc(10*sizeof(char))) == NULL){
		printf("不能成功分配存储空间！\n");
		exit(1);
	}
	for(count=0;count<10;count++) ch[count] = count + '0';
	for(count=0;count<10;count++) printf("%2c",ch[count]);
	printf("\n");



	return 0;
}