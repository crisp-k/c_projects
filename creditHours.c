// Program:	Ch03CreditHours
// Author:		Kyle Crisp
// Course:		COP2220

#include <stdio.h>

void displayWelcome(void);
int creditInput(void);
char residentInput (void);
double rateInput (void);
double totalCalculate (int credits, double creditRate);
void finalDisplay (int credits, char residentStatus, double amountDue);

int main (void)
{
	int credits;
	char residentStatus;
	double creditRate, amountDue;

	displayWelcome ();

	credits = creditInput();
    residentStatus = residentInput();

    if(residentStatus == 'Y')
    {
        creditRate = rateInput();
    }
    else
        creditRate = 401.27;

	amountDue = totalCalculate(credits, creditRate);

	finalDisplay(credits, residentStatus, amountDue);

	return 0;
}

void displayWelcome (void)
{
	printf("Welcome!\n\n");
	return ;
}

/* creditInput()
 * No parameters
 * Returns credits
 */
int creditInput (void)
{
    int credits;

    printf("Enter the number of credit hours: ");
	scanf("%i", &credits);

	return credits;
}

/* residentInput()
 * No parameters
 * Returns resident status
 */
char residentInput (void)
{
    char residentStatus;
    printf("Are you a resident (Y/N)? ");
    scanf("\n%c", &residentStatus);
    return residentStatus;
}

/* rateInput()
 * No parameters
 * Returns creditRate
 */
double rateInput (void)
{
    double creditRate;
    printf("Enter credit rate: ");
	scanf("\n%lf", &creditRate);
    return creditRate;
}

/* totalCalculate()
 * Parameters credits, credit rate
 * Returns amount due
 */
double totalCalculate (int credits, double creditRate)
{
    double amountDue = (credits * creditRate);
    return amountDue;
}

 void finalDisplay (int credits, char residentStatus, double amountDue)
 {
    printf("\nCredits enrolled in: %i\n", credits);
	printf("Resident status: %c\n", residentStatus);
	printf("Amount due: %.02lf\n", amountDue);
	return ;
 }
