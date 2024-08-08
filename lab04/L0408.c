#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ANSWER_RANDOM_RANGE 50

int answer, a, b, c, d;
int n;
char choice_user, choice_correct;

int
main(void)
{
	printf("Equation :: ans = 15 / 2 + 3 - (14 * n)\n");
	printf("Enter n: ");
	scanf("%d", &n);
	srand(time(NULL));
	choice_correct = 0x61 + (rand() % 4);
	answer = 15 / 2 + 3 - (14 * n);
	/* Need loop to not be zero */
	a = answer + rand() % (ANSWER_RANDOM_RANGE * 2) - ANSWER_RANDOM_RANGE;
	b = answer + rand() % (ANSWER_RANDOM_RANGE * 2) - ANSWER_RANDOM_RANGE;
	c = answer + rand() % (ANSWER_RANDOM_RANGE * 2) - ANSWER_RANDOM_RANGE;
	d = answer + rand() % (ANSWER_RANDOM_RANGE * 2) - ANSWER_RANDOM_RANGE;
	switch (choice_correct) {
	case 'a':
		a = answer;
		break;
	case 'b':
		b = answer;
		break;
	case 'c':
		c = answer;
		break;
	case 'd':
		d = answer;
		break;
	}
	printf("\
Choices:\n\
a) %d\n\
b) %d\n\
c) %d\n\
d) %d\n\
\n\
Enter your answer: ",
	       a, b, c, d);
	getchar();
	choice_user = getchar();
	if (choice_user == choice_correct)
		printf("Correct answer!\n");
	else
		printf("Wrong answer\n");

	return 0;
}
