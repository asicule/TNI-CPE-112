#include <stdio.h>

int i = 0;

int
main(void)
{
	float velocity = 0;
	float acceleration;
	puts("Starting the engine");
	fputs("Enter the acceleration value (m/s^2): ", stdout);
	scanf("%f", &acceleration);

	while (velocity < 20) {
		printf("Current speed at t=%d is %.3f m/s\n", i++, velocity);
		velocity += acceleration;
	}
	printf("Current speed at t=%d is %.3f m/s\n", i, velocity);

	return 0;
}
