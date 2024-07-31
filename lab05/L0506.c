#include <stdio.h>

int
main(void)
{
	unsigned int factorial;
	unsigned long i, sum = 1;
	fputs("Enter the number for factorial: ", stdout);
	scanf("%d", &factorial);
	i = factorial;
	while (i > 0) {
		sum *= i;
		printf("%ld ", i--);
		if (i) fputs("* ", stdout);
		else break;
	}

	printf("= %ld\n", sum);
	return 0;
}
