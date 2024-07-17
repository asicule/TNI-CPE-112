#include <stdio.h>

int x;

int
main()
{
	printf("Enter x: "); scanf("%d", &x);
	printf("\n");

	int i = 1;
	x -= 3/2;
	printf("x after eq%d = %d\n", i++, x);
	x *= 6;
	printf("x after eq%d = %d\n", i++, x);
	x += 12 * 3;
	printf("x after eq%d = %d\n", i++, x);
	x *= 140/3;
	printf("x after eq%d = %d\n", i++, x);

	return 0;
}


