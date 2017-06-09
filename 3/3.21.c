#include <sys/types.h> 
#include <stdio.h> 
#include <unistd.h>
#include <stdbool.h>

bool isInteger(float val);

int main() 
{ 
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
			printf("%d",num);
			while(num != 1){
				if(num%2 == 0){
					num = num/2;			
				}
				else{
					num = 3*num+1;			
				}
				printf(", %d",num);
			}
		} 
		else 
		{ 
			/* parent process */ 
			/* parent will wait for the child to complete */ 
			wait(NULL);
			printf("\nChild Complete\n"); 
		} 
	return 0;
}

bool isInteger(float val)
{
    int intVal = (int)val;
    return (val == intVal);
}

