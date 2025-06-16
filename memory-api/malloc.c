#include <stdlib.h>

int main(int argc, char *argv[]) {
    int *ptr_leak = (int *) malloc(sizeof(int));
    return 0;
}
