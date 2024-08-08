#include <stdio.h>

unsigned short lines_asterisk, lines_slash, lines_minus, lines_equal;

int
main(void)
{
	unsigned int user_input;
	int line, ch_index;
	do {
		printf("Enter 4-digit number: ");
		scanf("%u", &user_input);
	} while (user_input < 1000 || user_input > 9999);
	lines_asterisk = user_input / 1000;
	lines_slash = user_input / 100 % 10;
	lines_minus = user_input / 10 % 10;
	lines_equal = user_input % 10;

	printf("You entered %u %u %u and %u\n", lines_asterisk, lines_slash,
	       lines_minus, lines_equal);

	for (line = 0; line < lines_asterisk; line++) {
		for (ch_index = 0; ch_index <= line; ch_index++)
			fputs("* ", stdout);
		putchar('\n');
	}

	for (line = lines_slash; line > 0; line--) {
		for (ch_index = line; ch_index > 0; ch_index--)
			fputs("/ ", stdout);
		putchar('\n');
	}

	for (line = 0; line < lines_minus; line++) {
		for (ch_index = lines_minus - line; ch_index > 1; ch_index--)
			fputs("  ", stdout);
		for (ch_index = line * 2 + 1; ch_index > 0; ch_index--)
			fputs("- ", stdout);
		putchar('\n');
	}

	for (line = lines_equal; line > 0; line--) {
		for (ch_index = lines_equal - line; ch_index > 0; ch_index--)
			fputs("  ", stdout);
		for (ch_index = line * 2 - 1; ch_index > 0; ch_index--)
			fputs("= ", stdout);
		putchar('\n');
	}

	return 0;
}
