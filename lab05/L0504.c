#include <stdio.h>
#include <stdlib.h>

double width, length, buf;
int sections;

int
main(void)
{
	while (1) {
		fputs("Enter width: ", stdout);
		scanf("%lf", &width);
		fputs("Enter length: ", stdout);
		scanf("%lf", &length);
		fputs("Enter number of areas (n): ", stdout);
		scanf("%d", &sections);
		if (width > 0 && length > 0 && sections > 0) break;
		else puts("Error input");
		putchar('\n');
	}
	putchar('\n');
	if (width > length) {
		buf = width;
		width = length;
		length = buf;
	}
	printf("Width :: %.2f\n", width);
	printf("Length :: %.2f\n", length);
	printf("Area for each n :: %.2f\n", (width * length) / sections);

	return 0;
}
