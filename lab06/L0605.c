#include <stdio.h>
#include <time.h>

#define CLOCKS_PER_MS (CLOCKS_PER_SEC / 1000)

void delay(unsigned int milliseconds);
void fire_cannon(unsigned int cannon_num, unsigned int ammo_count, unsigned int delay, unsigned int print_wait_interval, char* print_wait_interval_format_specifier);
void fire_first_cannon(unsigned int ammo_count) { fire_cannon(1, ammo_count, 6000, 2000, "%.0f sec. passed\n"); }
void fire_second_cannon(unsigned int ammo_count) { fire_cannon(2, ammo_count, 600, 200, "%.1f sec. passed\n"); }

int
main(void)
{
	int round_current;
	unsigned int c1r, c2r;
	fputs("Enter amount of rounds for cannon 1: ", stdout);
	scanf("%ud", &c1r);
	fputs("Enter amount of rounds for cannon 2: ", stdout);
	scanf("%ud", &c2r);

	puts("\nTesting cannon 1\n----------------");
	fire_first_cannon(c1r);
	puts("\nCannon 1 out of ammo");

	puts("\nTesting cannon 2\n----------------");
	fire_second_cannon(c2r);
	puts("\nCannon 2 out of ammo");

	puts("\nEnd of program");
}

void fire_cannon(unsigned int cannon_num, unsigned int ammo_count, unsigned int delay_ms, unsigned int print_wait_interval_ms, char* print_wait_interval_format_specifier) {
	int round_current = 0;
	double time_delta;
	clock_t clock_start;
	while (1) {
		time_delta = 0;
		clock_start = clock();
		printf("\nFiring cannon %d %d/%d\n", cannon_num, ++round_current, ammo_count);
		if (round_current < ammo_count)
			while (1) {
				delay(print_wait_interval_ms);
				time_delta = (clock() - clock_start) / CLOCKS_PER_MS;
				printf(print_wait_interval_format_specifier, time_delta / 1000);
				if (time_delta >= delay_ms) break;
			}
		else break;
		/* Fire ammo!!! */
	}
}

void delay(unsigned int milliseconds) {
	clock_t clock_start = clock();
	while (((clock() - clock_start) / CLOCKS_PER_MS) <  milliseconds);
}
