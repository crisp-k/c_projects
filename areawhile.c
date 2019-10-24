// Program:	Program Name
// Author:		Author
// Course:

#include <stdio.h>

int main (void)
{
	double length, width, area;
	int index;
	char again;
	do
	{
		printf("Enter the length: ");
		scanf("%lf", &length);
		while (length < 0)
		{
			printf("Invalid length, length must be positive. \n");
			printf("Enter the length: ");
			scanf("%lf", &length);
		}
		do
		{
			printf("Enther the width: ");
			scanf("%lf", &width);
			if (width < 0)
				printf("Invalid width. Width must be positive. \n");
		}
		while (width < 0);
		area = length * width;
		printf("The aread of a %.2lf by %.2lf is %.2lf\n", length, width, area);
		printf("Would you like to run again? (Y/N)");
		scanf("\n%c", &again);
	}
	while (again == 'Y');
	for (index = 0; index <= 2; index = index + 1)
		printf("Goodbye. \n");
	return 0;
}




/*
Test data 1:
Length: 5, Width: 3

Expected results:
Length: 5.00, Width: 3.00, Area: 15.00

Test data 2:
Length: 3.5, Width: 4.7

Expected results:
Length: 3.50, Width: 4.70, Area: 16.45

Test data 3:
Length: 15.3, Width: 46.50

Expected results:
Length: 15.3, Width: 46.50, Area: 711.45
*/

/*
Output 1:
Enter the length: 5
Enther the width: 3
The aread of a 5.00 by 3.00 is 15.00
Would you like to run again? (Y/N)

Output 2:
Enter the length: 3.5
Enther the width: 4.7
The aread of a 3.50 by 4.70 is 16.45
Would you like to run again? (Y/N)

Output 3:
Enter the length: 15.3
Enther the width: 46.5
The aread of a 15.30 by 46.50 is 711.45
Would you like to run again? (Y/N)
*/
