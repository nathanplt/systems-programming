#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int pipefd[2];
	if (pipe(pipefd) == -1) {
		fprintf(stderr, "pipe failed\n");
		return 1;
    }

	int rc1 = fork();
	if (rc1 < 0) {
		fprintf(stderr, "fork 1 failed\n");
		return 1;
	}

	if (rc1 == 0) {
		// Close read end
		close(pipefd[0]);

		// Redirect stdout to the write end of pipe
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);

		// Now, execute ls
		execlp("ls", "ls", NULL);

		fprintf(stderr, "execlp failed\n");
		return 1;
	}

	int rc2 = fork();
	if (rc2 < 0) {
		fprintf(stderr, "fork 2 failed\n");
		return 1;
	}

	if (rc2 == 0) {
		// Close write end
		close(pipefd[1]);

		// Redirect stdin to the read end of pipe
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);

		// Execute wc
		execlp("wc", "wc", NULL);

		fprintf(stderr, "execlp failed\n");
		return 1;
	}

	close(pipefd[0]);
	close(pipefd[1]);

	waitpid(rc1, NULL, 0);
	waitpid(rc2, NULL, 0);

	return 0;
}
