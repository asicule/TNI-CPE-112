#include <stdio.h>
#include <stdlib.h>

int
main()
{
	int order;
	float price;
	char iname;
	printf("Before\n");
	printf("order: %d\n", order);
	printf("price: %f\n", price);
	printf("iname: %c\n", iname);
	order = 43;
	price = 83.40;
	iname = 'S';
	printf("\nAfter\n");
	printf("order: %d\n", order);
	printf("price: %f\n", price);
	printf("iname: %c\n", iname);
	return 0;
}
