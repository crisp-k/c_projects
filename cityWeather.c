// Program:	cityWeather
// Author:		Kyle Crisp
// Course:		COP2220C

#include <stdio.h>
#include <string.h>


#define NUM_CITIES 51
#define LEN_CITY 30
#define LEN_STATE 2

int displayWelcome(void);
int displayMenu(void);
int highestValue(double values[], const int numElements);
double lowestValue(double *pntrLow, const int numElements);
double computeAverage(double temp[], const int numElements);
int displayCredits(void);

int main(void)
{
    // variable declaration
    int highs[NUM_CITIES] = {72, 80, 65, 74, 59, 56, 71, 59, 65, 60, 63, 77, 64, 59, 61, 80, 63, 79, 66, 80, 75, 68, 73,
                    84, 56, 55, 70, 78, 62, 72, 83, 65, 87, 61, 63, 61, 72, 70, 81, 57, 74, 64, 80, 70, 64, 71, 61, 66, 82, 68, 67};
    int lows[NUM_CITIES] = {53, 59, 45, 53, 44, 40, 49, 41, 43, 43, 44, 57, 36, 42, 40, 60, 44, 58, 48, 59, 56, 49, 54, 70,
                    40, 37, 49, 61, 48, 51, 63, 47, 63, 42, 45, 43, 50, 48, 53, 39, 48, 42, 59, 58, 51, 50, 46, 48, 65, 52, 50};
    char cities[NUM_CITIES][LEN_CITY + 1] = {"Atlanta", "Austin", "Baltimore", "Birmingham", "Boston", "Buffalo", "Charlotte",
                    "Chicago", "Cincinnati", "Cleveland", "Columbus", "Dallas", "Denver", "Detroit", "Hartford", "Houston", "Indianapolis",
                    "Jacksonville", "Kansas City", "Las Vegas", "Los Angeles", "Louisville", "Memphis", "Miami", "Milwaukee", "Minneapolis",
                    "Nashville", "New Orleans", "New York", "Oklahoma City", "Orlando", "Philadelphia", "Phoenix", "Pittsburgh", "Portland",
                    "Providence", "Raleigh", "Richmond", "Riverside", "Rochester", "Sacramento", "Salt Lake City", "San Antonio", "San Diego",
                    "San Francisco", "San Jose", "Seattle", "St. Louis", "Tampa", "Virginia Beach", "Washington"};
    char states[NUM_CITIES][LEN_STATE + 1] = {"GA", "TX", "MD", "AL", "MA", "NY", "NC", "IL", "OH", "OH", "OH", "TX", "CO", "MI", "CT",
                    "TX", "IN", "FL", "MO", "NV", "CA", "KY", "TN", "FL", "WI", "MN", "TN", "LA", "NY", "OK", "FL", "PA", "AZ", "PA", "OR",
                    "RI", "NC", "VA", "CA", "NY", "CA", "UT", "TX", "CA", "CA", "CA", "WA", "MO", "FL", "VA", "DC"};
    char citySearch[NUM_CITIES + 1], stateSearch[NUM_CITIES + 1], *pntr;
    double dbleHighs[NUM_CITIES] = { };
    double dbleLows[NUM_CITIES] = { };
    double *pntrLow, averageHigh, averageLow;
    int index, *userPntr, userChoice, runProgram = 0;
    int highestValueIndex, lowestValueIndex;


    // converts integer values from given arrays into
    // double values for future calculations
    for(index = 0; index < NUM_CITIES; index++)
        {
            dbleHighs[index] = highs[index];
            dbleLows[index] = lows[index];
        }

    // displays welcome message
    displayWelcome();


    while(runProgram == 0)
        {
            // resets accumulators to 0 within loop
            int highsFound = 0;
            int lowsFound = 0;

            // calls menu display function and prompts user for choice
            userChoice = displayMenu();

            // switch statement for each possible choice

            switch(userChoice)
                {
                    case 1:
                        {
                            printf("\nInformation for city/cities with the highest temperature: \n\n");

                            // call for highest value function
                            // grabs the index of the highest value to compare with other values
                            highestValueIndex = highestValue(dbleHighs, NUM_CITIES);

                            // loops through arrays and prints city information if highs match
                            for(index = 0; index < NUM_CITIES; index++)
                                {
                                    if(dbleHighs[highestValueIndex] == dbleHighs[index])
                                        {
                                            // displays city, state, high, and low
                                            printf("    City: %s\n", cities[index]);
                                            printf("    State: %s\n", states[index]);
                                            printf("    High Temperature: %i\n", highs[index]);
                                            printf("    Low Temperature: %i\n", lows[index]);

                                            // accumulates how many cities share the highest temperature
                                            highsFound = highsFound + 1;
                                        }
                                }

                            // displays how many cities were found with the highest temperature
                            printf("\nCities found with the highest temperature: %i\n\n", highsFound);

                            break;
                        }
                    case 2:
                        {
                            // sets pointer to first value in lows array to compare with each other value
                            pntrLow = &dbleLows[0];

                            printf("\nInformation for city/cities with the lowest temperature: \n\n");

                            // calls lowest value function
                            // grabs index of lowest value to compare with other values
                            lowestValueIndex = lowestValue(pntrLow, NUM_CITIES);

                            // loops through arrays and prints city information if lows match
                            for(index = 0; index < NUM_CITIES; index++)
                                {
                                    if(dbleLows[lowestValueIndex] == dbleLows[index])
                                        {
                                            // displays city, state, high, and low
                                            printf("    City: %s\n", cities[index]);
                                            printf("    State: %s\n", states[index]);
                                            printf("    High Temperature: %i\n", highs[index]);
                                            printf("    Low Temperature: %i\n", lows[index]);

                                            // accumulates how many cities share the lowest temperature
                                            lowsFound = lowsFound + 1;
                                        }
                                }

                            // displays how many cities were found with the lowest temperature
                            printf("\nCities found with the lowest temperature: %i\n\n", lowsFound);

                            break;
                        }
                    case 3:
                        {
                            // calls average computation function
                            averageHigh = computeAverage(dbleHighs, NUM_CITIES);

                            // displays average of highs
                            printf("\nAverage of highs: %.2lf\n\n", averageHigh);

                            break;
                        }
                    case 4:
                        {
                            // calls average computation function
                            averageLow = computeAverage(dbleLows, NUM_CITIES);

                            // displays average of lows
                            printf("\nAverage of lows: %.2lf\n\n", averageLow);

                            break;
                        }
                    case 5:
                        {
                            // clears the input buffer
                            while ((getchar()) != '\n');

                            // prompts user to search for a city
                            printf("\nEnter a city to search for: ");
                            fgets(citySearch, LEN_CITY, stdin);

                            // searches string for newline character
                            pntr = strchr(citySearch, '\n');

                            // if newline character is found, it is set to an end string character
                            // else the buffer is cleared
                            if (pntr != NULL)
                                {
                                    *pntr = '\0';
                                }
                            else
                                {
                                    fflush(stdin);
                                }

                            // compares citySearch to each city in array, if match is found
                            // information is printed, or an error is thrown
                            for(index = 0; index < NUM_CITIES; index++)
                                {
                                    if (strstr(cities[index], citySearch) != 0)
                                        {
                                            // displays city, state, high, and low
                                            printf("\n    City: %s\n", cities[index]);
                                            printf("    State: %s\n", states[index]);
                                            printf("    High Temperature: %i\n", highs[index]);
                                            printf("    Low Temperature: %i\n\n", lows[index]);
                                        }
                                    else
                                        {
                                            printf("\nThat choice is not valid. Please enter a valid choice.\n\n");
                                            break;
                                        }
                                }

                            break;
                        }
                    case 6:
                        {
                            // clears the input buffer
                            while ((getchar()) != '\n');

                            // prompts user for state to search for
                            printf("\nEnter a state to search for: ");
                            fgets(stateSearch, LEN_STATE + 1, stdin);

                            // searches string for newline character
                            pntr = strchr(stateSearch, '\n');

                            // if newline character is found it is set to end string
                            // else the buffer is cleared
                            if (pntr != NULL)
                                {
                                    *pntr = '\0';
                                }
                            else
                                {
                                    fflush(stdin);
                                }

                            // compares stateSearch to each state in array, if match is found
                            // information is printed, else error is thrown
                            for(index = 0; index < NUM_CITIES; index++)
                                {
                                    if (strcmp(stateSearch, states[index]) == 0)
                                        {
                                            // displays city, state, high, and low
                                            printf("\n    City: %s\n", cities[index]);
                                            printf("    State: %s\n", states[index]);
                                            printf("    High Temperature: %i\n", highs[index]);
                                            printf("    Low Temperature: %i\n\n", lows[index]);
                                        }
                                    else
                                        {
                                            printf("\nThat choice is not valid. Please enter a valid choice.\n\n");
                                            break;
                                        }
                                }

                            break;

                        }
                    case 7:
                        {
                            printf("Information for all cities: \n");

                            // loops through arrays and prints corresponding information for each city
                            for(index = 0; index < NUM_CITIES; index++)
                                {
                                    // displays city, state, high, and low
                                    printf("\n    City: %s\n", cities[index]);
                                    printf("    State: %s\n", states[index]);
                                    printf("    High Temperature: %i\n", highs[index]);
                                    printf("    Low Temperature: %i\n", lows[index]);
                                }

                            break;
                        }
                    case 8:
                        {
                            // exits the switch statement
                            displayCredits();

                            break;
                        }

                    default:
                        {
                            // restarts the program if the user does not enter a valid option
                            printf("\nThat choice is not valid. Please enter a valid choice.\n\n");
                            break;
                        }

            }

            if(userChoice == 8)
                break;
        }
    return 0;
}


