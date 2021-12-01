#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>
#include<string.h>

#include "binary_printer.h"

//:::::::::::::::::::::::STRUCTS::::::::::::::::::::::::::::::::::::
typedef struct list_bp{
	char value;
	struct list_bp* next;
} t_list_bp;

int binary_printf(char* format, ...) {
	char *tk, *tmp;
	int i, j, group_size, arg;
	va_list ap;
	unsigned char flag_delimiter, group_delimiter, word_delimiter;
	t_list_bp *l, *aux;

	unsigned int shifter = 0;
	unsigned char char_to_print = 0;
	unsigned short short_to_print = 0;
	unsigned int int_to_print = 0;

	//inicializing parameter list to be able to use the pushed parameters
	va_start(ap, format);
	flag_delimiter = 0;
	word_delimiter = 0;
	group_delimiter = ' ';
	group_size = 0;
	

	//copying format into tmp to tokenize
	tmp = (char*)malloc(sizeof(char) * (strlen(format) + 1));
	//error malloc
	if (tmp == NULL) {
		return 1;
	}
	strcpy(tmp, format);

	//starts the tokenize spliting by spaces
	tk = strtok(tmp, "%");
	i = 0;
	do {
		if (!i) {
			if ((*tk) == 'p') {
				flag_delimiter = 1;
				continue;
			}
			l = (t_list_bp*)malloc(sizeof(t_list_bp));
			//error malloc
			if (l == NULL) {
				free(tmp);
				return 1;
			}
			l->value = (*tk);
			l->next = NULL;
			aux = l;
		} else {
			aux->next = (t_list_bp*)malloc(sizeof(t_list_bp));
			//error malloc
			if (aux->next == NULL) {
				free(tmp);
				aux = l;
				while(aux) {
					aux = aux->next;
					free(l);
					l = aux;
				}
				return 1;
			}
			aux = aux->next;
			aux->value = (*tk);
			aux->next = NULL;
		}
		
		arg = va_arg(ap, int);
		
		switch ((*tk)) {
			case 'D':
				word_delimiter = (char)arg;
				break;
			case 'g':
				group_size = (int)arg;
				break;
			case 'd':
				group_delimiter = (char)arg;
		}
		
		i = 1;
	} while (tk = strtok((char*)0, "%"));
	
	if (!flag_delimiter) {
		if (!word_delimiter) {
			word_delimiter = group_delimiter;
		}
	}
	
	va_end(ap);
	va_start(ap, format);

	aux = l;
	while (aux) {
		j = 0;
		arg = va_arg(ap, int);
			
		switch (aux->value) {
			case 'i':
				int_to_print = (unsigned int)arg;
				shifter = 1 << 31;
				
				for (i = 31; i > 15 ; i--, j++) {
			
					printf("%d",(int_to_print & shifter) >> i);
					shifter >>= 1;
				
					if (group_size && (((j+1) % group_size) == 0)) {
						printf("%c", group_delimiter);
					}
				}
			//intentional fall through
			case 's':
				short_to_print = (unsigned short)arg;
				
				shifter = 1 << 15;
				for (i = 15; i > 7 ; i--, j++) {
			
					printf("%d",(short_to_print & shifter) >> i);
					shifter >>= 1;
				
					if (group_size && (((j+1) % (group_size)) == 0)) {
						printf("%c", group_delimiter);
					}
				}
			//intentional fall through
			case 'c':
				char_to_print = (unsigned char)arg;
				shifter = 1 << 7;
				
				for (i = 7; i >= 0 ; i--, j++) {
			
					printf("%d",(char_to_print & shifter) >> i);
					shifter >>= 1;
				
					if (group_size && (((j+1) % group_size) == 0)) {
						if (i) printf("%c", group_delimiter);
					}
				}
			
				if (aux->next && word_delimiter) {
					printf("%c", word_delimiter);
				}
		}

		aux = aux->next;
		free(l);
		l = aux;
	}
	
	//final free
	free(tmp);
	va_end(ap);
	
	return 0;
}
