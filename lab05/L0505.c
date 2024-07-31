#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

short score, score_lowest = SHRT_MAX, score_highest = 0;
unsigned long score_highest_index, score_lowest_index;
unsigned long student_num = 0;
unsigned long score_sum = 0;

int
main(void)
{
	puts("Student score calculator");
	putchar('\n');

	while (1) {
		printf("Enter score for student %lu: ", ++student_num);
		scanf("%hd", &score);

		if (score < 0) {
			student_num--;
			break;
		}

		if (score > score_highest) {
			score_highest = score;
			score_highest_index = student_num;
		}
		if (score < score_lowest) {
			score_lowest = score;
			score_lowest_index = student_num;
		}
		score_sum += score;
	}
	putchar('\n');
	printf("Average score :: %.2f\n", (double) score_sum / (double) student_num);
	printf("Highest score :: %hd, by student %lu\n", score_highest, score_highest_index);
	printf("Lowest score  :: %hd, by student %lu\n", score_lowest, score_lowest_index);

	return 0;
}