// displayWelcome()
// no parameters, returns nothing
int displayWelcome(void)
{
    // displays welcome statement
    printf("\nWelcome to Kyle Crisp's City-Weather program.\n\n");

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
    printf("1) Display weather information for city/cities with the highest temperature\n");
    printf("2) Display weather information for city/cities with the lowest temperature\n");
    printf("3) Display the average of the highs\n");
    printf("4) Display the average of the lows\n");
    printf("5) Search by city and display weather information\n");
    printf("6) Search by state and display weather information\n");
    printf("7) Display weather information for all cities\n");
    printf("8) Exit\n\n");
    scanf("\n%i", &userChoice);


    return userChoice;
}

// highestDay()
// parameters: arrays containing temperature, and number of elements
// returns index of the highest value in the array
int highestValue(double values[], const int numElements)
{
    // variable declaration
    int index, highestIndex;
    double highest = values[0];

    // loops through index
    for(index = 0; index < numElements; index++)
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
// returns index of the lowest value in the array
int lowestValue(double *pntrLow, const int numElements)
{
    // variable declaration
    int index, lowestIndex;
    double lowest;

    // sets lowest value to first value in array
    lowest = *pntrLow;

    // loops through index
    for(index = 0; index < numElements; index++)
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

// computeAverage()
// paremeters: temperature arrays, number of elements
// returns average
double computeAverage(double temp[], const int numElements)
{
    // variable declaration
    double average, total = 0;
    int index;

    //  for loop to total each value in array
    for(index = 0; index < numElements; index++)
        {
            // adds temp in array to total
            total = total + temp[index];
        }

    // average computation
    average = total / numElements;

    return average;
}

// displayCredits()
// parameters: none; returns nothing
// display ending credits
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

Welcome to Kyle Crisp's City-Weather program.

1) Display weather information for city/cities with the highest temperature
2) Display weather information for city/cities with the lowest temperature
3) Display the average of the highs
4) Display the average of the lows
5) Search by city and display weather information
6) Search by state and display weather information
7) Display weather information for all cities
8) Exit


