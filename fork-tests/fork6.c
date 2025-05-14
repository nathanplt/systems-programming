#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int rc = fork();

	if (rc < 0) {
		fprintf(stderr, "fork failed\n");
		return 1;
	} else if (rc == 0) {
		printf("child (pid: %d): finished work\n", getpid());
	} else {
		int status;
		int rc_wait = waitpid(rc, &status, 0);
		printf("parent (pid: %d): waited for child %d with status %d\n", getpid(), rc_wait, status);
	}
	return 0;
}
