#include <stdio.h>

double students_height[30];
size_t students_height_len = sizeof(students_height) / sizeof(double);

double
arr_mean(double int_arr[], unsigned int arr_len)
{
	int i = arr_len;
	double sum = 0;
	while (1) {
		if (i--)
			sum += int_arr[i];
		else
			break;
	}
	return (sum / arr_len);
}

int
main(void)
{
	int i = 0;
	while (i < students_height_len) {
		printf("Enter height for student #%d: ", i + 1);
		scanf("%lf", &students_height[i]);
		if (students_height[i] <= 0)
			break;
		++i;
	}

	printf("\nAverage height is %.2lf\n", arr_mean(students_height, i));
	printf("Number of students is %d\n", i);

	return 0;
}
