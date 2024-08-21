#include <stdio.h>
#include <stdlib.h>

float product_arr[] = {7.25, 10.00, 5.00, 12.50, 20.00, 50.00, 15.25};
size_t product_arr_len = sizeof(product_arr) / sizeof(float);

int
main(void)
{
	int i;
	for (i = 0; i < product_arr_len; i++)
		printf("product %d       price   %.2f\n", i + 1,
		       product_arr[i]);

	return 0;
}
