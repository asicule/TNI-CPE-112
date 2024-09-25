#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef char color_t[50];

struct engine {
	char name;
	float maxSpeed;
	float weight;
};

struct car_type {
	int carType;
	float weight;
	float fuelTank;
};

struct car {
	color_t color;
	float maxSpeed;
	float weight;
	float fuelTank;
	int carType;
};

struct engine engines[] = {
    {'A', 160, 395}, {'B', 100, 250.8}, {'C', 184.63, 535.64}};
size_t engines_len = sizeof(engines) / sizeof(struct engine);

struct car_type car_types[] = {{1, 529.8, 44.32}, {2, 633.4, 57.46}};
size_t car_types_len = sizeof(car_types) / sizeof(struct car_type);

int
get_car_engine_info(char engine, struct car *car)
{
	int i;
	for (i = 0; i < engines_len; ++i) {
		if (engine == engines[i].name) {
			car->weight += engines[i].weight;
			car->maxSpeed = engines[i].maxSpeed;
			return 0;
		}
	}
	return -1;
}

int
get_car_type_info(int carType, struct car *car)
{
	int i;
	for (i = 0; i < car_types_len; ++i) {
		if (carType == car_types[i].carType) {
			car->weight += car_types[i].weight;
			car->fuelTank = car_types[i].fuelTank;
			car->carType = car_types[i].carType;
			return 0;
		}
	}
	return -1;
}

color_t colors[] = {"Black", "White", "Red", "Blue"};

char *
get_random_color(void)
{
	return colors[rand() % (sizeof(colors) / sizeof(color_t))];
}

struct car cars[100] = {0};
size_t cars_len = 0;

int i;

int
main(void)
{
	char usr_engine;
	int usr_car_type;
	unsigned int order_count, printout;
	srand(time(NULL));
	puts("Car Assembly Line\n-----------------------");
	fputs("Select engine (A, B, or C): ", stdout);
	usr_engine = getchar();
	fputs("Select car type (1 or 2): ", stdout);
	scanf("%d", &usr_car_type);
	fputs("How many to make: ", stdout);
	scanf("%u", &order_count);

	for (i = 0; i < order_count; ++i) {
		get_car_engine_info(usr_engine, &cars[i]);
		get_car_type_info(usr_car_type, &cars[i]);
		strncpy(cars[i].color, get_random_color(), sizeof(color_t));
	}

	printout = (order_count < 5 ? order_count : 5);
	for (i = 0; i < printout; ++i) {
		printf("\nCar #%d properties\n---------------\n", i + 1);
		printf("Color = %s\n", cars[i].color);
		printf("Max Speed = %.2f\n", cars[i].maxSpeed);
		printf("Weight = %.2f\n", cars[i].weight);
		printf("Fuel Tank = %.2f\n", cars[i].fuelTank);
		printf("Car Type = %d\n", cars[i].carType);
	}

	return 0;
}
