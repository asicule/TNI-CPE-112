#include <stdio.h>

int i = 0, score, score_sum = 0;
float score_average;
char grade_average;

int
main(void)
{
	printf("Enter s%d score: ", ++i);
	scanf("%d", &score);
	score_sum += score;
	printf("Enter s%d score: ", ++i);
	scanf("%d", &score);
	score_sum += score;
	printf("Enter s%d score: ", ++i);
	scanf("%d", &score);
	score_sum += score;
	printf("Enter s%d score: ", ++i);
	scanf("%d", &score);
	score_sum += score;
	printf("Enter s%d score: ", ++i);
	scanf("%d", &score);
	score_sum += score;

	score_average = (float) score_sum / i;

	putchar('\n');
	printf("Average score %.2f\n", score_average);

	if (score_average < 60) grade_average = 'F';
	else if (score_average < 70) grade_average = 'C';
	else if (score_average < 80) grade_average = 'B';
	else grade_average = 'A';
	printf("Average grade is %c\n", grade_average);

	return 0;
}
