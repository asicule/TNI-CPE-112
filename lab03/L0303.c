#include <stdio.h>

int n, x, y, z;

int
main(void)
{
	printf("Enter n: "); scanf("%d", &n);
	printf("\n");

	x = 3 + 4 * n / 2 - 18;
	/*
	 * 1. 4 * n
	 * 2. (4 * n) / 2
	 * 3. (4 * n) / 2 + 3
	 * 4. (4 * n) / 2 + 3 - 18
	 */

	y = (3 + 4) * n / (18 * 2);
	/*
	 * 1. (3 + 4)
	 * 2. (3 + 4) * n
	 * 3. (3 + 4) * n / (18 * 2)
	 */

	z = 15 / 2 + 3 - (14 * n);
	/*
	 * 1. 15 / 2
	 * 2. 15 / 2 + 3
	 * 3. 15 / 2 + 3 - (14 * n)
	 */
	
	printf("Result x = %d\n", x);
	printf("Result y = %d\n", y);
	printf("Result z = %d\n", z);

	return 0;
}
