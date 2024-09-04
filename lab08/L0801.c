#include <stdio.h>

int apple = 17;
float meter = 22.38;
char order = 'k';

int *apple_p = &apple;
float *meter_p = &meter;
char *order_p = &order;

int
main(void)
{
	printf("apple is %d, stored at %p\n", apple, (void *)apple_p);
	printf("meter is %f, stored at %p\n", meter, (void *)meter_p);
	printf("order is %c, stored at %p\n", order, (void *)order_p);

	return 0;
}
