#ifndef FORMAT_H
#define FORMAT_H

#define FIFE_VERBS "English"
#define MAX_VERBS 400	//Количество слов в словаре
#define QUAN_VERBS 20	//Количество вопросов

#define clBoldGreen "\033[01;32;05;10m" //RGB
#define clBoldRed "\033[01;31;05;10m" //RGB
#define clNormal "\033[m"

int read_file(const char *in_file_name);	//Чтение файла

int test_verbs(int formverbs);

int getrand(int r);

#endif