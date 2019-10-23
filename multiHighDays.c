#include <stdio.h>

#define MAX_DAYS 30

int highestDay(double values[], const int numElements);

int main(void)
{
    int highs[MAX_DAYS] = {91, 89, 90, 84, 97, 96, 97, 97, 96, 92, 90, 89, 88, 90, 88, 93, 96, 86, 84, 87, 87, 86, 87, 94, 96, 97, 93, 89, 89, 90};
    int lows[MAX_DAYS] =  {73, 77, 77, 73, 76, 72, 70, 71, 75, 73, 73, 73, 72, 73, 77, 72, 70, 72, 72, 71, 66, 67, 64, 64, 71, 73, 72, 68, 67, 71};
    double rainfall[MAX_DAYS] = {0.30, 0.07, 0.38, 0.59, 0.10, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 
                                0.32, 0.01, 0.01, 0.27, 0.00, 0.00, 0.24, 0.06, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00};
    double dbleHighs[MAX_DAYS] = { };
    double dbleLows[MAX_DAYS] = { };
    int index, highestValueIndex;

    for(index = 0; index < MAX_DAYS; index++)
        {
            dbleHighs[index] = highs[index];
            dbleLows[index] = lows[index];
        }
    


    printf("Information for day(s) with highest temperature: \n\n");

    highestValueIndex = highestDay(dbleHighs, MAX_DAYS);
    for(index = 0; index < MAX_DAYS; index++)
        {
            if(dbleHighs[highestValueIndex] == dbleHighs[index])
                {
                    printf("    Day: %i\n", index + 1);
                    printf("    High Temperature: %i\n", highs[index]);
                    printf("    Low Temerature: %i\n", lows[index]);
                    printf("    Rainfall %.2lf\n\n", rainfall[index]);
                }
        }

}

int highestDay(double values[], const int numElements)
{
    int index, highestIndex;
    double highest = values[0];

    for(index = 0; index < numElements; index++)
        {
            if (highest < values[index])
                {
                    highest = values[index];
                    highestIndex = index;
                }
        }

    return highestIndex;
}
