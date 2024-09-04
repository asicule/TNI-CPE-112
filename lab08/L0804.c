#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int array[12];
int *array_p = array;
ssize_t array_len = sizeof(array) / sizeof(array[0]);

void
print_array(int *array, ssize_t array_len)
{
	while (1) {
		printf("%d", *(array + --array_len));
		if (array_len <= 0)
			break;
		else
			putchar(' ');
	}
}

int
main(void)
{
	int i;

	srand(time(0));
	for (i = array_len - 1; i >= 0; i--)
		array[i] = rand() % 112;

	fputs("original ::: ", stdout);
	print_array(array, array_len);
	putchar('\n');

	for (i = array_len - 1; i >= 0; i--)
		*(array_p + i) *= 24;

	fputs("multiplied ::: ", stdout);
	print_array(array, array_len);
	putchar('\n');

	return 0;
}
