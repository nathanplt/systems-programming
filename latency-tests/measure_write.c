#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
#include "sys/time.h"

int main(int argc, char *argv[]) {
	struct timeval tvi;
	gettimeofday(&tvi, NULL);

	int n = 1000;
	for (int i=0; i<n; i++) {
		read(STDIN_FILENO, NULL, 0);
	}

	struct timeval tvf;
	gettimeofday(&tvf, NULL);


	double diff = (tvf.tv_sec - tvi.tv_sec) * 1e6 + (tvf.tv_usec - tvi.tv_usec);
	printf("time per write: %.5f\n", diff / n);
	return 0;
}
