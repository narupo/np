#include <np/os.h>

static char **
resize_array(char **ary, int32_t index, int32_t *capa, int32_t byte) {
    if (index < *capa) {
        return ary;
    }

    int32_t oldcapa = *capa;
    *capa *= 2;
    int32_t newsize = *capa * byte + byte;
    char **tmp = realloc(ary, newsize);
    if (!tmp) {
        np_free_array(ary);
        return NULL;
    }
    for (int32_t i = oldcapa; i < *capa + 1; i++) {
        tmp[i] = NULL;
    }
    return tmp;
}

char **
np_listdir(const char *dirpath) {
    int32_t capa = 4;
    int32_t byte = sizeof(char *);
    int32_t index = 0;
    char **ary = calloc(capa + 1, byte);
    if (!ary) {
        return NULL;
    }

#ifdef NP_WIN
    // TODO
    return NULL;
#else
    DIR *dir = opendir(dirpath);
    if (!dir) {
        free(ary);
        return NULL;
    }

    struct dirent *ent;
    for (; (ent = readdir(dir)); ) {
        ary = resize_array(ary, index, &capa, byte);
        char *name = np_strdup(ent->d_name);
        if (!name) {
            np_free_array(ary);
            return NULL;
        }
        ary[index++] = name;
    }

    closedir(dir);
#endif
    return ary;
}

bool
np_is_exists(const char *path) {
    struct stat buf;
    return stat(path, &buf) == 0;
}
