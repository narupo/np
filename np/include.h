#pragma once

#if defined(_WIN32) || defined(_WIN64)
# define NP_WIN 1
# warning hige
#endif

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdint.h>

#ifdef NP_WIN
# warning TODO
#else
# include <dirent.h>
#endif
