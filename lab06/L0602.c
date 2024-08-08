#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *get_hand_str(int hand_num);

int
main(void)
{
	int user_hand, program_hand;
	puts("Rock - Scissors - Paper\n\n\
Rules\n\
---------------\n\
Rock > Scissors\n\
Scissors > Paper\n\
Paper > Rock\
");

	srand(time(NULL));

	while (1) {
		/* User part */
		fputs("\nEnter 1.Rock 2.Scissors 3.Paper : ", stdout);
		scanf("%d", &user_hand);
		printf("User :: %s\n", get_hand_str(user_hand));
		if (user_hand < 1 || user_hand > 3)
			continue;

		/* Program part */
		program_hand = 1 + rand() % 3;
		printf("CPU :: %s\n", get_hand_str(program_hand));

		putchar('\n');
		/*
		    U - P = T =  0
		    1 - 2 = U = -1
		    1 - 3 = P = -2
		    2 - 1 = P =  1
		    2 - 3 = U = -1
		    3 - 1 = U =  2
		    3 - 2 = P =  1
		*/
		switch (user_hand - program_hand) {
		case 0:
			goto tie;
		case -1:
		case 2:
			goto user_win;
		case -2:
		case 1:
			goto cpu_win;
		}

	tie:
		puts("It's a tie!");
		continue;
	user_win:
		puts("Player wins!");
		break;
	cpu_win:
		puts("CPU wins!");
		break;
	}
}

char *
get_hand_str(int hand_num)
{
	switch (hand_num) {
	case 1:
		return "Rock";
	case 2:
		return "Scissor";
	case 3:
		return "Paper";
	}
	return "Error Input";
}
