#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int rc = fork();

	if (rc < 0) {
		fprintf(stderr, "fork failed\n");
		return 1;
	} else if (rc == 0) {
		close(STDOUT_FILENO);
		printf("test\n");
	} else {
		int status;
		int rc_wait = wait(&status);
		printf("parent (pid: %d): waited for child %d", getpid(), rc_wait);
	}
	return 0;
}
