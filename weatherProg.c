// Program:	weatherProg
// Author:		Kyle Crisp
// Course:		COP2220

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int     high, low;
    double  prec;

    printf("Welcome to Kyle Crisp's weather report... \n");
    printf("...\n");

    //Prompts user for input
    printf("Please enter the high temperature for the day: ");
    scanf("%i", &high);

    printf("Please enter the low temperature for the day: ");
    scanf("%i", &low);

    printf("Please enter the precipitation for the day: %%");
    scanf("%lf", &prec);

    int spread = (high - low);

    // Displays user inputed results
    printf("The high temperture is: %i\n", high);
    printf("The low temperature is: %i\n", low);
    printf("The spread is: %i\n", spread);
    printf("The precipitation is: %%%.2lf\n", prec);

    return 0;
}

    /*Test Case 1:
      Sample input:
      92, 73, 1.24

      Expected output:
      Welcome to Kyle Crisp's weather report...
      ...
      Please enter the high temperature for the day: 92
      Please enter the low temperature for the day: 73
      Please enter the precipitation for the day: %1.24
      The high temperture is: 92
      The low temperature is: 73
      The spread is: 19
      The precipitation is: %1.24

      Test Case 2:
      Sample input:
      84, 53, 53.24

      Expected output:
      Welcome to Kyle Crisp's weather report...
      ...
      Please enter the high temperature for the day: 84
      Please enter the low temperature for the day: 53
      Please enter the precipitation for the day: %53.24
      The high temperture is: 84
      The low temperature is: 53
      The spread is: 31
      The precipitation is: %53.24


      Test Case 3:
      Sample input:
      63, 56, 7.92

      Expected output:
      Welcome to Kyle Crisp's weather report...
      ...
      Please enter the high temperature for the day: 63
      Please enter the low temperature for the day: 56
      Please enter the precipitation for the day: %7.92
      The high temperture is: 63
      The low temperature is: 56
      The spread is: 7
      The precipitation is: %7.92

    */

    /* Sample Run 1:
       Welcome to Kyle Crisp's weather report...
       ...
       Please enter the high temperature for the day: 92
       Please enter the low temperature for the day: 73
       Please enter the precipitation for the day: %1.24
       The high temperture is: 92
       The low temperature is: 73
       The spread is: 19
       The precipitation is: %1.24


       Sample Run 2:
       Welcome to Kyle Crisp's weather report...

      Please enter the high temperature for the day: 84
      Please enter the low temperature for the day: 53
      Please enter the precipitation for the day: %53.24
      The high temperture is: 84
      The low temperature is: 53
      The spread is: 31
      The precipitation is: %53.24


       Sample Run 3:
       Welcome to Kyle Crisp's weather report...
      ...
      Please enter the high temperature for the day: 63
      Please enter the low temperature for the day: 56
      Please enter the precipitation for the day: %7.92
      The high temperture is: 63
      The low temperature is: 56
      The spread is: 7
      The precipitation is: %7.92

    */
