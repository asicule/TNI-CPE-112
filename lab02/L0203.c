#include <stdio.h>

long int num;

int
main(void)
{
	int i = 1;
	printf("Enter number: ");
	scanf("%ld", &num);
	printf("%ld x %d = %ld\n", num, i, num * i);
	i++;
	printf("%ld x %d = %ld\n", num, i, num * i);
	i++;
	printf("%ld x %d = %ld\n", num, i, num * i);
	i++;
	printf("%ld x %d = %ld\n", num, i, num * i);
	i++;
	printf("%ld x %d = %ld\n", num, i, num * i);
	i++;
	printf("%ld x %d = %ld\n", num, i, num * i);
	return 0;
}
