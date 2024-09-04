#include <stdio.h>

int melon = 21;
int banana = 14;

int *p1 = &melon;

int
main(void)
{
	int *p2 = p1;

	puts("step 1");
	printf("pointer1 has %d in its stored address\n", *p1);
	printf("pointer2 has %d in its stored address\n", *p2);

	putchar('\n');
	puts("step 2");
	melon = 77;
	printf("pointer1 has %d in its stored address\n", *p1);
	printf("pointer2 has %d in its stored address\n", *p2);

	putchar('\n');
	puts("step 3");
	p2 = &banana;
	printf("pointer1 has %d in its stored address\n", *p1);
	printf("pointer2 has %d in its stored address\n", *p2);

	putchar('\n');
	puts("step 4");
	*p2 = 21;
	printf("pointer1 has %d in its stored address\n", *p1);
	printf("pointer2 has %d in its stored address\n", *p2);

	return 0;
}
