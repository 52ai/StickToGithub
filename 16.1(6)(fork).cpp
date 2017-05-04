#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int i=1;
	if(!fork()) i++;
	printf("%d\n",i);
	if(!fork()) i++;
	printf("%d\n",i);
	return 0;
}

/**
fork 英文的意思是叉。在这里的意思是进程从这里开始分叉，分成两个进程：一个父进程，一个子进程。
子进程复制了父进程的绝大部分栈、缓冲区等等。
系统为子进程创建一个新的进程表项，其中进程id与父进程是不相同的。
当涉及数据时子进程有自己的数据空间，在有数据修改时，系统会为子进程申请新的页面
**/