Test Data 1:
Menu Option: 1

Expected Output:

Information for city/cities with the highest temperature:

    City: Phoenix
    State: AZ
    High Temperature: 87
    Low Temperature: 63

Cities found with the highest temperature: 1

Test Data 2:
Menu Option: 2

Expected Output:

Information for city/cities with the lowest temperature:

    City: Denver
    State: CO
    High Temperature: 64
    Low Temperature: 36

Cities found with the lowest temperature: 1


Test Data 3:
Menu Option: 3

Expected Output:

Average of highs: 68.88


Test Data 4:
Menu Option: 4

Average of lows: 49.71


Test Data 5:
Menu Option: 5
Input: Seattle

Expected Output:

Enter a city to search for: *Seattle*

    City: Seattle
    State: WA
    High Temperature: 61
    Low Temperature: 46


Test Data 6:
Menu Option: 6
Input: TX

Expected Output:

Enter a state to search for: *TX*

    City: Austin
    State: TX
    High Temperature: 80
    Low Temperature: 59


    City: Dallas
    State: TX
    High Temperature: 77
    Low Temperature: 57


    City: Houston
    State: TX
    High Temperature: 80
    Low Temperature: 60


    City: San Antonio
    State: TX
    High Temperature: 80
    Low Temperature: 59


