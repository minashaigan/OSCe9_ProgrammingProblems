#include <sys/types.h> 
#include <stdio.h> 
#include <unistd.h>
#include <stdbool.h>

#define MIN_PID 300
#define MAX_PID 5000

int allocate_map(void);
int allocate_pid(void);
void release_pid(int pid);

struct pid_table
{
    int pid;
    bool bitmap;
};
struct pid_table pidArr[4700];

int main() 
{ 
	int pid = allocate_pid();
	/* fork a child process */ 
	pid = fork();
	if (pid < 0) 
	{ 
		/* error occurred */
		 fprintf(stderr, "Fork Failed"); 
		return 1; 
	} 
	else if (pid == 0) 
		{ 
			/* child process */ 
			printf("pid : %d\n",pid);
			execlp("/bin/ls","ls",NULL); 
		} 
		else 
		{ 
			printf("pid : %d\n",pid);
			/* parent process */ 
			/* parent will wait for the child to complete */ 
			wait(NULL); 
			release_pid(pid);
			printf("Child Complete\n"); 
		} 
	return 0;
}

int allocate_map(void)                                  
{
    int i,j;
    for(i = MIN_PID, j =0; i <= MAX_PID; i++, j++)
    {
        pidArr[j].pid = i;
        pidArr[j].bitmap = 0;
    }

    if(i == MAX_PID && j == 4700)
    return 1;

    else
    return -1;
}

int allocate_pid(void)                                
{
	int i,j;
    for(i = MIN_PID,j=0; i <= MAX_PID; i++, j++)
    {
        if(pidArr[j].bitmap == 0)
        {
            pidArr[j].pid = i;
            pidArr[j].bitmap = 1;
            return i;
            break;
        }
    }

    return -1;
}

void release_pid(int pid)                               
{
	int i;
    for(i = 0; i <= 4700; i++)
    {
        if(pidArr[i].pid == pid)
        {
            pidArr[i].bitmap = 0;
        }
    }
}
