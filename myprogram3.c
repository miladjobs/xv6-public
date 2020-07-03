#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"

int main(void){
    int pid = fork();
    if (pid == 0)
    {
        fork();
        fork();
        fork();
        fork();
        int pidx = getpid();
        switch (pidx % 8)
        {
        case 0:
            printf(1, "Initializing process %d, priority: %d\n", pidx, 90);
            set_priority(pidx, 90); //set priority in it's queue
            nice(pidx, 1); // set it's queue
            break;
        case 1:
            printf(1, "Initializing process %d, priority: %d\n", pidx, 70);
            set_priority(pidx, 70);
            nice(pidx, 3);
            break;
        case 2:
            printf(1, "Initializing process %d, priority: %d\n", pidx, 50);
            set_priority(pidx, 50);
            nice(pidx, 1);
            break;
        case 3:
            printf(1, "Initializing process %d, priority: %d\n", pidx, 20);
            set_priority(pidx, 20);
            nice(pidx, 3);
            break;
        case 4:
            printf(1, "Initializing process %d, priority: %d\n", pidx, 30);
            set_priority(pidx, 30);
            nice(pidx, 2);
            break;
        case 5:
            printf(1, "Initializing process %d, priority: %d\n", pidx, 80);
            set_priority(pidx, 80);
            nice(pidx, 3);
            break;
        case 6:
            printf(1, "Initializing process %d, priority: %d\n", pidx, 10);
            set_priority(pidx, 10);
            nice(pidx, 1);
            break;
        default:
            printf(1, "Initializing process %d, priority: %d\n", pidx, 60);
            set_priority(pidx, 60);
            nice(pidx, 2);
            break;                        
        }
        sleep(5);
        int i;
        for (i = 0; i < (getpid()%8) * 100000; i++) //some work
        {
            continue;
        }
        exit();
    }
    else
    {
        sleep(5);
        printf(1, "Run ps command \n");
        xps();
        exit();
    }
    
    
}