CC=gcc
CFLAGS= -Wall -Werror -std=c99
OBJECTS=build/src/main.o build/src/func.o
OBJECTSTEST=build/test/main_test.o build/test/func_test.o
DIR=build/src build/test bin

#//////////////////////////////
.PHONY: all allclean allprog alltest

all: makedir allprog alltest

allclean: clean_bsrc clean_btest

clean_btest:
	rm -rf build/test/*.o 

clean_bsrc:
	rm -rf build/src/*.o 

makedir:
	mkdir -p $(DIR)

#/////////////////////////////
allprog: makedir main func testverbs

testverbs:$(OBJECTS)
	$(CC) $(OBJECTS) -o bin/testverbs

main: src/main.c
	$(CC) -o build/src/main.o -c $(CFLAGS) src/main.c

func: src/func.c
	$(CC) -o build/src/func.o -c $(CFLAGS) src/func.c

#/////////////////////////////
alltest: makedir main_test func_test testing

main_test: test/main.c
	$(CC) $(CFLAGS) -c test/main.c -o build/test/main_test.o

func_test: test/func_test.c  
	$(CC) $(CFLAGS) -I src -c test/func_test.c -o build/test/func_test.o 

testing:$(OBJECTSTEST) src/func.c
	$(CC) $(CFLAGS) $(OBJECTSTEST) src/func.c -o bin/testprog