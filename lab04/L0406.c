#include <stdio.h>

double width, length, area;
int family_member_count;
double area_per_family_member;

int
main(void)
{
	printf("Bann Sai Thong\n\n");
	printf("Enter land width: ");
	scanf("%lf", &width);
	printf("Enter land length: ");
	scanf("%lf", &length);
	printf("Enter number of family members: ");
	scanf("%d", &family_member_count);
	putchar('\n');
	
	area = width * length;
	area_per_family_member = area / family_member_count;
	if (width > 0 && length > 0 && family_member_count > 0)
		printf("Each member will receive a %.4f sq.m. of land\n", area_per_family_member);
	else {
		printf("Error inputs\n");
		return 1;
	}
	if (area_per_family_member < 50) printf("Not optimal for family members.\n");

	return 0;
}
