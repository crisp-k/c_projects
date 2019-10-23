// Program:	weatherStats
// Author:		Kyle Crisp
// Course:		COP2220C

#include <stdio.h>
#include <ctype.h>


// constant declaration
#define MAX_DAYS 30

// preprocessor function declarations
int displayWelcome(void);
int displayMenu(void);
double computeAverage(double temp[], const int numElements);
double computeTotal(double values[], const int numElements);
int highestDay(double values[], const int numElements);
double lowestDay(double *pntrLow, const int numElements);
int displayCredits(void);


int main(void)
{
    // variable declarations
    int highs[MAX_DAYS] = {91, 89, 90, 84, 97, 96, 97, 97, 96, 92, 90, 89, 88, 90, 88, 93, 96, 86, 84, 87, 87, 86, 87, 94, 96, 97, 93, 89, 89, 90};
    int lows[MAX_DAYS] =  {73, 77, 77, 73, 76, 72, 70, 71, 75, 73, 73, 73, 72, 73, 77, 72, 70, 72, 72, 71, 66, 67, 64, 64, 71, 73, 72, 68, 67, 71};
    double rainfall[MAX_DAYS] = {0.30, 0.07, 0.38, 0.59, 0.10, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00,
                                0.32, 0.01, 0.01, 0.27, 0.00, 0.00, 0.24, 0.06, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00};
    double dbleHighs[MAX_DAYS] = { };
    double dbleLows[MAX_DAYS] = { };
    int userChoice, dayRequested, atLeast, runProgram = 0;
    int index, highestValueIndex, lowestValueIndex;
    int userDaysFound, highDaysFound, lowDaysFound;
    double *pntrLow;

    // converts integer values from given arrays into
    // double values for future calculations
    for(index = 0; index <= MAX_DAYS - 1; index++)
        {
            dbleHighs[index] = highs[index];
            dbleLows[index] = lows[index];
        }

    while(runProgram == 0)
    {
        // resets days found variables back to 0
        highDaysFound = 0;
        lowDaysFound = 0;
        userDaysFound = 0;

        // call for display function
        displayWelcome();

        // calls for menu display function, assigns returned value as userChoice variable
        userChoice = displayMenu();

        switch(userChoice)
            {
                case 1:
                    {
                        // prompts the user to enter a day to search for
                        printf("\nWhich day would you like information for? [1-30] ");
                        scanf("\n%i", &dayRequested);

                        // displays corresponding information for desired day
                        printf("\nWeather information for day %i: \n\n", dayRequested);
                        printf("    Temperature High: %i\n", highs[dayRequested - 1]);
                        printf("    Temperature Low: %i\n", lows[dayRequested - 1]);
                        printf("    Rainfall: %.2lf\n", rainfall[dayRequested - 1]);

                        break;
                    }
                case 2:k
                    {
                        printf("\nInformation for day(s) with highest temperature: \n\n");

                        // call for highest day function
                        // grabs the index of the highest value to compare with other values
                        highestValueIndex = highestDay(dbleHighs, MAX_DAYS);

                        // loops through arrays and prints day information if highs match
                        for(index = 0; index <= MAX_DAYS - 1; index++)
                            {
                                if(dbleHighs[highestValueIndex] == dbleHighs[index])
                                    {
                                        // displays day, high, low, and rainfall
                                        printf("    Day: %i\n", index + 1);
                                        printf("    High Temperature: %i\n", highs[index]);
                                        printf("    Low Temperature: %i\n", lows[index]);
                                        printf("    Rainfall %.2lf\n\n", rainfall[index]);

                                        // accumulates how many days share the highest rainfall
                                        highDaysFound = highDaysFound + 1;
                                    }
                            }

                        // displays how many days were found with the highest temperature
                        printf("Days found with the highest temperature: %i\n", highDaysFound);

                        break;
                    }
                case 3:
                    {
                        // sets pointer to first value in lows array to compare with each other value
                        pntrLow = &dbleLows[0];

                        printf("\nInformation for day(s) with lowest temperature: \n\n");

                        // calls lowest day function
                        // grabs index of lowest value to compare with other days
                        lowestValueIndex = lowestDay(pntrLow, MAX_DAYS);

                        printf("Lowest temp %i\n", lows[lowestValueIndex]);

                        // loops through arrays and prints day information if lows match
                        for(index = 0; index <= MAX_DAYS - 1; index++)
                            {
                                if(dbleLows[lowestValueIndex] == dbleLows[index])
                                    {
                                        // displays day, high, low, and rainfall
                                        printf("    Day: %i\n", index + 1);
                                        printf("    High Temperature: %i\n", highs[index]);
                                        printf("    Low Temperature: %i\n", lows[index]);
                                        printf("    Rainfall %.2lf\n\n", rainfall[index]);

                                        // accumulates how many days share the lowest temperature
                                        lowDaysFound = lowDaysFound + 1;
                                    }
                            }

                        // displays how many days were found with the lowest temperature
                        printf("Days found with lowest temperature: %i\n", lowDaysFound);

                        break;
                    }
                case 4:
                    {
                        // prompts user for a high temperature to search for
                        printf("\nEnter a high temperature: ");
                        scanf("\n%i", &atLeast);

                        // reconfirms user's entered value
                        printf("\nDays that have at least a temperature of: %i\n\n", atLeast);

                        // searches through array and prints information for days that have
                        // at least the value entered by the user
                        for(index = 0; index <= MAX_DAYS - 1; index++)
                            {
                                if(highs[index] >= atLeast)
                                    {
                                        // displays day, high, low, and rainfall
                                        printf("    Day: %i\n", index + 1);
                                        printf("    High Temperature: %i\n", highs[index]);
                                        printf("    Low Temperature: %i\n", lows[index]);
                                        printf("    Rainfall %.2lf\n\n", rainfall[index]);

                                        // accumulates the amount of days found with at least the users value
                                        userDaysFound = userDaysFound + 1;
                                    }
                            }

                        // displays how many days were found with at least the value entered by the user
                        printf("Days found with a temperature of at least %i: %i\n\n", atLeast, userDaysFound);

                        break;
                    }
                case 5:
                    {
                        printf("\nInformation for day(s) with the most rainfall: \n\n");

                        // call for highest day function
                        // grabs the index of the highest value to compare with other values
                        highestValueIndex = highestDay(rainfall, MAX_DAYS);

                        // loops through arrays and prints day information if highs match
                        for(index = 0; index <= MAX_DAYS - 1; index++)
                            {
                                if(rainfall[highestValueIndex] == rainfall[index])
                                    {
                                        // displays day, high, low, and rainfall
                                        printf("    Day: %i\n", index + 1);
                                        printf("    High Temperature: %i\n", highs[index]);
                                        printf("    Low Temperature: %i\n", lows[index]);
                                        printf("    Rainfall %.2lf\n\n", rainfall[index]);

                                        // accumulates how many days share the highest temperature
                                        highDaysFound = highDaysFound + 1;
                                    }
                            }

                        // displays how many days were found with the highest rainfall
                        printf("Days found with the highest rainfall: %i\n", highDaysFound);

                        break;
                    }
                case 6:
                    {
                        // calls for average high function
                        double averageHigh = computeAverage(dbleHighs, MAX_DAYS);

                        // calls for average low function
                        double averageLow = computeAverage(dbleLows, MAX_DAYS);

                        // calls for total rainfall function
                        double totalRainfall = computeTotal(rainfall, MAX_DAYS);

                        // displays acquired values from functions
                        // average high, low, and total rainfall for month
                        printf("\nAverage high, low, and total rainfall for this month:\n\n");
                        printf("    Average High: %.2lf\n", averageHigh);
                        printf("    Average Low: %.2lf\n", averageLow);
                        printf("    Total Rainfall: %.2lf\n", totalRainfall);

                        break;
                    }
                case 9:
                    {
                        // exits the switch statement
                        // displays end credit
                        displayCredits();
                        break;
                    }
                default:
                    {
                        // restarts the program if the user does not enter a valid option
                        printf("\nThat choice is not valid. Please enter a valid choice.\n");
                        break;
                    }



            }
        // fully closes loop and ends the program
        if(userChoice == 9)
            break;

    }
    return 0;
}

