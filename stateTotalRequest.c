#include <stdio.h>
#include <string.h>


#define NUM_CITIES 51
#define LEN_CITY 30
#define LEN_STATE 2

int main(void)
{
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
    char stateSearch[NUM_CITIES + 1];
    char *pntr;
    int index;

    printf("\nEnter a state to search for: ");
    fgets(stateSearch, LEN_STATE + 1, stdin);

    pntr = strchr(stateSearch, '\n');

    if (pntr != NULL)
        {
            *pntr = '\0';
        }
    else
        {
            fflush(stdin);
        }


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
        }

    return 0;
}
