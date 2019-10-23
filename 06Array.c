#include <stdio.h>

double computeAverage(int values[], int elements);
int getHighsAndLows(int highs[], int lows[], int capacity);

int main(void)
{
    int highs[7] = {0};//{83, 82, 82, 83, 84, 85, 85};
    int lows[7] = {0};//{71, 69, 68, 62, 61, 66, 67};
    int index, numElemHigh, numElemLow, count;
    double averageHigh, averageLow;

    numElemHigh = (sizeof(highs) / sizeof(highs[0]));
    numElemLow = (sizeof(lows) / sizeof(lows[0]));

    count = getHighsAndLows(highs, lows, 7);
    index = 0;
    while (index <= count - 1)
        {
            printf("Day: %i, Highs: %i, Lows: %i\n", (index + 1), highs[index], lows[index]);
            index = index + 1;
        }

    printf("Array size: %i\n", sizeof(highs));
    printf("Element size: %i\n", sizeof(highs[0]));
    printf("Number of elements: %i\n\n", sizeof(highs) / sizeof(highs[0]));

    averageHigh = computeAverage(highs, numElemHigh);
    averageLow = computeAverage(lows, numElemLow);

    computeAverage(highs, numElemHigh);
    printf("Average High: %.2lf\n", averageHigh);
    printf("Average Low: %.2lf\n", averageLow);

    return 0;
}

double computeAverage(int values[], int elements)
    {
        int index = 0;
        int total = 0;
        double average;

        while (index <= 6)
            {
                total = total + values[index];
                index = index + 1;
            }

        average = (double)total / elements;

        return average;
    }

int getHighsAndLows(int highs[], int lows[], int capacity)
    {
        int index = 0;
        char another = 'y';

        while (index < capacity && another == 'y')
        {
            printf("Enter high %i:  ", index + 1);
            scanf("\n%i", &highs[index]);
            printf("Enter low %i:  ", index + 1);
            scanf("\n%i", &lows[index]);
            index++;

            if (index < capacity)
                {
                    printf("Do you have another? [y/n]");
                    scanf("\n%c", &another);
                }
        }

        return index;
    }