// displayWelcome()
// no parameters, returns nothing
int displayWelcome(void)
{
    // displays welcome statement
    printf("\nWelcome to Kyle Crisp's weather stats program.\n\n");

    return 0;
}

// displayMenu()
// no parameters, returns users choice
// displays menu, and prompts user for input
int displayMenu(void)
{
    // variable declaration
    int userChoice;

    // displays menu for user
    printf("1) Display weather information for a specific day\n");
    printf("2) Display weather information for day(s) with highest temperature(s)\n");
    printf("3) Display weather information for day(s) with the lowest temperature(s)\n");
    printf("4) Display weather information using specified high temperature\n");
    printf("5) Display weather information for day with highest rainfall\n");
    printf("6) Display average high, low, and total rainfall for the month\n");
    printf("9) Exit the program.\n\n");
    scanf("\n%i", &userChoice);


    return userChoice;
}

// computeAverage()
// paremeters: temperature arrays, number of elements
// returns average
double computeAverage(double temp[], const int numElements)
{
    // variable declaration
    double average, total = 0;
    int index;

    //  for loop to total each value in array
    for(index = 0; index <= numElements - 1; index++)
        {
            // adds temp in array to total
            total = total + temp[index];
        }

    // average computation
    average = total / numElements;

    return average;
}

