#include <stdio.h>

	
	struct Initial {
		char a; //1
		int b; //4
		double c; //8
	};

	struct Reorder {
		int b; //4
		double c; //8
		char a; //1
	};

	int main() {

		struct Initial init;
		struct Reorder reInit;

    		printf("Size of Original struct: %zu bytes\n", sizeof(init));
    		printf("Size of Reordered struct: %zu bytes\n", sizeof(reInit));

    		printf("Address of orig.a: %p\n", (void *)&init.a);
    		printf("Address of orig.b: %p\n", (void *)&init.b);
    		printf("Address of orig.c: %p\n", (void *)&init.c);

    		printf("Address of reorder.c: %p\n", (void *)&reInit.c);
    		printf("Address of reorder.b: %p\n", (void *)&reInit.b);
    		printf("Address of reorder.a: %p\n", (void *)&reInit.a);

    		return 0;
	}

//after running uname -m command I am sure that this linux server runs on 64bit cpu. This means that our cpu can take 8bytes in every cycle.
//Our goal is to minimize cycles count, and take more data with less cycles. Memory usage is not in priority here. 
//So for initial struct we have char that uses 1 byte, int uses 4 bytes and double uses 8 bytes.
//As our cpu can take 8bytes at once, char and int can be taken in 1 cycle, double can be taken in second cycle.
//in initial struct size is 16 bytes, because 1+4<8 for char and int.
//in reordered struct size is 24, because 4+8 > 8, so compiler adds padding of 4 bytes to be aligned on 8 byte bound, double is ok with 64bit system word, and there is padding of 7 bytes for char.
