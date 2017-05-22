#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	for(int i=0;i<2;i++){
		fork();
		printf("ppid=%d,pid=%d,i=%d\n",getppid(),getpid(),i);
	}
	sleep(10);
	return 0;
}

/**

output:


ppid=35965,pid=36293,i=0
ppid=35965,pid=36293,i=1
ppid=36293,pid=36294,i=0
ppid=36293,pid=36294,i=1
ppid=36293,pid=36295,i=1
ppid=36294,pid=36296,i=1

**/