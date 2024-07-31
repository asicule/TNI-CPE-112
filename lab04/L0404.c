#include <stdio.h>

int x;

int
main(void)
{
	printf("Enter number x: "); scanf("%d", &x);
	if (x < 0) printf("Minus Number\n");
	else if (x == 0) printf("It's \"Zero\"\n");
	else {
		if (x < 100) printf("\"Nominal Range\"\n");
		else if (x < 1000) printf("\"Large Number\"\n");
		else printf("\"Very Large Number\"\n");
	}

	return 0;
}
