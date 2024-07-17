#include <stdio.h>
#include <time.h>

int birth_year;

int
main()
{
	time_t timestamp = time(NULL);
	struct tm tm = *localtime(&timestamp);
	int current_year = tm.tm_year + 1900;
	printf("Enter birth year: ");
	scanf("%d", &birth_year);
	printf("User age is %d\n", current_year - birth_year);
	return 0;
}
