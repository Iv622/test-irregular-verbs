#ifndef FORMAT_H
#define FORMAT_H

#define FIFE_VERBS "English"
#define MAX_VERBS 101

typedef struct{
 	char one_form[MAX_VERBS];
	char two_form[MAX_VERBS];
	char fre_form[MAX_VERBS];
	char translite[MAX_VERBS];
} MasVerbs;

MasVerbs *read_file(const char *in_file_name);	//Чтение файла

#endif