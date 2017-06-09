#include <sys/types.h> 
#include <stdio.h> 
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

bool isInteger(float val);

int main() 
{ 
	const int SIZE = 4096; 
	const char *name = "OS";
	char *message;
	int shm_fd;
	void *ptr;

	/* create the shared memory segment */
	shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);

	/* configure the size of the shared memory segment */
	ftruncate(shm_fd,SIZE);

	/* now map the shared memory segment in the address space of the process */
	ptr = mmap(0,SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
	if (ptr == MAP_FAILED) {
		printf("Map failed\n");
		return -1;
	}

	float n;
	printf("n : ");
	scanf("%f",&n);
	while(n<=0 && isInteger(n)){
		printf("you must enter a positive value");	
		scanf("%f",&n);
	}
	int num = (int)n;
	

	pid_t pid;
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
			sprintf(message,"%d",num);
			sprintf(ptr,"%s",message);
			ptr += strlen(message);
			while(num != 1){
				if(num%2 == 0){
					num = num/2;			
				}
				else{
					num = 3*num+1;			
				}
				sprintf(message,", %d",num);
				sprintf(ptr,"%s",message);
				ptr += strlen(message);
			}
		} 
		else 
		{ 
			/* parent process */ 
			/* parent will wait for the child to complete */ 
			wait(NULL);
			/* open the shared memory segment */
			shm_fd = shm_open(name, O_RDONLY, 0666);
			if (shm_fd == -1) {
				printf("shared memory failed\n");
				exit(-1);
			}

/* now map the shared memory segment in the address space of the process */
			ptr = mmap(0,SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
			if (ptr == MAP_FAILED) {
				printf("Map failed\n");
				exit(-1);
			}
			/* now read from the shared memory region */
			printf("%s",ptr);

			/* remove the shared memory segment */
			if (shm_unlink(name) == -1) {
				printf("Error removing %s\n",name);
				exit(-1);
			}
			printf("\nChild Complete\n"); 
		} 
	return 0;
}

bool isInteger(float val)
{
    int intVal = (int)val;
    return (val == intVal);
}
