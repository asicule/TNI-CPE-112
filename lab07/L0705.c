#include <stdio.h>

int numbers[50];
unsigned int numbers_len = sizeof(numbers) / sizeof(int);

void bubble_sort(int num_array[], int num_array_len) {
	int i_last, i, buf;
	/* Decrement last index of the array as the previous pass is already makes
	   the number of the last one have the most value */
	for (i_last = num_array_len - 1; i_last > 0; --i_last)
		/* Loop increamentally for swap number to make the i_last the most number */
		for (i = 0; i < i_last; ++i) {
			/* Swap number if the current number is more than the next one */
			if (num_array[i] > num_array[i+1]) {
				buf = num_array[i];
				num_array[i] = num_array[i+1];
				num_array[i+1] = buf;
			}
		}
}

int
main(void)
{
	int i = 0, number;
	while (i < numbers_len) {
		printf("Enter number #%d: ", i+1);
		scanf("%d", &number);
		if (number <= 0) break;
		numbers[i++] = number;
	}

	numbers_len = i;

	fputs("\nEntered :::", stdout);
	for (i = 0; i < numbers_len; ++i)
		printf(" %d", numbers[i]);
	putchar('\n');

	bubble_sort(numbers, numbers_len);
	fputs("\nSorted :::", stdout);
	for (i = 0; i < numbers_len; ++i)
		printf(" %d", numbers[i]);
	putchar('\n');

	return 0;
}
