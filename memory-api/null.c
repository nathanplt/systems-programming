#include <stdlib.h>

int main(int argc, char *argv[]) {
    int *bad_ptr = NULL;
    int x = *bad_ptr;
    return 0;
}
