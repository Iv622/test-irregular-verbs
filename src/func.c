#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include "func.h"

int read_file(const char *in_file_name){
	FILE *in_file;
	uint32_t CountWord = 0, CountSpace = 0;
	register int inWord = 0;
	int c;
	int WLen = 0;
	char *Words[MAX_VERBS];	//Массив содержаший слова
	char word[100]= {' '}; 
	if((in_file = fopen(in_file_name, "r")) == NULL)
		return -1;
		//printf("\tОшибка чтения файла\n");
	//printf("\tЧтение файла %s\n", in_file_name);

	 while((c = getc(in_file)) != EOF)
	 {
		if((c == '\t') || (c == '\n'))
		{
			inWord = 0;
			++CountSpace;
			if (WLen)
			{
				word[WLen] = '\0';
				Words[CountWord - 1] = malloc((WLen + 1) * sizeof(char));
				strcpy(Words[CountWord - 1], word);
				//printf("%s\n", Words[CountWord - 1]);
			}
			WLen = 0;
		}
		else
		{
			word[WLen] = c;
			++WLen;
			if(inWord == 0)
			{
				inWord = 1;
				++CountWord;
			}
		}
	}

	//test_verbs(*Words);
	printf("\tДобро пожаловать!\n\tТестирование неправельных глаголов английского языка\n\tВерсия: 1.0\n\tРазработчики: Бубнов, Лейка, Вараксина\n");
	printf("\n\tПо какой форме глаголов вы бы хотели протестироватся?\n\t");
	
	int form;
	scanf("%d", &form);
		if(form == 1){
			printf("\n\t1\n");
		}else
		if(form == 2){
			printf("\n\t2\n");
		}else
		if(form == 3){
			printf("\n\t3\n");
		}else{
			printf("\n\tНеобходимо вводить цифру от 1 до 3!\n");
			return 1;
		}

	for(int i = 0; i < MAX_VERBS; i++){
		//printf("%s\n", Words[i]);
		free(Words[i]);
	}
	free(*Words);
   	fclose(in_file);
	return 0;
}

// void test_verbs(char Words[MAX_VERBS]){

	
// }