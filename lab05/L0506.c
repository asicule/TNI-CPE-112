#include <stdio.h>

int
main(void)
{
	unsigned int factorial;
	unsigned long i, sum = 1;
	fputs("Enter the number for factorial: ", stdout);
	scanf("%d", &factorial);
	i = factorial;
addsum:
	sum *= i;
	printf("%ld ", i--);
	if (i) {
		fputs("* ", stdout);
		goto addsum;
	}

	printf("= %ld\n", sum);
	return 0;
}