Test Data 7:
Menu Option: 7

Expected Output:

    City: Atlanta
    State: GA
    High Temperature: 72
    Low Temperature: 53

    City: Austin
    State: TX
    High Temperature: 80
    Low Temperature: 59

    City: Baltimore
    State: MD
    High Temperature: 65
    Low Temperature: 45

    City: Birmingham
    State: AL
    High Temperature: 74
    Low Temperature: 53

    City: Boston
    State: MA
    High Temperature: 59
    Low Temperature: 44

    City: Buffalo
    State: NY
    High Temperature: 56
    Low Temperature: 40

    City: Charlotte
    State: NC
    High Temperature: 71
    Low Temperature: 49

    City: Chicago
    State: IL
    High Temperature: 59
    Low Temperature: 41

    City: Cincinnati
    State: OH
    High Temperature: 65
    Low Temperature: 43

    City: Cleveland
    State: OH
    High Temperature: 60
    Low Temperature: 43

    City: Columbus
    State: OH
    High Temperature: 63
    Low Temperature: 44

    City: Dallas
    State: TX
    High Temperature: 77
    Low Temperature: 57

    City: Denver
    State: CO
    High Temperature: 64
    Low Temperature: 36

    City: Detroit
    State: MI
    High Temperature: 59
    Low Temperature: 42

    City: Hartford
    State: CT
    High Temperature: 61
    Low Temperature: 40

    City: Houston
    State: TX
    High Temperature: 80
    Low Temperature: 60

    City: Indianapolis
    State: IN
    High Temperature: 63
    Low Temperature: 44

    City: Jacksonville
    State: FL
    High Temperature: 79
    Low Temperature: 58

    City: Kansas City
    State: MO
    High Temperature: 66
    Low Temperature: 48

    City: Las Vegas
    State: NV
    High Temperature: 80
    Low Temperature: 59

    City: Los Angeles
    State: CA
    High Temperature: 75
    Low Temperature: 56

    City: Louisville
    State: KY
    High Temperature: 68
    Low Temperature: 49

    City: Memphis
    State: TN
    High Temperature: 73
    Low Temperature: 54

    City: Miami
    State: FL
    High Temperature: 84
    Low Temperature: 70

    City: Milwaukee
    State: WI
    High Temperature: 56
    Low Temperature: 40

    City: Minneapolis
    State: MN
    High Temperature: 55
    Low Temperature: 37

    City: Nashville
    State: TN
    High Temperature: 70
    Low Temperature: 49

    City: New Orleans
    State: LA
    High Temperature: 78
    Low Temperature: 61

    City: New York
    State: NY
    High Temperature: 62
    Low Temperature: 48

    City: Oklahoma City
    State: OK
    High Temperature: 72
    Low Temperature: 51

    City: Orlando
    State: FL
    High Temperature: 83
    Low Temperature: 63

    City: Philadelphia
    State: PA
    High Temperature: 65
    Low Temperature: 47

    City: Phoenix
    State: AZ
    High Temperature: 87
    Low Temperature: 63

    City: Pittsburgh
    State: PA
    High Temperature: 61
    Low Temperature: 42

    City: Portland
    State: OR
    High Temperature: 63
    Low Temperature: 45

    City: Providence
    State: RI
    High Temperature: 61
    Low Temperature: 43

    City: Raleigh
    State: NC
    High Temperature: 72
    Low Temperature: 50

    City: Richmond
    State: VA
    High Temperature: 70
    Low Temperature: 48

    City: Riverside
    State: CA
    High Temperature: 81
    Low Temperature: 53

    City: Rochester
    State: NY
    High Temperature: 57
    Low Temperature: 39

    City: Sacramento
    State: CA
    High Temperature: 74
    Low Temperature: 48

    City: Salt Lake City
    State: UT
    High Temperature: 64
    Low Temperature: 42

    City: San Antonio
    State: TX
    High Temperature: 80
    Low Temperature: 59

    City: San Diego
    State: CA
    High Temperature: 70
    Low Temperature: 58

    City: San Francisco
    State: CA
    High Temperature: 64
    Low Temperature: 51

    City: San Jose
    State: CA
    High Temperature: 71
    Low Temperature: 50

    City: Seattle
    State: WA
    High Temperature: 61
    Low Temperature: 46

    City: St. Louis
    State: MO
    High Temperature: 66
    Low Temperature: 48

    City: Tampa
    State: FL
    High Temperature: 82
    Low Temperature: 65

    City: Virginia Beach
    State: VA
    High Temperature: 68
    Low Temperature: 52

    City: Washington
    State: DC
    High Temperature: 67
    Low Temperature: 50


