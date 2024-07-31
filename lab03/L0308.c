#include <stdio.h>
#include <math.h>

#define PI 3.1416
double r, area;

int
main(void)
{
	printf("Enter r: ");
	scanf("%lf", &r);

	area = PI * pow(r, 2);
	printf("\n");
	printf("Circle area = %.2lf\n", area);
	printf("Big circle %d\n", (int) area / 100);

	return 0;
}


