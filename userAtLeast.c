#include <stdio.h>

#define MAX_DAYS 30

int main()
{
    int highs[MAX_DAYS] = {91, 89, 90, 84, 97, 96, 97, 97, 96, 92, 90, 89, 88, 90, 88, 93, 96, 86, 84, 87, 87, 86, 87, 94, 96, 97, 93, 89, 89, 90};
    int lows[MAX_DAYS] =  {73, 77, 77, 73, 76, 72, 70, 71, 75, 73, 73, 73, 72, 73, 77, 72, 70, 72, 72, 71, 66, 67, 64, 64, 71, 73, 72, 68, 67, 71};
    double rainfall[MAX_DAYS] = {0.30, 0.07, 0.38, 0.59, 0.10, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 
                                0.32, 0.01, 0.01, 0.27, 0.00, 0.00, 0.24, 0.06, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00};
    int atLeast, index, daysFound;

    printf("Enter a High Temperature:\n");
    scanf("\n%i", &atLeast);

    printf("Days that have at least a temperature of: %i\n\n", atLeast);

    for(index = 0; index < MAX_DAYS; index++)
        {
            if(highs[index] >= atLeast)
                {
                    printf("    Day: %i\n", index + 1);
                    printf("    High Temperature: %i\n", highs[index]);
                    printf("    Low Temerature: %i\n", lows[index]);
                    printf("    Rainfall %.2lf\n\n", rainfall[index]);
                    daysFound = daysFound + 1;
                }
        }
    
    printf("Days found with a temperature of at least %i: %i\n\n", atLeast, daysFound);

}