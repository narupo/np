#include <test.h>

/*****
* os *
*****/

void
test_os_listdir(void) {
    char **files = np_listdir("sample/listdir");
    assert(files);

    int n = 0;
    for (char **p = files; *p; p++) {
        if (!strcmp(*p, "file1.txt") ||
            !strcmp(*p, "file2.txt") ||
            !strcmp(*p, "file3.txt")) {
            n++;
        }
    }
    assert(n == 3);

    np_free_array(files);
}

void
test_os(void) {
    test_os_listdir();
}

/*********
* string *
*********/

void
test_string_strdup(void) {
    assert(np_strdup(NULL) == NULL);

    char *p = np_strdup("test");
    assert(p);
    assert(!strcmp(p, "test"));
    free(p);
}

void
test_string(void) {
    test_string_strdup();
}

int
main(void) {
    test_string();
    test_os();
    return 0;
}
