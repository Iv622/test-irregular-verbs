#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include "func.h"

MasVerbs *read_file(const char *in_file_name){
	FILE *in_file;
	if((in_file = fopen(in_file_name, "r")) == NULL)
	{
		printf("\tОшибка чтения файла %s\n", in_file_name);
		exit(1);
	}
	printf("\tЧтение файла %s\n", in_file_name);
	
	return 0;
}