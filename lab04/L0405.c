#include <stdio.h>

int part_id;
char *part_name;

int
main(void)
{
	printf("\
Avaliable parts list\n\
48. Radiator 240\n\
61. X43 Alternator\n\
99. B33 Battery\n\
\n\
Select the part to inspect: ");
	scanf("%d", &part_id);
	switch (part_id) {
		case 48:
			part_name = "Radiator 240";
			break;
		case 61:
			part_name = "X43 Alternator";
			break;
		case 99:
			part_name = "B33 Battery";
			break;
		default:
			printf("Error in part selection\n");
			return 1;
	}
	printf("%s selected\n", part_name);
}
