#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    int pid;
    int child_pid, wait_time, run_time;
    pid = fork();
    if (pid < 0)
    {
        printf(1, "fork faild!\n");
        exit();
    }
    if (pid == 0)
    {
        printf(1, "child created with pid %d\n", getpid());
    }
    else
    {
        for (int i = 0; i < 1000; i++) //use as delay for wait child
        {
            printf(1, "%d", i);
        }
        child_pid = waitx(&wait_time, &run_time);
        printf(1, "\n Parent wait time : %d , Parent RunTime : %d with cildpid : %d\n", wait_time, run_time, child_pid);
    }
    exit();
}