/* 1) build and examine this code !@@@! Done !@@@!
   2) correct the mistake: it is possible to hang on wait. Why and when? (see "man fork") !@@@! Done !@@@!
 */

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main() {
	pid_t pid;
   	int status, died;
	switch(pid = fork()) {
   		case 0: 
			execl("/bin/ls","ls","-l",NULL); // this is the code the child runs 
   		case -1:
			printf("Error: new process wasn't created.");//If OS can't create new process (for ex. there are no possible PID's in it) the parent process will be waited the signal from the child process up to the end of OS working (or, maybe, up to SIGKILL or so on).
		default: 
			wait(&status); // this is the code the parent runs
   	}
	return 0;
}
