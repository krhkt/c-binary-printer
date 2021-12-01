*[last update: 2014-11-10]*

# C Binary Printer

This is a simple binary printf function.

It can separate the bits in groups and can take several numbers
to print.

### Format Codes
- `%c` = print 1 byte
- `%s` = print 2 bytes
- `%i` = print 4 bytes
- `%d` = delimiter in group (must be a char, defaults to `' '`)
- `%g` = number of bits in one group (must be a number)
- `%D` = delimiter for each binary string (must be a char).
	> If `%D` is not present, `%d` will be used as delimiter for a 	binary string. To avoid this, `%p` should the first letter for the string
- `%p` = ignore binary string delimiter

#### Return Codes
- 1 if any memory error
- 0 if success

### Examples
```c
	binary_printf("%c", 120);
	//output: 01111000

	binary_printf("%p%g%d%s", 4, '.', 25097);
	//output: 0110.0010.0000.1001
```