#include <stdio.h>

#define MAX_DAYS 30

double convertToDouble(int temp[], int index, const int numElements);

int main(void)
{
    int highs[MAX_DAYS] = {91, 89, 90, 84, 97, 96, 97, 97, 96, 92, 90, 89, 88, 90, 88, 93, 96, 86, 84, 87, 87, 86, 87, 94, 96, 97, 93, 89, 89, 90};
    int lows[MAX_DAYS] =  {73, 77, 77, 73, 76, 72, 70, 71, 75, 73, 73, 73, 72, 73, 77, 72, 70, 72, 72, 71, 66, 67, 64, 64, 71, 73, 72, 68, 67, 71};
    double dbleHighs[MAX_DAYS] = { };
    double dbleLows[MAX_DAYS] = { };
    int index;

     for(index = 0; index < MAX_DAYS; index++)
        {
            dbleHighs[index] = convertToDouble(highs, index, MAX_DAYS);
            dbleLows[index] = convertToDouble(lows, index, MAX_DAYS);

            printf("Double Highs %i: %.1lf  Double Lows %i: %.1lf\n", index, dbleHighs[index], index, dbleLows[index]);
        }
    
    return 0;
}

double convertToDouble(int temp[], int index, const int numElements)
{
    double dbleTemp;

    dbleTemp = temp[index];

    return dbleTemp;
}