// computeTotal()
// parameters: arrays containing temperatures and rainfall, and number of elements
// returns total
double computeTotal(double values[], const int numElements)
{
    // variable declaration
    double total = 0;
    int index;

    // for loop to step through arrays and total values
    for(index = 0; index <= numElements - 1; index++)
        {
            // adds value in array to total
            total = total + values[index];
        }

    return total;
}

// highestDay()
// parameters: arrays containing temperatures and rainfall, and number of elements
// returns index of the highest value in the array
int highestDay(double values[], const int numElements)
{
    // variable declaration
    int index, highestIndex;
    double highest = values[0];

    // loops through index
    for(index = 0; index <= numElements - 1; index++)
        {
            // compares current highest with a value in array
            // if value in array is higher, a new highest value is set
            if (highest < values[index])
                {
                    highest = values[index];
                    // saves index of new highest value
                    highestIndex = index;
                }
        }

    return highestIndex;
}

// lowestDay()
// parameters: pointer to dbleLows array, and number of elements
// returns index of day with the lowest temperature
double lowestDay(double *pntrLow, const int numElements)
{
    // variable declaration
    int index, lowestIndex;
    double lowest;

    // sets lowest value to first value in array
    lowest = *pntrLow;

    // loops through index
    for(index = 0; index <= numElements - 1; index++)
        {
            // compares current lowest with next in array; using pointer notation
            // if value in array is lower, a new lowest value is set
            if(lowest > *(pntrLow + index))
                {
                    lowest = *(pntrLow + index);
                    // saves index of new lowest value
                    lowestIndex = index;
                }
        }

    return lowestIndex;
}

// displayCredits()
// parameters: none; returns nothing
// displays ending credits
int displayCredits(void)
    {
        // displays end credit
        printf("\nResults provided by Kyle Crisp.\n\n");

        return 0;
    }

