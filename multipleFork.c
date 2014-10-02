
/*
	multiple child forking.
	1 parent multiple children.

*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void) {

	pid_t pid;
	int i = 0;
	int n = 10;
	int status;

	printf("Parent PID: %d\n", getpid());
	
	for(i = 0; i < n; i++) {
		fflush(stdout);
		if ((pid = fork()) < 0) {
			perror("Forking Error");
			abort();
		} else if (pid == 0) {
			// child stuff
			printf("Child %d: %d\n", i, getpid());
			exit(0);
		} else {
			// don't need this. It's the parent.
			// print same as getpid above.
				// printf("%d\n", getpid());
			// put wait here to put it in order.
				// wait(0)
			// execution returns back to parent and conts.
		}	
	}

	while (n > 0){
		pid = wait(&status);
		printf("Child with PID %ld exit %d\n", (long)pid, status);
		--n;
	}

	return 0;
}
