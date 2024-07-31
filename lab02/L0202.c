#include <stdio.h>

#define MILLI_RATE 10
#define METER_RATE 100
#define INCH_RATE 2.54

double user_input;
double centimeter, millimeter, meter, inch;

int
main(void)
{
	printf("Enter length in centemeter: ");
	scanf("%lf", &user_input);
	centimeter = user_input;
	millimeter = centimeter * MILLI_RATE;
	meter = centimeter / METER_RATE;
	inch = centimeter / INCH_RATE;
	printf("%.2lf centimeters = %.2lf millimeter, %.2lf meters, and %.2lf inches\n", centimeter, millimeter, meter, inch);
	return 0;
}
