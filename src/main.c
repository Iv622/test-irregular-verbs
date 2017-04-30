#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "func.h"

int main(int argc, char *argv[]){
	printf("\tДобро пожаловать!\n\tТестирование неправельных глаголов английского языка\n\tВерсия: 1.0\n\tРазработчики: Бубнов, Лейка, Вараксина\n");
	printf("\n\tПо какой форме глаголов вы бы хотели протестироватся?\n\t");
	read_file(FIFE_VERBS); 
	return 0;
}