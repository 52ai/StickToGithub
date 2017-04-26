#include <iostream>
#include <stdio.h>
#include <unistd.h>

/**

sleep()函数在windows系统和linux系统下是两个不同的函数，差别较大，但功能相同，都是将进程挂起一段时间

windows下函数名为Sleep()在<windows.h>头文件中，参数为毫秒

linux下函数名为sleep(),参数为秒,在<unistd.h>头文件中（usleep()精度更高，单位为微妙）

**/
void timer(double x){
	double cnt;
	cnt = x*1000;
	usleep(cnt);//sleep函数，每次1us，cnt次表示1ms
}

int main(int argc, char const *argv[])
{
	timer(3);
	printf("3秒过去了！\n");

	printf("你");
	fflush(stdout);//强制刷新缓存，输出显示

	//举一反三，fflush(stdin)清理标准输入流，把多余的仍未被保存的数据扔掉
	
	for(int i=0;i<10;i++){
		sleep(1);//linux下使用sleep,参数单位为秒
		printf(".");
		fflush(stdout);//强制刷新缓存，输出显示
	}
	printf("好！\n");//你与好之间隔十秒输出
	return 0;
}