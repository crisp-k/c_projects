// Program:		multiTemp
// Author:		Kyle Crisp
// Course:		COP 2220
// Due: 10/09/19

#include <stdio.h>
#include <ctype.h>

// constants to be used
#define tempFreezeFah 32
#define tempBoilFah 212
#define tempFreezeCel 0
#define tempBoilCel 100
#define tempFreezeKel 273.15

double getTemp();
double fahToCel(double tempF, double conRatio);
double fahToKel(double tempF, double conRatio);
double celToFah(double tempC, double conRatio);
double celToKel(double tempC);
double kelToFah(double tempK, double conRatio);
double kelToCel(double tempK);

int main(void)
{
    // declaration of variables
    double temp, tempF, tempC, tempK;
    int test = 1;

    // establishes conversion ratios to be passed into conversion functions
    double fahCelRatio = ((double) tempBoilCel - tempFreezeCel)/((double) tempBoilFah - tempFreezeFah);
    double celFahRatio = ((double) tempBoilFah - tempFreezeFah)/((double) tempBoilCel - tempFreezeCel);

    // while loop, test parameter is always true,
    // so loop will always execute
    while (test == 1)
    {
        // delcaration of variable
        char userChoice;

        // menu prompt for user, asks for input
        printf("Convert from:\n");
        printf("a) Fahrenheit to Celsius \nb) Fahrenheit to Kelvin \n");
        printf("c) Celsius to Fahrenheit \nd) Celsius to Kelvin \n");
        printf("e) Kelvin to Fahrenheit \nf) Kelvin to Celsius \n");
        printf("g) Exit program \n");
        scanf("\n%c", &userChoice);

        // switch statement for each potential user choice
        switch(tolower(userChoice))
        {
            // converts from Fahrenheit to Celsius
            case 'a':
                temp = getTemp();
                tempC = fahToCel(temp, fahCelRatio);
                printf("%.1lfF converts to %.1lfC\n\n", temp, tempC);
                break;

            // converts from Fahrenheit to Kelvin
            case 'b':
                temp = getTemp();
                tempK = fahToKel(temp, fahCelRatio);
                printf("%.1lfF converts to %.1lfK\n\n", temp, tempK);
                break;

            // converts from Celsius to Fahrenheit
            case 'c':
                temp = getTemp();
                tempF = celToFah(temp, celFahRatio);
                printf("%.1lfC converts to %.1lfF\n\n", temp, tempF);
                break;

            // converts from Celsius to Kelvin
            case 'd':
                temp = getTemp();
                tempK = celToKel(temp);
                printf("%.1lfC converts to %.1lfK\n\n", temp, tempK);
                break;

            // converts from Kelvin to Fahrenheit
            case 'e':
                temp = getTemp();
                tempF = kelToFah(temp, celFahRatio);
                printf("%.1lfK converts to %.1lfF\n\n", temp, tempF);
                break;

            // converts from Kelvin to Celsius
            case 'f':
                temp = getTemp();
                tempC = kelToCel(temp);
                printf("%.1lfK converts to %.1lfC\n\n", temp, tempC);
                break;

            // displays good-bye message if the user wishes to exit
            case 'g':
                printf("Results provided by Kyle Crisp, have a wonderful day.\n");
                break;

            // default case, if user inputs a non-valid option
            default:
                printf("That is not a valid selection, please enter a valid selection. \n");
                break;

        }

        // if statement to break from while loop
        // if user chooses 'exit' option
        if (userChoice == 'g')
            break;
    }

    return 0;
}

// getTemp() - prompts user for intial temperature
// no parameters
// returns: users input
double getTemp()
{
    // variable declaration
    double temp;

    // promts user for input
    printf("Enter the temperature in initial units: ");
    scanf("%lf", &temp);

    return temp;
}
// fahToCel() - converts from Fahrenheit to Celsius
// parameters: temperature in Fahrenheit, convertion ratio (fahCelRatio)
// returns: temperature in Celsius
double fahToCel(double tempF, double conRatio)
{
    // variable declaration
    double tempC;

    // computes conversion using conversion formula and ratio
    tempC = ((tempF - tempFreezeFah) * conRatio);

    return tempC;
}

