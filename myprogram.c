#include "types.h"
#include "stat.h"
#include "user.h"


int
main(void)
{
    int f = fork();
    if (f != 0)
    {
        f = fork();
        if (f != 0)
        {
            malloc(7 * sizeof(int));
        }
        else
        {
            malloc(10 * sizeof(int));
        }
        wait();
    }
    else
    {
        f = fork();
        if (f != 0)
        {
            malloc(15 * sizeof(int));
            wait();
        }
        else
        {
            malloc(5*sizeof(int));
            int maxProcs = 64;
            struct proc_info *processes = malloc(maxProcs*sizeof(struct proc_info));
            int N = getprocs(maxProcs, processes);
            for (int i = 0; i < N; i++)
            {
                printf(2, "Process with pid : %d has memory size : %d \n", processes[i].pid, processes[i].memsize);
            }
        }
    }
    
    wait();
    exit();
}