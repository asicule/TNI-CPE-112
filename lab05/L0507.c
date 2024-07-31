#include <stdio.h>

int
main(void)
{
	unsigned long sum_fact, result;
	unsigned short factorial, line, i, j;
	fputs("Enter the highest number for factorial: ", stdout);
	scanf("%hd", &factorial);

	for (line = 1; line <= factorial; line++) {
		printf("%hd! = ", line);
		sum_fact = 1;
		for (i = line; i > 1; i--) {
			printf("%hd ", i);
			fputs("* ", stdout);
			sum_fact *= i;
		}
		printf("%hd ", i);
		sum_fact *= i;
		printf("= %ld\n", sum_fact);
	}
	putchar('\n');

	fputs("Summation of factorial results\n", stdout);
	result = 0;
	for (i = 1; i < factorial; i++) {
		sum_fact = 1;
		for (j = i; j > 0; j--) sum_fact *= j;
		printf("%ld ", sum_fact);
		fputs("+ ", stdout);
		result += sum_fact;
	}
	sum_fact = 1;
	for (j = factorial; j > 0; j--) sum_fact *= j;
	printf("%ld ", sum_fact);
	result += sum_fact;
	printf("= %ld\n", result);

	return 0;
}