/*
Test Data 0:

Program menu boot up test:

Expected Display:

Welcome to Kyle Crisp's weather stats program.

1) Display weather information for a specific day
2) Display weather information for day(s) with highest temperature(s)
3) Display weather information for day(s) with the lowest temperature(s)
4) Display weather information using specified high temperature
5) Display weather information for day with highest rainfall
6) Display average high, low, and total rainfall for the month
9) Exit the program.


Test Data 1:
Menu Option: 1
Specific Day: *14*

Expected Output:

Which day would you like information for? [1-30] *14*

Weather information for day 14:

    Temperature High: 90
    Temperature Low: 73
    Rainfall: 0.01


Test Data 2:
Menu Option: 2

Expected Output:

Information for day(s) with highest temperature:

    Day: 5
    High Temperature: 97
    Low Temerature: 76
    Rainfall: 0.10

    Day: 7
    High Temperature: 97
    Low Temerature: 70
    Rainfall: 0.00

    Day: 8
    High Temperature: 97
    Low Temerature: 71
    Rainfall: 0.00

    Day: 26
    High Temperature: 97
    Low Temerature: 73
    Rainfall: 0.00

    Days found with highest temperature: 4


Test Data 3:
Menu Option: 3

Expected Output:

Information for day(s) with lowest temperature:

    Day: 23
    High Temperature: 87
    Low Temerature: 64
    Rainfall: 0.00

    Day: 24
    High Temperature: 94
    Low Temerature: 64
    Rainfall: 0.00

Days found with lowest temperature: 2


Test Data 4:
Menu Option: 4
Specified high temperature: *95*

Expected Output:

Enter a high temperature: *95*

Days that have at least a temperature of: 95

    Day: 5
    High Temperature: 97
    Low Temerature: 76
    Rainfall: 0.10

    Day: 6
    High Temperature: 96
    Low Temerature: 72
    Rainfall: 0.00

    Day: 7
    High Temperature: 97
    Low Temerature: 70
    Rainfall: 0.00

    Day: 8
    High Temperature: 97
    Low Temerature: 71
    Rainfall: 0.00

    Day: 9
    High Temperature: 96
    Low Temerature: 75
    Rainfall: 0.00

    Day: 17
    High Temperature: 96
    Low Temerature: 70
    Rainfall: 0.00

    Day: 25
    High Temperature: 96
    Low Temerature: 71
    Rainfall: 0.00

    Day: 26
    High Temperature: 97
    Low Temerature: 73
    Rainfall: 0.00

Days found with a temperature of at least 95: 8


Test Data 5:
Menu Option: 5

Expected Output:

Information for day(s) with the most rainfall:

    Day: 4
    High Temperature: 84
    Low Temerature: 73
    Rainfall: 0.59

Days found with the highest rainfall: 1


Test Data 6:
Menu Option: 6

Expected Output:

Average high, low, and total rainfall for this month:

    Average High: 90.93
    Average Low: 71.50
    Total Rainfall: 2.35


Test Data 7:
Menu Option: 8

Expected Output:

That choice is not valid. Please enter a valid choice.


Test Data 8:
Menu Option: 9

Expected Output:

Results provided by Kyle Crisp.


Sample Data 0:

Welcome to Kyle Crisp's weather stats program.

1) Display weather information for a specific day
2) Display weather information for day(s) with highest temperature(s)
3) Display weather information for day(s) with the lowest temperature(s)
4) Display weather information using specified high temperature
5) Display weather information for day with highest rainfall
6) Display average high, low, and total rainfall for the month
9) Exit the program.


Sample Data 1:

Which day would you like information for? [1-30] 14

Weather information for day 14:

    Temperature High: 90
    Temperature Low: 73
    Rainfall: 0.01


Sample Data 2:

Information for day(s) with highest temperature:

    Day: 5
    High Temperature: 97
    Low Temerature: 76
    Rainfall 0.10

    Day: 7
    High Temperature: 97
    Low Temerature: 70
    Rainfall 0.00

    Day: 8
    High Temperature: 97
    Low Temerature: 71
    Rainfall 0.00

    Day: 26
    High Temperature: 97
    Low Temerature: 73
    Rainfall 0.00

Days found with the highest temperature: 4


Sample Data 3:

Information for day(s) with lowest temperature:

Lowest temp 64
    Day: 23
    High Temperature: 87
    Low Temerature: 64
    Rainfall 0.00

    Day: 24
    High Temperature: 94
    Low Temerature: 64
    Rainfall 0.00

Days found with lowest temperature: 2

Sample Data 4:

Enter a high temperature: 95

Days that have at least a temperature of: 95

    Day: 5
    High Temperature: 97
    Low Temerature: 76
    Rainfall 0.10

    Day: 6
    High Temperature: 96
    Low Temerature: 72
    Rainfall 0.00

    Day: 7
    High Temperature: 97
    Low Temerature: 70
    Rainfall 0.00

    Day: 8
    High Temperature: 97
    Low Temerature: 71
    Rainfall 0.00

    Day: 9
    High Temperature: 96
    Low Temerature: 75
    Rainfall 0.00

    Day: 17
    High Temperature: 96
    Low Temerature: 70
    Rainfall 0.00

    Day: 25
    High Temperature: 96
    Low Temerature: 71
    Rainfall 0.00

    Day: 26
    High Temperature: 97
    Low Temerature: 73
    Rainfall 0.00

Days found with a temperature of at least 95: 8


Sample Data 5:

Information for day(s) with the most rainfall:

    Day: 4
    High Temperature: 84
    Low Temerature: 73
    Rainfall 0.59

Days found with the highest rainfall: 1


Sample Data 6:

Average high, low, and total rainfall for this month:

    Average High: 90.93
    Average Low: 71.50
    Total Rainfall: 2.35


Sample Data 7:

That choice is not valid. Please enter a valid choice.


Sample Data 8:

Results provided by Kyle Crisp.
*/
