#include <stdio.h>

int
main(void)
{
	int i;
	fputs("List of odd number :: ", stdout);
	for (i = 1; i <= 100; i += 2) {
		printf("%d ", i);
	}
	putchar('\n');
	putchar('\n');
	fputs("List of even number :: ", stdout);
	for (i = 2; i <= 100; i += 2) {
		printf("%d ", i);
	}
	putchar('\n');
}
