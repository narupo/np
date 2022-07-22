#include <np/memory.h>

void
np_free_array(char **array) {
    for (char **p = array; *p; p++) {
        free(*p);
    }
    free(array);
}
