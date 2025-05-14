#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	int rc = fork();
	
	if (rc < 0) {
		fprintf(stderr, "fork failed\n");
		return 1;
	} else if (rc == 0) {
		printf("child (pid: %d): finished work\n", getpid());
	} else { 
		int status;
		int rc_wait = wait(&status);
		printf("parent (pid: %d): child %d exited, status = %d\n", getpid(), rc_wait, status);
	}
	return 0;
}
