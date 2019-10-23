#include <stdio.h>

#define NUM_PEOPLE 11

int main(void)
{
    int feet [NUM_PEOPLE] = {6, 5, 6, 5, 6, 5, 5, 6, 6, 6, 5};
    int personNum [NUM_PEOPLE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    double inches [NUM_PEOPLE] = {3, 0, 1, 9.5, 3, 8, 10, 0, 0, 2, 2};
    double average;
    int inchTotal;
    int tallestFt = feet[0], tallestIn = inches[0], tallestPer;
    int shortestFt = feet[0], shortestIn = inches[0], shortestPer;
    int index = 0;
    int total = 0;

    printf("List of Heights: \n\n");
    while (index < NUM_PEOPLE)
       {
           printf("      Person #%i   Feet: %i  Inches: %.1lf\n", index + 1, feet[index], inches[index]);

           if (tallestFt < feet[index])
                if (tallestFt = feet[index] || (tallestIn < inches[index]))
                    {
                        tallestFt = feet[index];
                        tallestIn = inches[index];
                        tallestPer = personNum[index];
                    }

           if ((shortestFt > feet[index]) && (shortestIn > inches[index]))
           {
               shortestFt = feet[index];
               shortestIn = inches[index];
               shortestPer = personNum[index];
           }

           inchTotal = (feet[index] * 12) + inches[index];
           total = total + inchTotal;
           index++;
       }
    printf("The tallest person is #%i with a height of %ift %.1lfin\n", tallestPer, tallestFt, tallestIn);
    printf("The shortest person is #%i with a height of %ift %.1lfin\n", shortestPer, shortestFt, shortestIn);

    average = (total / NUM_PEOPLE);
    printf("The average height is %.1lfin\n", average);

    return 0;
}