// fahToKel() - converts from Fahrenheit to Kelvin
// parameters: temperature in Fahrenheit, convertion ratio (fahCelRatio)
// returns: temperature in Kelvin
double fahToKel(double tempF, double conRatio)
{
    // variable declaration
    double tempK;

    // computes conversion using conversion formula and ratio
    tempK = ((tempF - tempFreezeFah) * conRatio + tempFreezeKel);

    return tempK;
}

// celToFah() - converts from Celsius to Fahrenheit
// parameters: temperature in Celsius, conversion ratio (celFahRatio)
// returns: temperature in Fahrenheit
double celToFah(double tempC, double conRatio)
{
    // variable declaration
    double tempF;

    // computes conversion using conversion formula and ratio
    tempF = ((tempC * conRatio) + tempFreezeFah);

    return tempF;
}

// celToKel() - converts from Celsius to Kelvin
// parameters: temperature in Celsius
// returns: temperature in Kelvin
double celToKel(double tempC)
{
    // variable declaration
    double tempK;

    // computes conversion using conversion formula
    tempK = (tempC + tempFreezeKel);

    return tempK;
}

// kelToFah() - converts from Kelvin to Fahrenheit
// parameters: temperature in Kelvin, convertion ratio (celFahRatio)
// returns: temperature in Fahrenheit
double kelToFah(double tempK, double conRatio)
{
    // variable declaration
    double tempF;

    // computes conversion using conversion formula and ratio
    tempF = ((tempK - tempFreezeKel) * conRatio + tempFreezeFah);

    return tempF;
}

// kelToCel() - converts from Kelvin to Celsius
// parameters: temperature in Kelvin
// returns: temperature in Celsius
double kelToCel(double tempK)
{
    // variable declaration
    double tempC;

    // computes conversion using conversion formula
    tempC = (tempK - tempFreezeKel);

    return tempC;
}

/*
Expected Menu:
Convert from:
a) Fahrenheit to Celsius
b) Fahrenheit to Kelvin
c) Celsius to Fahrenheit
d) Celsius to Kelvin
e) Kelvin to Fahrenheit
f) Kelvin to Celsius
g) Exit program

Test Data 1:
Conversion: a
Temperature: 65.3

Expected Output:
65.3F converts to 18.5C

Test Data 2:
Conversion: b
Temperature: 14.5

Expected Output:
14.5F converts to 263.4K

Test Data 3:
Conversion: c
Temperature: -12.3

Expected Output:
-12.3C converts to 9.9F

Test Data 4:
Conversion: d
Temperature: 23

Expected Output:
23.0C converts to 296.2K

Test Data 5:
Conversion: e
Temperature: 241.7

Expected Output:
241.7K converts to -24.6F

Test Data 6:
Conversion: f
Temperature: 304

Expected Output:
304K converts to 30.9C

Test Data 7:
Conversion: g

Expected Output:
Results provided by Kyle Crisp, have a wonderful day.

Test Data 8:
Conversion: y

Expected Output:
That is not a valid selection, please enter a valid selection.
*/

/*
Program Menu Output:
Convert from:
a) Fahrenheit to Celsius
b) Fahrenheit to Kelvin
c) Celsius to Fahrenheit
d) Celsius to Kelvin
e) Kelvin to Fahrenheit
f) Kelvin to Celsius
g) Exit program

Program Output 1:
a
Enter the temperature in initial units: 65.3
65.3F converts to 18.5C

Program Output 2:
b
Enter the temperature in initial units: 14.5
14.5F converts to 263.4K

Program Output 3:
c
Enter the temperature in initial units: -12.3
-12.3C converts to 9.9F

Program Output 4:
d
Enter the temperature in initial units: 23
23.0C converts to 296.1K

Program Output 5:
e
Enter the temperature in initial units: 241.7
241.7K converts to -24.6F

Program Output 6:
f
Enter the temperature in initial units: 304
304.0K converts to 30.9C

Program Output 7:
g
Results provided by Kyle Crisp, have a wonderful day.

Program Output 8:
y
That is not a valid selection, please enter a valid selection.
