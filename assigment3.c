#include <stdio.h>

	
struct WithoutPragma {
	char a; //1
        int b; //4
        double c; //8
};

#pragma pack(push,1)
struct WithPragma1 {
	char a;
    	int b;
    	double c;
};

#pragma pack(pop)

#pragma pack(push,2)
struct WithPragma2 {
        char a;
        int b;
        double c;
};

#pragma pack(pop)

#pragma pack(push,4)
struct WithPragma4 {
        char a;
        int b;
        double c;
};

#pragma pack(pop)

int main() {
	struct WithoutPragma without;
	struct WithPragma1 with1;
	struct WithPragma2 with2;
	struct WithPragma4 with4;



        printf("Size of struct without pragma: %zu bytes\n", sizeof(without));
	printf("Address of without.a: %p\n", (void *)&without.a);
        printf("Address of without.b: %p\n", (void *)&without.b);
        printf("Address of orig.c: %p\n", (void *)&without.c);

	printf("Size of struct with pragma1: %zu bytes\n", sizeof(with1));
        printf("Address of pragma1.a: %p\n", (void *)&with1.a);
        printf("Address of pragma1.b: %p\n", (void *)&with1.b);
        printf("Address of pragma1.c: %p\n", (void *)&with1.c);

	printf("Size of struct with pragma2: %zu bytes\n", sizeof(with2));
        printf("Address of pragma2.a: %p\n", (void *)&with2.a);
        printf("Address of pragma2.b: %p\n", (void *)&with2.b);
        printf("Address of pragma2.c: %p\n", (void *)&with2.c);


        printf("Size of struct with pragma4: %zu bytes\n", sizeof(with4));
        printf("Address of pragma4.a: %p\n", (void *)&with4.a);
        printf("Address of pragma4.b: %p\n", (void *)&with4.b);
        printf("Address of pragma4.c: %p\n", (void *)&with4.c);


        return 0;
}
//pack(1) reduces the size of the sum by eleminating the padding. So it will just sum all memory sizes of members. 1+4+8=13
//pack2(2 reduces the size of int b by 2 byte. Without padding it. So the size will be 14. 1+4+x+8=14. x is equal to 1 because 2 elements are unpacked.
//pack(4) will try to align int b to 4 bytes, which will result padding 3 of bytes. So the size will be 16.  1+4+3+8 = 16. 3 is the padding. Most unefficient alignment in this situation,
//as the memory is used as much as possible, and cpu cycles will not be efficient.
