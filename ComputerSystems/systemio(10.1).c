#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h> //定义访问权限位
#include <fcntl.h>

int main( int argc, char const *argv[]){
	int fd1, fd2;

	fd1=open("foo1", O_RDONLY, 0);
	printf("fd1=%d\n",fd1);
	close(fd1);
	fd2=open("foo2",O_RDONLY,0);
	printf("fd2=%d\n",fd2);

	//一次一个字节的从标准输入拷贝到标准输出

	char c;
	while(read(STDIN_FILENO,&c,1) !=0)
		write(STDOUT_FILENO, &c,1);
	exit(0);
}