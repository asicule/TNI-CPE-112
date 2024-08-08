#include <stdio.h>

int n, x, y, z;

int buf;

int
main(void)
{
	printf("Enter n: ");
	scanf("%d", &n);
	printf("\n");

	x = 3 + 4 * ++n / 2 - 18;
	/*
	 * 1. 4
	 * 2. n += 1
	 * 3. 4 * n
	 * 4. 4 * n / 2
	 * 5. 4 * n / 2 + 3
	 * 6. 4 * n / 2 + 3 - 18
	 * 7. store value in x
	 */

	y = (3 + 4) * n++ / (18 * 2);
	/*
	 * 1. 3
	 * 2. 3 + 4
	 * 3. (3 + 4) * n
	 * 4. (3 + 4) * n / (18 * 2)
	 * 5. store value in y
	 * 6. n += 1
	 */

	z = 15 / 2 + 3 - (14 * --n);
	/*
	 * 1. 15
	 * 2. 15 / 2
	 * 3. 15 / 2 + 3
	 * 4. n -= 1
	 * 5. 15 / 2 + 3 - (14 * n)
	 */

	printf("Result x = %d\n", x);
	printf("Result y = %d\n", y);
	printf("Result z = %d\n", z);

	return 0;
}
