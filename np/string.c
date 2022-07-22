#include <np/string.h>

char *
np_strdup(const char *str) {
    if (!str) {
        return NULL;
    }
    
    size_t len = strlen(str);
    size_t size = len + 1;

    char *p = malloc(size);
    if (!p) {
        return NULL;
    }

    strcpy(p, str);
    p[len] = '\0';

    return p;
}
