#include <stdio.h>

char s1[100];
char s2[100];

int i;

int
main(void)
{
	fputs("Enter your full name (s1): ", stdout);
	gets(s1);
	fputs("Enter your full name again (s2): ", stdout);
	scanf("%s", s2);

	for (i = 0; i < sizeof(s2); ++i)
		if (s2[i] == ' ')
			break;
	s2[i] = '\0';

	puts("\nResults");
	puts(s1);
	puts(s2);

	return 0;
}
