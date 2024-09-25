#include <stdio.h>

struct car {
	char color[50];
	float maxSpeed;
	float weight;
	float fuelTank;
	int carType;
};

struct car myCar = {.color = "Blue",
                    .maxSpeed = 162.5,
                    .weight = 985.36,
                    .fuelTank = 40,
                    .carType = 1};

int
main(void)
{
	puts("myCar properties\n---------------");
	printf("Color = %s\n", myCar.color);
	printf("Max Speed = %.2f\n", myCar.maxSpeed);
	printf("Weight = %.2f\n", myCar.weight);
	printf("Fuel Tank = %.2f\n", myCar.fuelTank);
	printf("Car Type = %d\n", myCar.carType);

	return 0;
}
