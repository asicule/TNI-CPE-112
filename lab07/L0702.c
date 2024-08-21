#include <stdio.h>
#include <stdlib.h>

int people_ages[10];
size_t people_ages_len = sizeof(people_ages) / sizeof(int);

int
main(void)
{
	int i = 0;
	while (i < people_ages_len) {
		printf("Enter age for person #%d: ", i + 1);
		scanf("%d", &people_ages[i]);
		if (people_ages[i] < 0) {
			fputs("ERROR!\n", stderr);
			continue;
		}
		++i;
	}
	puts("\n--------");
	for (i = people_ages_len - 1; i >= 0; --i)
		printf("Person #%d age %d\n", i + 1, people_ages[i]);

	return 0;
}
