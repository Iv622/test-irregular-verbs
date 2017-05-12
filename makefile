CC=gcc
CFLAGS= -Wall -Werror -std=c99
OBJECTS=build/main.o build/func.o
DIR=build bin

#//////////////////////////////
.PHONY: all clean_b allprog alltest

all: makedir allprog 

clean_b:
	rm -rf build/*.o 

makedir:
	mkdir -p $(DIR)

#/////////////////////////////
allprog: makedir main func testverbs

testverbs:$(OBJECTS)
	$(CC) $(OBJECTS) -o bin/testverbs

main: src/main.c
	$(CC) -o build/main.o -c $(CFLAGS) src/main.c

func: src/func.c
	$(CC) -o build/func.o -c $(CFLAGS) src/func.c

