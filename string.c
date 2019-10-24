#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LEN_NAME 30

char *toLower(char str[], const int numChar);
char *toUpper(char str[], const int numChar);
char *titleCase(char str[], const int numChar);

int main(void)
    {
        // variable declaration
        char firstName[LEN_NAME + 1], lastName[LEN_NAME + 1], fullName[LEN_NAME + 1];
        char *ptr;
        size_t len;
        int result;



        // gets first name
        printf("Enter your first name: ");
        fgets(firstName, LEN_NAME, stdin);

        // replaces new line character with a string end character if one is found
        ptr = strchr(firstName, '\n');

        if (ptr != NULL)
        {
            *ptr = '\0';
        }
        else
        {
            fflush(stdin);
        }

        // copies first name over to fullName array
        strcpy(fullName, firstName);

        // displays first name from fullName array
        printf("Your first name is: %s\n", fullName);

        // gets last name
        printf("\nEnter your last name: ");
        fgets(lastName, LEN_NAME, stdin);

        // replaces new line character with a string end character if one is found
        ptr = strchr(lastName, '\n');
        if (ptr != NULL)
        {
            *ptr = '\0';
        }

        // adds space, then last name to fullName arrays
        strcat(fullName, " ");
        strcat(fullName, lastName);

        // counts characters in string
        len = strlen(fullName);

        result = strcmp(firstName, lastName);

        // prints final full name and length of fullName array
        printf("Your full name is %s\n", fullName);
        printf("Your name is %i characters long\n", len);

        printf("The result of comparing %s to %s is %i\n", firstName, lastName, result);

        printf("Now uppercase is %s\n", toUpper(firstName, LEN_NAME));
        printf("Now lowercase is %s\n", toLower(lastName, LEN_NAME));
        printf("Now title case is %s %s \n", titleCase(firstName, LEN_NAME), titleCase(lastName, LEN_NAME));

        return 0;
    }


char *toUpper(char str[], const int numChar)
{
    int index;


    for(index = 0; index < numChar; index++)
    {
        str[index] = toupper(str[index]);
    }


    return str;
}



char *toLower(char str[], const int numChar)
{
    int index;

    for(index = 0; index < numChar; index++)
    {
        str[index] = tolower(str[index]);
    }

    return str;
}

char *titleCase(char str[], const int numChar)
{
    int index;

    for(index = 0; index < numChar; index++)
    {
        str[index] = tolower(str[index]);
    }

    str[0] = toupper(str[0]);

    return str;
}
