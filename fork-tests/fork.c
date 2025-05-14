#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int x = 100;
	int rc = fork();
	if (rc < 0) {
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) {
		printf("child (pid: %d): x = %d\n", (int) getpid(), x);
	} else {
		x = 120;
		printf("parent (pid: %d): x = %d\n", (int) getpid(), x);
	}
	return 0;
}
