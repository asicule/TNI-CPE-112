#include <stdio.h>
#include <math.h>

#define ITER_MAX 4

double x, sum = 0;

int
main()
{
	int i = 0;
	while (i < ITER_MAX) {
		i++;
		printf("Enter x%d: ", i);
		scanf("%lf", &x);
		sum += pow(x, 2);
	}
	printf("\n");
	printf("xrms = %.3lf\n", sqrt(sum / i));

	return 0;
}
