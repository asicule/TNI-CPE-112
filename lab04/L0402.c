#include <stdio.h>

int x;

int
main(void)
{
	printf("Enter number x: ");
	scanf("%d", &x);
	if (x < 0)
		printf("Minus Number\n");
	else
		printf("Just Number\n");

	return 0;
}
