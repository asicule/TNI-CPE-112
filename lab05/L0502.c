#include <stdio.h>

int num;

int
main(void)
{
	do {
		fputs("Enter number: ", stdout);
		scanf("%d", &num);
	} while (num > 0);

	putchar('\n');
	puts("Data receiving ended");
	return 0;
}
