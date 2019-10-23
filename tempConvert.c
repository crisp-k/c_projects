// Program:	tempConvert
// Author:		Kyle Crisp
// Course:		COP2220
// Date: 09/25/2019
#include <stdio.h>

void welcome(void);
double getTemp(char *tempType);
double convertToCelsius(double tempF);
double convertToFahren(double tempC);
double computeSpread(double tempHigh, double tempLow);
void displayResults(double tempHigh, double tempLow);
void displayCredits(void);

int main(void)
{
    // delcaration of variables
    double tempHigh, tempLow;
    double tempCHigh, tempCLow, tempFHigh, tempFLow;

    // call for welcome function
    welcome();

    // functions to get temperature from user
    // uses text parameter to specify desired value
    tempHigh = getTemp("high in Fahrenheit");
    tempLow = getTemp("low in Fahrenheit");

    // converts user's temps to Celsius
    tempCHigh = convertToCelsius(tempHigh);
    tempCLow = convertToCelsius(tempLow);

    // converts back to Fahrenheit to verify
    // conversions accuracy
    tempFHigh = convertToFahren(tempCHigh);
    tempFLow = convertToFahren(tempCLow);

    // displays results, Celsius then Fahrenheit
    printf("\nCelsius:\n");
    displayResults(tempCHigh, tempCLow);

    printf("\nFahrenheit:\n");
    displayResults(tempFHigh, tempFLow);

    // displays end ticket
    displayCredits();

    return 0;
}

// welcome function
// no parameters, returns no value
void welcome(void)
{
    // welcomes user
    printf("Welcome to Kyle Crisp's Temperature Converter \n");

    return ;
}

// intial value prompt function
// string parameter to specify desired value
// returns user's input
double getTemp(char *tempType)
{
    // variable declaration
    double temp;

    // prompts user for input
    printf("\nPlease enter the temperature %s: ", tempType);
    scanf("%lf", &temp);

    return temp;
}

// Celsius conversion function
// Fahrenheit parameter
// returns temperature in Celsius
double convertToCelsius(double tempF)
{
    // variable declaration
    double tempC;

    // conversion to Celsius
    tempC = ((tempF - 32) * 5/9);

    return tempC;
}

// Fahrenheit conversion function
// Celsius parameter
// returns temperature in Fahrenheit
double convertToFahren(double tempC)
{
    // variable declaration
    double tempF;

    // conversion to Fahrenheit
    tempF = ((tempC * 9/5) + 32);

    return tempF;
}

// spread computation function
// temperature parameters: highs and lows
// returns calculated spread
double computeSpread(double tempHigh, double tempLow)
{
    // calculates spread
    double spread = (tempHigh - tempLow);

    return spread;
}

// result display function
// temperature parameters: high and lows
// returns nothing
void displayResults(double tempHigh, double tempLow)
{
    // variable declaration
    double tempSpread;

    // calls spread computation function
    tempSpread = computeSpread(tempHigh, tempLow);

    // prints results
    printf("  High: %.1lf\n  Low: %.1lf\n  Spread: %.1lf\n", tempHigh, tempLow, tempSpread);

    return ;
}

// display end ticket function
// no parameters
// returns nothing
void displayCredits(void)
{
    // prints end credits
    printf("\nResults provided by Kyle Crisp\n");

    return ;
}

/*
Test data:


Sample input 1:
High in Fahrenheit: 52
Low in Fahrenheit: 24

Expected Output 1:
Please enter the temperature high in Fahrenheit: 52

Please enter the temperature low in Fahrenheit: 24

Celsius:
  High: 11.1
  Low: -4.4
  Spread: 15.6

Fahrenheit:
  High: 52.0
  Low: 24.0
  Spread: 28.0


Sample Input 2:
High in Fahrenheit: 78.6
Low in Fahrenheit: 65.7

Expected Output 2:
Please enter the temperature high in Fahrenheit: 78.6

Please enter the temperature low in Fahrenheit: 65.7

Celsius:
  High: 25.9
  Low: 18.7
  Spread: 7.2

Fahrenheit:
  High: 78.6
  Low: 65.7
  Spread: 12.9


Sample Input 3:
High in Fahrenheit: 52
Low in Fahrenheit: 24

Expected Output 3:
Please enter the temperature high in Fahrenheit: 95.46

Please enter the temperature low in Fahrenheit: 35.67

Celsius:
  High: 35.3
  Low: 2.0
  Spread: 33.2

Fahrenheit:
  High: 95.5
  Low: 35.7
  Spread: 59.8

Program output 1:
Welcome to Kyle Crisp's Temperature Converter

Please enter the temperature high in Fahrenheit: 52

Please enter the temperature low in Fahrenheit: 24

Celsius:
  High: 11.1
  Low: -4.4
  Spread: 15.6

Fahrenheit:
  High: 52.0
  Low: 24.0
  Spread: 28.0

Results provided by Kyle Crisp


Program output 2:
Welcome to Kyle Crisp's Temperature Converter

Please enter the temperature high in Fahrenheit: 78.6

Please enter the temperature low in Fahrenheit: 65.7

Celsius:
  High: 25.9
  Low: 18.7
  Spread: 7.2

Fahrenheit:
  High: 78.6
  Low: 65.7
  Spread: 12.9

Results provided by Kyle Crisp


Program output 3:
Welcome to Kyle Crisp's Temperature Converter

Please enter the temperature high in Fahrenheit: 95.46

Please enter the temperature low in Fahrenheit: 35.67

Celsius:
  High: 35.3
  Low: 2.0
  Spread: 33.2

Fahrenheit:
  High: 95.5
  Low: 35.7
  Spread: 59.8

Results provided by Kyle Crisp
*/