Test Data 8:
Menu Option: 9

Expected Output:

That choice is not valid. Please enter a valid choice.


Test Data 9:
Menu Option: 8

Expected Output:

Results provided by Kyle Crisp.


Sample Data 0:

Welcome to Kyle Crisp's City-Weather program.

1) Display weather information for city/cities with the highest temperature
2) Display weather information for city/cities with the lowest temperature
3) Display the average of the highs
4) Display the average of the lows
5) Search by city and display weather information
6) Search by state and display weather information
7) Display weather information for all cities
8) Exit


Sample Data 1:

Information for city/cities with the highest temperature:

    City: Phoenix
    State: AZ
    High Temperature: 87
    Low Temperature: 63

Cities found with the highest temperature: 1


Sample Data 2:

Information for city/cities with the lowest temperature:

    City: Denver
    State: CO
    High Temperature: 64
    Low Temperature: 36

Cities found with the lowest temperature: 1


Sample Data 3:

Average of highs: 68.88


Sample Data 4:

Average of lows: 49.71


Sample Data 5:

    City: Seattle
    State: WA
    High Temperature: 61
    Low Temperature: 46


Sample Data 6:

    City: Austin
    State: TX
    High Temperature: 80
    Low Temperature: 59


    City: Dallas
    State: TX
    High Temperature: 77
    Low Temperature: 57


    City: Houston
    State: TX
    High Temperature: 80
    Low Temperature: 60


    City: San Antonio
    State: TX
    High Temperature: 80
    Low Temperature: 59


