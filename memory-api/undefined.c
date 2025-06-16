#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int *data = (int *) malloc(sizeof(int) * 100);
    data[100] = 0;
    free(data);
    printf("Bad access: %d\n", data[0]);
    return 0;
}
