#include <stdio.h>
#include <stdlib.h>

float
speedDistance(float speed, int *time)
{
	float distance = speed * (*time);
	*time += 3;
	return distance;
}

int time = 1;
float speed;

int
main(void)
{
	int i;
	puts("Distance calculator\n-----------------------");
	for (i = 1; i <= 3; i++) {
		fputs("Enter speed: ", stdout);
		scanf("%f", &speed);
		printf("step %d => distance %.2f, time %u\n", i,
		       speedDistance(speed, &time), time);
	}

	return 0;
}
