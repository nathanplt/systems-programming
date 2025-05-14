#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int fd = open("output.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (fd < 0) {
		fprintf(stderr, "file open failed\n");
		return 1;
	}

	int rc = fork();
	if (rc < 0) {
		fprintf(stderr, "fork failed\n");
		return 1;
	} else if (rc == 0) {
		for (int i=0; i<5; i++) {
			const char *msg = "child writing\n";
			write(fd, msg, strlen(msg));
		}
	} else {
		for (int i=0; i<5; i++) {
			const char *msg = "parent writing\n";
			write(fd, msg, strlen(msg));
		}	
	}
	close(fd);
	return 0;
}
