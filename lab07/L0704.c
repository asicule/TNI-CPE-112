#include <stdio.h>
#include <stdlib.h>

char goods[] = {'E', 'R', 'T', 'Y', 'U'};
double goods_price[] = {99.00, 199.00, 149.00, 639.00, 1099.00};

size_t goods_len = sizeof(goods);

int goods_amount[sizeof(goods)] = {0};

int
main(void)
{
	int i, good_amount;
	char ch;
	double price_sum = 0, good_price_sum;

	puts("Welcome to the shop!");
	puts("----------");

	for (i = 0; i < goods_len; i++)
		printf("%d. %c price %.2f\n", i + 1, goods[i], goods_price[i]);

	while (1) {
		printf("What would you like to buy? (1-%lu): ", goods_len);
		scanf("%d", &i);
		if (i > goods_len || i < 1) {
			puts("Error number");
			continue;
		}
	input_amount:
		fputs("Amount: ", stdout);
		scanf("%d", &good_amount);
		if (good_amount < 0) {
			puts("Error amount");
			goto input_amount;
		}
		goods_amount[i - 1] += good_amount;
		fputs("Press y to stop shopping, others to continue: ", stdout);
		while ((ch = getchar()) != EOF && ch != '\n')
			;
		ch = getchar();
		if (ch == 'y')
			break;
	}

	puts("\nYou purchased");
	puts("----------");
	for (i = 0; i < goods_len; ++i) {
		good_price_sum = goods_price[i] * goods_amount[i];
		printf("%d. %c ::: %d ::: %.2f\n", i + 1, goods[i], goods_amount[i],
		       good_price_sum);
		price_sum += good_price_sum;
	}

	if (price_sum > 2000) {
		puts("\n18% DISCOUNT");
		price_sum *= 0.82;
	}

	printf("\nTotal ::: %.2f\n", price_sum);

	return 0;
}
