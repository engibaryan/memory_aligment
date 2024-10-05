#include <stdio.h>

	
struct WithoutPragma {
	char a; //1
        int b; //4
        double c; //8
};

#pragma pack(push,1)
struct WithPragma {
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

int main() {
	struct WithoutPragma without;
	struct WithPragma with1;
	struct WithPragma with2;
	struct WithPragma with4;



        printf("Size of struct without pragma: %zu bytes\n", sizeof(without));
	printf("Address of orig.a: %p\n", (void *)&without.a);
        printf("Address of orig.b: %p\n", (void *)&without.b);
        printf("Address of orig.c: %p\n", (void *)&without.c);

	printf("Size of struct with pragma1: %zu bytes\n", sizeof(with1));
        printf("Address of orig.a: %p\n", (void *)&with1.a);
        printf("Address of orig.b: %p\n", (void *)&with1.b);
        printf("Address of orig.c: %p\n", (void *)&with1.c);

	printf("Size of struct with pragma2: %zu bytes\n", sizeof(with2));
        printf("Address of orig.a: %p\n", (void *)&with2.a);
        printf("Address of orig.b: %p\n", (void *)&with2.b);
        printf("Address of orig.c: %p\n", (void *)&with2.c);


        printf("Size of struct with pragma4: %zu bytes\n", sizeof(with4));
        printf("Address of orig.a: %p\n", (void *)&with4.a);
        printf("Address of orig.b: %p\n", (void *)&with4.b);
        printf("Address of orig.c: %p\n", (void *)&with4.c);


        return 0;
}

