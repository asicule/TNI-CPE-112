#include <stdio.h>

int x;

int
main()
{
	printf("Enter number x: "); scanf("%d", &x);
	if (x < 0) printf("Minus Number\n");
	else if (x == 0) printf("It's \"Zero\"\n");
	else printf("Plus Number\n");

	return 0;
}
