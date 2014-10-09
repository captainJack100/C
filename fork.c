#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(void) {

	pid_t pid;
	int i = 0;
	int n = 10;
	int status;

	printf("Parent PID: %d\n", getpid());
	
	for (i = 0; i < n; i++){
		fflush(stdout);
		if ((pid = fork()) < 0) {
			perror("forking error");
			abort();
		} else if (pid == 0) {
			// child stuff
			printf("Child %d: %d\n", i, getpid());
			exit(0);
		} else {

			printf("PARENT: %d \n", getpid());
		}
	}

	while (n > 0) {
		pid = wait(&status);
		printf("Child with PID %ld exit %d\n", (long)pid, status);
		--n;
	}

	return 0;
}
