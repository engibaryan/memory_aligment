#include <stdio.h>
#include <stdlib.h>

int main() {

	int integer;
	char character;
	double doubleNumber;
	short shortNumber;

	printf("Size of int: %d bytes\n",(int) sizeof(integer));
   	printf("Size of char: %d byte\n",(int) sizeof(character));
    	printf("Size of double: %d bytes\n",(int) sizeof(doubleNumber));
    	printf("Size of short: %d bytes\n",(int) sizeof(shortNumber));

    	printf("Address of int: %p\n", (void *)&integer);
   	printf("Address of char: %p\n", (void *)&character);
    	printf("Address of double: %p\n", (void *)&doubleNumber);
    	printf("Address of short: %p\n", (void *)&shortNumber);


	return 0;
}

//Sizes we see after compilation are determined by the data type. Memory addresses for each variable are aligned based on their size; For example, int type are aligned to 4 byte space, for CPU to 
//need 1 cycle to access it. So aligment help to optimize memory access time for cpu. When looking at addresses you may notice that it is not increase by the size of the variable. 
//Reason for this is padding added by compiler to align data. This is simple but good example to understand how memory is managed in low level enviroment, and it may be beneficial for optimizing 
//programs performance.
