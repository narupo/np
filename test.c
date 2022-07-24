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
            !strcmp(*p, "file3.txt") ||
            !strcmp(*p, "file4.txt") ||
            !strcmp(*p, "file5.txt") ||
            !strcmp(*p, "file6.txt") ||
            !strcmp(*p, "file7.txt") ||
            !strcmp(*p, "file8.txt") ||
            !strcmp(*p, "file9.txt") ||
            !strcmp(*p, "file10.txt") ||
            !strcmp(*p, "file11.txt") ||
            !strcmp(*p, "file12.txt") ||
            !strcmp(*p, "file13.txt") ||
            !strcmp(*p, "file14.txt")) {
            n++;
        }
    }
    assert(n == 14);

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
    puts("OK");
    return 0;
}
