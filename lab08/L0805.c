#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SPACE_BETWEEN_ATK_DEF 9

unsigned short initial_flush_stdin = 1;

int
random_stat(void)
{
	return rand() % 100 * 100;
}

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

void
swap_integer(int *p1, int *p2)
{
	int buf;
	buf = *p1;
	*p1 = *p2;
	*p2 = buf;
}

unsigned short
getdigit(int number)
{
	int i = 1;
	while (1) {
		number /= 10;
		if (!number)
			return i;
		else
			++i;
	}
}

void
print_atk_def(int atk, int def)
{
	unsigned short space = SPACE_BETWEEN_ATK_DEF - getdigit(atk);
	printf("ATK :: %d", atk);
	while (space--)
		putchar(' ');
	printf("DEF :: %d", def);
	putchar('\n');
}

int
main(void)
{
	srand(time(0));
	int p_atk, p_def, o_atk, o_def;
	p_atk = random_stat();
	p_def = random_stat();
	o_atk = random_stat();
	o_def = random_stat();
	char ch;

	puts("Card Battle!");
	puts("\nPlayer\n--------");
	print_atk_def(p_atk, p_def);
	puts("\nOpponent\n--------");
	print_atk_def(o_atk, o_def);

	while (1) {
		flush_stdin();
		fputs("\nSwitch player's ATK and DEF? (y/n): ", stdout);
		ch = getchar();
		if (ch == 'y') {
			swap_integer(&p_atk, &p_def);
			puts("\nPlayer\n--------");
			print_atk_def(p_atk, p_def);
			break;
		} else if (ch == 'n')
			break;
		else
			puts("Error input");
	}

	puts("\nAttack calculating ATK vs ATK");
	if (p_atk < o_atk)
		puts("Player destroyed!");
	else if (p_atk > o_atk)
		puts("Opponent destroyed!");
	else
		puts("Draw!");

	return 0;
}
