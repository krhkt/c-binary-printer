#ifndef _BINARY_PRINTER
#define _BINARY_PRINTER 1

//:::::::::::::::::::::::FUNCTIONS::::::::::::::::::::::::::::::::::
//this function is a simple binary_printer formated
//it can separate the bits in groups and can take several numbers
//to print
//formatation code: %+
//c = char to print (one byte)
//s = short to print (two bytes)
//i = int to print (four bytes)
//d = delimiter in group (must be a char)
//g = number of bits in one group (must be a number)
//D = delimiter for each binary string (must be a char)
// if D is not present, d will be used as delimiter for a binary string
// to avoid this, p should be passed as first letter for the string
//
//return:	1 if any memory error
//			0 if success
int binary_printf (char*, ...);

#endif
