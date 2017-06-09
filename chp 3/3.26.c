#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 255
#define READ_END 0
#define WRITE_END 1

int main(void){
	char write_msg[BUFFER_SIZE];
	char read_msg[BUFFER_SIZE];
	int fd[2];
	pid_t pid;
	/* create the pipe */
	if (pipe(fd) == -1) {
		fprintf(stderr,"Pipe Failed");
		return 1;
	}
	/* fork a child process */
	pid = fork();
	if(pid < 0) {
		fprintf(stderr,"Fork Failed");
		return 1;
	}
	if(pid > 0){ /* parent process */
		/* close the unused end of the pipe */
		close(fd[READ_END]);
		/* write to the pipe */
		printf("message : ");
		gets(write_msg);
		write(fd[WRITE_END], write_msg, strlen(write_msg)+1);
		/* close the write end of the pipe */
		close(fd[WRITE_END]);
	}
	else{ /* child process */
		/* close the unused end of the pipe */
		close(fd[WRITE_END]);
		/* read from the pipe */
		read(fd[READ_END], read_msg, BUFFER_SIZE);
		int i;
		for(i=0;i < strlen(read_msg)+1;++i){
			if(islower(read_msg[i])){
				read_msg[i] = toupper(read_msg[i]);
			}
			else{
				read_msg[i] = tolower(read_msg[i]);
			}
		}
		printf("%s\n",read_msg);
		/* close the read end of the pipe */	
		close(fd[READ_END]);
	}
	return 0;
}