Sample Data 7:


    City: Atlanta
    State: GA
    High Temperature: 72
    Low Temperature: 53

    City: Austin
    State: TX
    High Temperature: 80
    Low Temperature: 59

    City: Baltimore
    State: MD
    High Temperature: 65
    Low Temperature: 45

    City: Birmingham
    State: AL
    High Temperature: 74
    Low Temperature: 53

    City: Boston
    State: MA
    High Temperature: 59
    Low Temperature: 44

    City: Buffalo
    State: NY
    High Temperature: 56
    Low Temperature: 40

    City: Charlotte
    State: NC
    High Temperature: 71
    Low Temperature: 49

    City: Chicago
    State: IL
    High Temperature: 59
    Low Temperature: 41

    City: Cincinnati
    State: OH
    High Temperature: 65
    Low Temperature: 43

    City: Cleveland
    State: OH
    High Temperature: 60
    Low Temperature: 43

    City: Columbus
    State: OH
    High Temperature: 63
    Low Temperature: 44

    City: Dallas
    State: TX
    High Temperature: 77
    Low Temperature: 57

    City: Denver
    State: CO
    High Temperature: 64
    Low Temperature: 36

    City: Detroit
    State: MI
    High Temperature: 59
    Low Temperature: 42

    City: Hartford
    State: CT
    High Temperature: 61
    Low Temperature: 40

    City: Houston
    State: TX
    High Temperature: 80
    Low Temperature: 60

    City: Indianapolis
    State: IN
    High Temperature: 63
    Low Temperature: 44

    City: Jacksonville
    State: FL
    High Temperature: 79
    Low Temperature: 58

    City: Kansas City
    State: MO
    High Temperature: 66
    Low Temperature: 48

    City: Las Vegas
    State: NV
    High Temperature: 80
    Low Temperature: 59

    City: Los Angeles
    State: CA
    High Temperature: 75
    Low Temperature: 56

    City: Louisville
    State: KY
    High Temperature: 68
    Low Temperature: 49

    City: Memphis
    State: TN
    High Temperature: 73
    Low Temperature: 54

    City: Miami
    State: FL
    High Temperature: 84
    Low Temperature: 70

    City: Milwaukee
    State: WI
    High Temperature: 56
    Low Temperature: 40

    City: Minneapolis
    State: MN
    High Temperature: 55
    Low Temperature: 37

    City: Nashville
    State: TN
    High Temperature: 70
    Low Temperature: 49

    City: New Orleans
    State: LA
    High Temperature: 78
    Low Temperature: 61

    City: New York
    State: NY
    High Temperature: 62
    Low Temperature: 48

    City: Oklahoma City
    State: OK
    High Temperature: 72
    Low Temperature: 51

    City: Orlando
    State: FL
    High Temperature: 83
    Low Temperature: 63

    City: Philadelphia
    State: PA
    High Temperature: 65
    Low Temperature: 47

    City: Phoenix
    State: AZ
    High Temperature: 87
    Low Temperature: 63

    City: Pittsburgh
    State: PA
    High Temperature: 61
    Low Temperature: 42

    City: Portland
    State: OR
    High Temperature: 63
    Low Temperature: 45

    City: Providence
    State: RI
    High Temperature: 61
    Low Temperature: 43

    City: Raleigh
    State: NC
    High Temperature: 72
    Low Temperature: 50

    City: Richmond
    State: VA
    High Temperature: 70
    Low Temperature: 48

    City: Riverside
    State: CA
    High Temperature: 81
    Low Temperature: 53

    City: Rochester
    State: NY
    High Temperature: 57
    Low Temperature: 39

    City: Sacramento
    State: CA
    High Temperature: 74
    Low Temperature: 48

    City: Salt Lake City
    State: UT
    High Temperature: 64
    Low Temperature: 42

    City: San Antonio
    State: TX
    High Temperature: 80
    Low Temperature: 59

    City: San Diego
    State: CA
    High Temperature: 70
    Low Temperature: 58

    City: San Francisco
    State: CA
    High Temperature: 64
    Low Temperature: 51

    City: San Jose
    State: CA
    High Temperature: 71
    Low Temperature: 50

    City: Seattle
    State: WA
    High Temperature: 61
    Low Temperature: 46

    City: St. Louis
    State: MO
    High Temperature: 66
    Low Temperature: 48

    City: Tampa
    State: FL
    High Temperature: 82
    Low Temperature: 65

    City: Virginia Beach
    State: VA
    High Temperature: 68
    Low Temperature: 52

    City: Washington
    State: DC
    High Temperature: 67
    Low Temperature: 50


Sample Data 8:

That choice is not valid. Please enter a valid choice.


Sample Data 9:

Results provided by Kyle Crisp.

*/
