#include <stdio.h>
#include <math.h>

#define PI 3.1416

double r, h;

int
main()
{
	printf("Enter r: "); scanf("%lf", &r);
	printf("Enter h: "); scanf("%lf", &h);

	printf("\n");
	printf("Circle area = %.2lf\n", PI * pow(r, 2));
	printf("\n");
	printf("Sphere volume = %.2lf\n", PI * pow(r, 3) * 4 / 3);
	printf("\n");
	printf("Circle area = %.2lf\n", PI * pow(r, 2) * h);

	return 0;
}
