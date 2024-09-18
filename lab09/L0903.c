#include <stdio.h>
#include <string.h>

char s1[100];
char s2[100];

int i;

int
main(void)
{
	fputs("Enter your full string (s1): ", stdout);
	gets(s1);
	fputs("Enter your full string (s2): ", stdout);
	gets(s2);

	puts("\nBefore");
	puts(s1);
	puts(s2);

	strcpy(s2, "No Data");

	puts("\nAfter");
	puts(s1);
	puts(s2);

	return 0;
}
