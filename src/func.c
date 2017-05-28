#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <inttypes.h>
#include "func.h"

char *Words[MAX_VERBS];	//Массив содержаший слова
int Mas[QUAN_VERBS];

int read_file(const char *in_file_name)\
{
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

int test_verbs(int formverbs)//Фукция тестирования
{ 
	getrand(100); //Создать рандомный массив
	if((formverbs == 1) || (formverbs == 2) || (formverbs == 3))
	{
		//Сравнение слов и вывод результата
		int i=compar_verbs(formverbs);/////////////////////////////////////////переиминуй переменную по русски
		print_res(result_print(i),i);
	}
	else
	{
		printf("\n\tНеобходимо вводить цифру от 1 до 3!\n");
		//Очистить выделенную память
		for(int i = 0; i < MAX_VERBS; i++)
		{
			free(Words[i]);
		}
		free(*Words);
		return -1;
	}

	//Очистить выделенную память
	for(int i = 0; i < MAX_VERBS; i++)
	{
		free(Words[i]);
	}
	free(*Words);
	return 0;
}

int getrand(int r) //Рандом
	{
	srand(time(NULL));
	int i, j;
	for(i = 0; i<QUAN_VERBS; i++){
	Mas[i] = rand() % r ;
	for(j = 0; j < i; j++)
	if(Mas[i] == Mas[j])
	i--;
	}
return 0;
}

/*int result_print(int trueanswer){	//Вывод результата
  if ((trueanswer>=0)&&(trueanswer<=20)){	
         printf("\n\tВы верно ответили %d раз(а)\n\t", trueanswer);
         
 	if((trueanswer>=18)&&(trueanswer<=20)){
		printf("%sОтлично%s\n\n", clBoldGreen, clNormal);
		return 5;
 	}else if(trueanswer>=15){
		printf("%sХорошо%s\n\n", clBoldGreen, clNormal);
		return 4;
 	}else if(trueanswer>=10){
		printf("%sУдовлетворительно%s\n\n", clBoldGreen, clNormal);
		return 3;
	}else if((trueanswer>=0)&&(trueanswer<=9)){
		printf("%sНе удовлетворительно%s\n\n", clBoldRed, clNormal);
		return 2;
	}
    
  }else printf("Неверный диапазон.\n"); 
	return 0;
}
*/

int result_print(int trueanswer)
{
	int res;
	if ((trueanswer>=0)&&(trueanswer<=20))
	{	
        
 		if((trueanswer>=18)&&(trueanswer<=20))
 		{
			res=5;
			return res;
 		}
 		else if(trueanswer>=15)
 		{
			res=4;
			return res;
 		}
		else if(trueanswer>=10)
		{
			res=3;
			return res;
		}
		else if((trueanswer>=0)&&(trueanswer<=9))
		{
			res=2;
			return res;
		}
	}
	return 0;
} 

void print_res(int res, int trueanswer)
{
	if ((trueanswer>=0)&&(trueanswer<=20))
	{
		printf("\n\tВы верно ответили %d раз(а)\n\t", trueanswer);

	if(res == 5)
	{
		printf("%sОтлично%s\n\n", clBoldGreen, clNormal);

	}
	else if(res == 4)
	{
	printf("%sХорошо%s\n\n", clBoldGreen, clNormal); 		
	}
	else if(res == 3)
	{
	printf("%sУдовлетворительно%s\n\n", clBoldGreen, clNormal);	
	}
	else if(res == 2)
	{
	printf("%sНе удовлетворительно%s\n\n", clBoldRed, clNormal);	
	}

//}else printf("Неверный диапазон.\n"); 
}
}
int compar_verbs(int formverbs)//Сравнение строк
{
	int i =0;
	char character;
	int trueanswer = 0, verbprint = 1, j = 0;
	char word[100]; 
	if(formverbs == 1) verbprint = 3;
	printf("\n\tВведите глагол %d-й формы, если глаголы представленны в %d-й форме:\n", formverbs, verbprint);	
	for( ;j<QUAN_VERBS; j++)
	{	
		printf("\n\t%d) %s: ", j+1, Words[4*Mas[j]+verbprint-1]);
		scanf("%s", word);
		while (word[i]) // пока не конец строки
	{
		character = word[i];
	word[i] = (char)tolower(character); // преобразовать текущий символ строки в строчный
	i++; // инкремент индекса символов в строке
		}
			i=0;
		if(strcmp(word, Words[4*Mas[j]+formverbs-1]) == 0)
		{
			printf("\n\t%sверно%s\n", clBoldGreen, clNormal);
			trueanswer++;
		}
		else printf("\n\t%sне верно%s (%s)\n", clBoldRed, clNormal, Words[4*Mas[j]+formverbs-1]);
	}
	return trueanswer;

}
