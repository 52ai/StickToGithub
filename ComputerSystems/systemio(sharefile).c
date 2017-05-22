#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
	int fd1,fd2;
	char c;
	fd1 = open("foo1", O_RDONLY,0);
	fd1 = open("foo1", O_RDONLY,0);
	read(fd1,&c,1);
	read(fd2,&c,1);
	printf("c=%c\n",c);

	int fd;
	char c1;
	fd = open("foo1",O_RDONLY,0);
	if(fork()==0){//fork()函数成功调用子进程返回0，父进程返回子进程ID
		printf("这是子进程!\n");
		read(fd, &c1,1);
		//read(fd, &c1,1);
		exit(0);
	}
	else
		printf("这是父进程1!\n");

	wait(NULL); //wait()函数用于使父进程(也就是调用wait()的进程)阻塞，直到一个子进程结束或该进程接收到一个指定的信号为止。
	read(fd,&c1,1);
	printf("这是父进程2!\n");
	printf("c1=%c\n",c1 );

	exit(0);
}