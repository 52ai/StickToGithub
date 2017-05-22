#include "csapp.h"
int main(int argc, char const *argv[])
{
	int fd1,fd2;
	char c;
	fd1 = open("foo1",O_RDONLY,0);
	fd2 = open("foo1",O_RDONLY,0);
	read(fd2,&c,1);
	dup2(fd2,fd1);//使用dup2函数进行重定向
	read(fd1,&c,1);
	printf("c=%c\n",c );
	return 0;
}