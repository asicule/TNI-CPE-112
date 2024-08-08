#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
	double y, x1, x2;

	fputs("Enter the number for y: ", stdout);
	scanf("%lf", &y);

	x1 = sqrt(pow(y, 2) + 45);
	x2 = pow(y, 2) + 3 * y + 1;

	puts("\nResults");
	printf("x from eq.1 = %.2f\n", x1);
	printf("x from eq.2 = %.2f\n", x2);

	return 0;
}
