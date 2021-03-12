#include <stdio.h>

/**
  Show Fahrenheit to Celsius Conversion Table
  (°F − 32) × 5/9 = °C
  TASK 1.3
 **/
void fahrenheitToCelsius();

/**
  Show Celsius to Fahrenheit Conversion Table
  (°C × 9/5) + 32 = °F
  TASK 1.4
**/
void celsiusToFahrenheit();

/**
  Inverted order Fahrenheit to Celsius Conversion Table
  Task 1.5
 **/
void invertFahrenheitToCelsius();

/**
 Show EOF const
 Show expression result: getchar() != EOF
 Task 1.6 and 1.7
 */
void eofAndGetchar();

/**
 Counting breaks between words
 Task 1.8
 * */
void spaceCounter();

/**
 Copies the input stream to the output stream replacing several consecutive spaces with one
 Task 1.9
 */
void copyInToOutStream();

int main() {
    printf(">>> Hello, C world! <<<\n");
    copyInToOutStream();
    return 0;
}

void fahrenheitToCelsius() {
    float fahr, cel;
    int lower = 0, upper = 300, step = 20;
    fahr = lower;
    printf("Fahrenheit to Celsius: \n");
    while (fahr <= upper) {
        cel = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, cel);
        fahr = fahr + step;
    }
}


void celsiusToFahrenheit() {
    float fahr, cel;
    int lower = 0, upper = 300, step = 20;
    cel = lower;
    printf("Celsius to Fahrenheit: \n");
    while (cel <= upper) {
        fahr = (9.0 / 5.0 * cel) + 32.0;
        printf("%3.0f %6.1f\n", cel, fahr);
        cel = cel + step;
    }
}

void invertFahrenheitToCelsius() {
    printf("Inverse table: \n");
    for (int fahr = 300; fahr >= 0; fahr -= 20)
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
}

void eofAndGetchar() {
    int c;
    printf("const EOF = %d", EOF);
    printf("getchar() != EOF = %d \n", getchar() != EOF);

}

void spaceCounter() {
    int c, tabCount = 0, spaceCount = 0, newlineCount = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') ++newlineCount;
        if (c == '\t') ++tabCount;
        if (c == ' ') ++spaceCount;
    }
    printf("New lines: %2d, Tabs: %2d, Spaces: %2d", newlineCount, tabCount, spaceCount);
}

void copyInToOutStream() {
    int c;
    int spaceCount = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++spaceCount;
        } else {
            spaceCount = 0;
        }
        if (spaceCount <= 1) putchar(c);
    }
}