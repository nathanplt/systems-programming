#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
	int pipe1[2], pipe2[2];
	if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
		fprintf(stderr, "pipe failed\n");
		return 1;
	}

	int n = 100000;
	struct timeval start, end;

	int rc = fork();
	if (rc < 0) {
		fprintf(stderr, "fork failed\n");
		return 1;
	} else if (rc == 0) {
		for (int i=0; i<n; i++) {
			char buf;
			read(pipe1[0], &buf, 1);
			write(pipe2[1], "x", 1);
		}
	} else {
		gettimeofday(&start, NULL);
		for (int i=0; i<n; i++) {
			write(pipe1[1], "x", 1);
			char buf;
			read(pipe2[0], &buf, 1);
		}

		gettimeofday(&end, NULL);
		wait(NULL);

		double diff = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);
		printf("avg time per ctxt swtch = %.5f\n", diff / (2 * n));
	}
	return 0;	
}
