#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>
#include<string.h>

#include "../binary_printer.h"

int main() {

	printf("%i:\n", 120);
	binary_printf("%c", 120);
	printf("\n\n");

	printf("%i - %i:\n", 1037, 130);
	binary_printf("%i%c%D%g", 1037, 130, 
		'\n', 4);
	printf("\n\n");

	printf("%i:\n", 25097);
	binary_printf("%p%g%d%s", 4, '.',
		25097);
	printf("\n\n");

	printf("ip %i.%i.%i.%i:\n", 192, 168, 0, 120);
	binary_printf("%D%g%d%c%c%c%c", '.', 4, ' ', 
		192, 168, 0, 120);
	printf("\n");

	return 0;
}
