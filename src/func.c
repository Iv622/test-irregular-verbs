#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include <sys/time.h>
#include "func.h"

char *Words[MAX_VERBS];	//Массив содержаший слова
int Mas[QUAN_VERBS];

int read_file(const char *in_file_name){
	FILE *in_file;
	uint32_t CountWord = 0, CountSpace = 0;
	register int inWord = 0;
	int c;
	int WLen = 0;
	char word[100]= {' '}; 
	if((in_file = fopen(in_file_name, "r")) == NULL)
		return -1;
		//printf("Ошибка чтения файла");
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
	fclose(in_file);
	return 0;
}

int test_verbs(int formverbs){ //Фукция тестирования
	getrand(100); //Создать рандомный массив
	int i = 0, trueanswer = 0, verbprint = 1;
	char word[100]; 
	if((formverbs == 1) || (formverbs == 2) || (formverbs == 3)){
		if(formverbs == 1) verbprint = 3;
		printf("\n\tВведите глагол %d-й формы, если глаголы представленны в %d-й форме:\n", formverbs, verbprint);	
		for( ;i<QUAN_VERBS; i++){	
			printf("\n\t%d) %s: ", i+1, Words[4*Mas[i]+verbprint-1]);
			scanf("%s", word);
			if(strcmp(word, Words[4*Mas[i]+formverbs-1]) == 0){
				printf("\n\t%sверно%s\n", clBoldGreen, clNormal);
				trueanswer++;
			}else printf("\n\t%sне верно%s (%s)\n", clBoldRed, clNormal, Words[4*Mas[i]+formverbs-1]);
		}
		//Вывод результата
	 	printf("\n\tВы верно ответили %d раз(а)\n\t", trueanswer);
	 	if(trueanswer>=18){
			printf("%sОтлично%s\n\n", clBoldGreen, clNormal);
	 	}else if(trueanswer>=15){
			printf("%sХорошо%s\n\n", clBoldGreen, clNormal);
	 	}else if(trueanswer>=10){
			printf("%sУдовлетворительно%s\n\n", clBoldGreen, clNormal);
		}else printf("%sНе удовлетворительно%s\n\n", clBoldRed, clNormal);

	}else{
		printf("\n\tНеобходимо вводить цифру от 1 до 3!\n");
		return 1;
	}

	//Очистить выделенную память
	for(int i = 0; i < MAX_VERBS; i++){
		free(Words[i]);
	}
	free(*Words);

	return 0;
}

int getrand(int r) //Рандом
{
	srand(time(0));
	for(int i=0; i<QUAN_VERBS; i++){ 
		Mas[i] = rand() / (RAND_MAX + 1.0) * r;
		printf("%d ", Mas[i]);
	}
	return 0;
}