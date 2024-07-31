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
		i = line;
		while (1) {
			printf("%hd ", i);
			sum_fact *= i;
			if (--i) {
				fputs("* ", stdout);
			} else break;
		}
		printf("= %ld\n", sum_fact);
	}
	putchar('\n');

	fputs("Summation of factorial results\n", stdout);
	result = 0;
	i = 1;
	while (1) {
		sum_fact = 1;
		for (j = i; j > 0; j--) sum_fact *= j;
		printf("%ld ", sum_fact);
		result += sum_fact;
		if (i++ < factorial) {
			fputs("+ ", stdout);
		} else break;
	}
	printf("= %ld\n", result);

	return 0;
}
