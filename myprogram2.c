#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    int pid = fork();
    if (pid == 0)
    {
        fork();
        fork();
        fork();
        fork();
        int pidx = getpid();
        if (pidx % 8 == 0)
        {
            printf(1, "Initializing process %d, priority : %d\n", pidx, 90);
            set_priority(pidx, 90);
        }
        else if (pidx % 8 == 1)
        {
            printf(1, "Initializing process %d, priority : %d\n", pidx, 70);
            set_priority(pidx, 70);
        }
        else if (pidx % 8 == 2)
        {
            printf(1, "Initializing process %d, priority : %d\n", pidx, 80);
            set_priority(pidx, 80);
        }
        else if (pidx % 8 == 3)
        {
            printf(1, "Initializing process %d, priority : %d\n", pidx, 20);
            set_priority(pidx, 20);
        }
        else if (pidx % 8 == 4)
        {
            printf(1, "Initializing process %d, priority : %d\n", pidx, 50);
            set_priority(pidx, 50);
        }
        else if (pidx % 8 == 5)
        {
            printf(1, "Initializing process %d, priority : %d\n", pidx, 30);
            set_priority(pidx, 30);
        }
        else if (pidx % 8 == 6)
        {
            printf(1, "Initializing process %d, priority : %d\n", pidx, 10);
            set_priority(pidx, 10);
        }
        else
        {
            printf(1, "Initializing process %d, priority : %d\n", pidx, 60);
            set_priority(pidx, 60);
        }
        
        for (int i = 0; i < getpid() * 100000; i++) //some works
        {
            continue;
        }
        
        exit();
    }
    else
    {
        sleep(20000);
        printf(1, "------Running ps-----\n");
        xps();
        wait();
        exit();
    }
    
    
}