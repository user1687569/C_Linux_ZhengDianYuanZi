#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t pid;

    pid = fork();
    switch (pid) {
    case -1:
        perror("fork error");
        exit(-1);
    case 0:
        printf("这是子进程打印信息<pid:%d, 父进程pid:%d>\n",
               getpid(), getppid());
        _exit(0);
    default:
        printf("这是父进程打印信息<pid:%d, 子进程pid:%d>\n",
               getpid(), pid);
        exit(0);
    }
}

/*
上述代码中，case0是子进程的分支，这里使用了_exit()结束进程而没有使用exit().
Tips:C库函数exit()建立在系统调用_exit()上，这里我们强调，在调用了fork()之后，
父、子进程中一般只有一个会通过调用exit()推出进程，而另一个则应使用_exit()退出，
具体原因将会在后面章节内容中向大家做进一步说明!
*/

