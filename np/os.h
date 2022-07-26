#pragma once

#include <np/include.h>
#include <np/memory.h>
#include <np/string.h>

char **
np_listdir(const char *dirpath);

bool
np_is_exists(const char *path);
