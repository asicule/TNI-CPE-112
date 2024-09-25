#include <stdio.h>
#include <string.h>

struct car {
	char color[50];
	float maxSpeed;
	float weight;
	float fuelTank;
	int carType;
};

struct car cars[3];

size_t cars_len = sizeof(cars) / sizeof(struct car);

int i;

int
main(void)
{
	printf("Enter properties for %zu cars\n-------------------------------\n",
	       cars_len);
	for (i = 0; i < cars_len; ++i) {
		printf("Car #%d\n", i + 1);
		fputs("Enter color: ", stdout);
		fgets(cars[i].color, sizeof(((struct car *)0)->color), stdin);
		cars[i].color[strlen(cars[i].color) - 1] = '\0';
		fputs("Enter Max Speed: ", stdout);
		scanf("%f", &cars[i].maxSpeed);
		fputs("Enter Weight: ", stdout);
		scanf("%f", &cars[i].weight);
		fputs("Enter Fuel Tank: ", stdout);
		scanf("%f", &cars[i].fuelTank);
		fputs("Enter Car Type: ", stdout);
		scanf("%d", &cars[i].carType);
		while (getchar() != '\n')
			;
		putchar('\n');
	}

	puts("Entered properties\n-------------------------------");
	for (i = 0; i < cars_len; ++i) {
		printf("Car #%d properties\n---------------\n", i + 1);
		printf("Color = %s\n", cars[i].color);
		printf("Max Speed = %.2f\n", cars[i].maxSpeed);
		printf("Weight = %.2f\n", cars[i].weight);
		printf("Fuel Tank = %.2f\n", cars[i].fuelTank);
		printf("Car Type = %d\n", cars[i].carType);
	}

	return 0;
}
