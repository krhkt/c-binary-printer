all: 	binary_printer_demo

binary_printer_demo: binary_printer.o
	gcc -o binary_printer_demo binary_printer.o binary_printer_demo.c -lm -Wall
	

binary_printer.o:
	gcc -c ../binary_printer.c

clean: 
	rm *.o binary_printer_demo
