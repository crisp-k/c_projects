#include <stdio.h>
#include <math.h>
#include <ctype.h>

double computeArea(double length, double width, double radius, char shape);

int main()
{
    double length, width, area, radius;
    char shape;

    printf("Is the object a [s]quare, [r]ectangle or [c]ircle? ");
    scanf("%c", &shape);

    switch(tolower(shape))
    {
        case 's':

            printf("Enter length: ");
            scanf("%lf", &length);

            width = length;

            break;
        case 'r':

            printf("Enter length: ");
            scanf("%lf", &length);

            printf("Enter width: ");
            scanf("%lf", &width);

            break;
        case 'c':

            printf("Enter radius: ");
            scanf("%lf", &radius);

            break;
        default:

            printf("Invalid shape\n");

            break;
    }
    /*
    if(shape == 's')
    {
        printf("Enter length: ");
        scanf("%lf", &length);

        width = length;
    }
    else if(shape == 'r')
    {
        printf("Enter length: ");
        scanf("%lf", &length);

        printf("Enter width: ");
        scanf("%lf", &width);
    }
    else if(shape == 'c')
    {
        printf("Enter radius: ");
        scanf("%lf", &radius);
    }
    else
        printf("Invalid shape\n");
    */

    area = computeArea(length, width, radius, shape);
    if (shape == 's' || shape == 'r')
        printf("The area of a %.1lf by %.1lf region is equal to %.1lf", length, width, area);
    else if (shape == 'c')
        printf("The area with a radius of %.1lf is equal to %.1lf", radius, area);
    return 0;
}

double computeArea(double length, double width, double radius, char shape)
{
    double area;

    if (shape == 's' || shape == 'r')
        area = (length * width);
    else if(shape == 'c')
        area = (M_PI * radius * radius);

    return area;
}

/*
Test Data 1:
Length: 5
Width: 15

Expected Result:
Area: 75

Test Data 2:
Length: 5.43
Width: 7.65

Expected Result:
Area: 41.5

Test Data 3:
Length: 24.3
Width: 26

Expected Result:
Area: 631.8
*/

/*
Test Result 1:
Enter length: 5
Enter width: 15
The area of a 5.0 by 15.0 square is equal to 75.0

Test Result 2:
Enter length: 5.43
Enter width: 7.65
The area of a 5.4 by 7.7 square is equal to 41.5

Test Result 3:
Enter length: 24.3
Enter width: 26
The area of a 24.3 by 26.0 square is equal to 631.8
*/
