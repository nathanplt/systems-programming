#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int rc = fork();
	if (rc < 0) {
		fprintf(stderr, "fork failed\n");
		return 1;
	} else if (rc == 0) {
		execl("/bin/ls", "ls", NULL);

		fprintf(stderr, "execvp failed\n");
		
	} else {
		printf("parent reached\n");
	}
	return 0;
}
