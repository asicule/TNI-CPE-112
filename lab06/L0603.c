#include <math.h>
#include <stdio.h>

#define PI 3.1416

double circleArea(double radius);
double cylinVol(double radius, double height);

int
main(void)
{
	double radius, height, area, volume;
	puts("Circle and Cylinder Volume Calculator");

	puts("\nCircle");
	fputs("Enter radius r: ", stdout);
	scanf("%lf", &radius);
	printf("Circle area %.2f\n", circleArea(radius));

	puts("\nCylinder");
	fputs("Enter height h: ", stdout);
	scanf("%lf", &height);
	printf("Cylinder volume %.2f\n", cylinVol(radius, height));

	return 0;
}

double
circleArea(double radius)
{
	return PI * pow(radius, 2);
}

double
cylinVol(double radius, double height)
{
	return circleArea(radius) * height;
}
