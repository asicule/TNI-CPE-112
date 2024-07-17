#include <stdio.h>

long int num;

int
main()
{
	printf("Enter number: ");
	scanf("%ld", &num);
	int i = 1;
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
