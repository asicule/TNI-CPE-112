#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DICE_FACE 6
#define BOARD_CHANNELS 25

unsigned short initial_flush_stdin = 1;

void
flush_stdin(void)
{
	char ch;
	if (initial_flush_stdin) {
		initial_flush_stdin = 0;
		return;
	}
	while ((ch = getchar()) != EOF && ch != '\n')
		;
}

unsigned int
roll_dice(unsigned short dice_count)
{
	unsigned int dice_sum = 0;
	while (dice_count--)
		dice_sum += (1 + (rand() % DICE_FACE));
	return dice_sum;
}

int
exists_in_unsigned_integer_array(unsigned int num, unsigned int *array,
                                 ssize_t array_len)
{
	unsigned int i = 0;
	while (i < array_len)
		if (num == array[i++])
			return 1;
	return 0;
}

void
print_board(unsigned int *players_pos, ssize_t players_pos_len,
            unsigned int *holes, ssize_t holes_len)
{
	unsigned int i = 1;
	int is_player;
	int is_hole;
	fputs("Board :: ", stdout);
	while (1) {
		is_player = exists_in_unsigned_integer_array(i, players_pos,
		                                             players_pos_len);
		is_hole = exists_in_unsigned_integer_array(i, holes, holes_len);
		if (is_player)
			putchar('(');
		if (is_hole)
			putchar('_');
		printf("%u", i);
		if (is_hole)
			putchar('_');
		if (is_player)
			putchar(')');
		if (i < BOARD_CHANNELS)
			putchar(' ');
		else
			break;
		++i;
	}
}

int
main(void)
{
	unsigned int players_pos[1] = {1};
	ssize_t players_pos_len = sizeof(players_pos) / sizeof(players_pos[0]);
	int p_now = 0;
	unsigned int dice_res;
	char ch;
	unsigned int holes[] = {4, 14, 24};
	ssize_t holes_len = sizeof(holes) / sizeof(holes[0]);

	srand(time(0));

	puts("Snake and Ladder");

	while (players_pos[p_now] < BOARD_CHANNELS) {
		putchar('\n');
		print_board(players_pos, players_pos_len, holes, holes_len);
		putchar('\n');
		while (1) {
			flush_stdin();
			fputs("Roll dice?(y): ", stdout);
			if (getchar() == 'y')
				break;
			puts("Error input\n");
		}
		dice_res = roll_dice(1);
		players_pos[p_now] += dice_res;
		printf("You got %d\n", dice_res);
		print_board(players_pos, players_pos_len, holes, holes_len);
		if (exists_in_unsigned_integer_array(players_pos[p_now], holes,
		                                     holes_len)) {
			players_pos[p_now] -= 3;
		}
		putchar('\n');
	}
	puts("\nFINISH!");
}
