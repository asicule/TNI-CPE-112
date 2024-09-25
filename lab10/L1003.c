#include <stdio.h>
#include <string.h>

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

struct car *p = &myCar;

int
main(void)
{
	puts("myCar properties\n---------------");
	printf("Color = %s\n", myCar.color);
	printf("Max Speed = %.2f\n", myCar.maxSpeed);
	printf("Weight = %.2f\n", myCar.weight);
	printf("Fuel Tank = %.2f\n", myCar.fuelTank);
	printf("Car Type = %d\n", myCar.carType);

	p->weight = 1234.5;
	p->maxSpeed = 1234.5;
	strcpy(p->color, "Bronze");

	puts("\nmyCar properties\n---------------");
	printf("Color = %s\n", myCar.color);
	printf("Max Speed = %.2f\n", myCar.maxSpeed);
	printf("Weight = %.2f\n", myCar.weight);
	printf("Fuel Tank = %.2f\n", myCar.fuelTank);
	printf("Car Type = %d\n", myCar.carType);

	return 0;
}
