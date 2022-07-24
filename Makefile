CC := gcc
CC_FLAGS := -std=c17 -Wall -O0 -g -I .
TEST_PROG := test.out
LIB_PROG := libnp.so
OBJS := build/np/file.o \
	build/np/os.o \
	build/np/memory.o \
	build/np/string.o

all: test lib

.PHONY: init
init:
	rm -rf build && mkdir build && mkdir build/np

test: $(OBJS) build/test.o
	$(CC) $(CC_FLAGS) $(OBJS) build/test.o -o build/$(TEST_PROG)

lib: $(OBJS)
	$(CC) $(CC_FLAGS) -shared $(OBJS) -o build/$(LIB_PROG)

build/test.o: test.c test.h
	$(CC) $(CC_FLAGS) -c $< -o $@
	
build/np/file.o: np/file.c np/file.h
	$(CC) $(CC_FLAGS) -c $< -o $@
build/np/os.o: np/os.c np/os.h
	$(CC) $(CC_FLAGS) -c $< -o $@
build/np/memory.o: np/memory.c np/memory.h
	$(CC) $(CC_FLAGS) -c $< -o $@
build/np/string.o: np/string.c np/string.h
	$(CC) $(CC_FLAGS) -c $< -o $@
