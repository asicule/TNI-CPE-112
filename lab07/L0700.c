#include <stdio.h>

int x[7] = {1, 4, 7, 11, 16};
float y[] = {13.2, 1.4, 3.8, 2.75};
char z[25] = {'E', 'r', 'i', 'c', 's', 'o', 'n'};

int
main(void)
{
	printf("%d %.2f %c\n", x[2], y[0], z[3]);

	return 0;
}
