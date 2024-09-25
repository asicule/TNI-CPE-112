#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct card {
	int point;
	char symbol;
};

struct card handCards[5];
size_t handCards_len = sizeof(handCards) / sizeof(struct card);

void
get_card(unsigned short card_index, struct card *card)
{
	card->point = 1 + card_index % 13;
	card->symbol = 65 + (card_index % 4);
}

int
main(void)
{
	int i;
	srand(time(NULL));
	while (1) {
		fputs("Draw 5 cards? (y/n): ", stdout);
		switch (getchar()) {
		case 'n':
			break;
		case 'y':
			for (i = 0; i < handCards_len; ++i) {
				get_card(rand() % 52, &handCards[i]);
			}
			fputs("\nYou got", stdout);
			for (i = 0; i < handCards_len; ++i) {
				printf(" %d%c", handCards[i].point, handCards[i].symbol);
			}
			putchar('\n');
			putchar('\n');
		default:
			while (getchar() != '\n')
				;
			continue;
		}
		break;
	}

	return 0;
}
