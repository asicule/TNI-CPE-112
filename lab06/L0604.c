#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int threeDices(void);

int
main(void)
{
	char ch = 0;
	short dice_sum, win;
	long my_money, bet;
	srand(time(NULL));

	/* Initalize Program */
	puts("Sic Bo Simulator");
	fputs("\nEnter wallet amount: ", stdout);
	scanf("%ld", &my_money);

start_bet:
	win = 0;
	fputs("\nPlace your bet: ", stdout);
	scanf("%ld", &bet);
select_bet:
	while ((ch = getchar()) != '\n' && ch != EOF);
	fputs("High 'H' (11-18) or Low 'L' (3-10): ", stdout);
	ch = getchar();
	switch (ch) {
		case 'H':
			dice_sum = threeDices();
			if (dice_sum > 11) win = 1;
			break;
		case 'L':
			dice_sum = threeDices();
			if (dice_sum < 11) win = 1;
			break;
		default:
			goto select_bet;
	}
	printf("Three dices gave %hd!\n", dice_sum);
	if (win) {
		puts("You win!");
		my_money += bet;
	} else {
		puts("You lose!");
		my_money -= bet;
	}

	printf("\nYour current balance is %ld\n", my_money);
	fputs("\nContinue? (y/n): ", stdout);
	scanf("%c", &ch);
	if (getchar() == 'y' && my_money > 0) goto start_bet;

	puts("\n\nGame over, please come again");
	return 0;
}

int
threeDices(void)
{
	int sum = 3;
	unsigned short i = 3;
	while (i--) sum += rand() % 6;
	return sum;
}
