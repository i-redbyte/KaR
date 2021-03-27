#include <stdio.h>

#define WORLD_SIZE 11
#define CHARS_SIZE 94

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
 Task 1.10 - similar solution
 */
void copyInToOutStream();

/**
 Prints each word on a new line
 Task 1.12
 */
void showWorldsInLines();

/**
  Vertical histogram of counting word lengths
  Task 1.13
 */
void verticalHistogramOfWordLen();

void showWordLenHistogram(const int *lengthFrequency, int verticalSize);

/**
 Character frequency histogram
 Task 1.14
 */
void charFreqHistogram();

/**
 Change temperature conversion from task 1.3 to function
 Task 1.15
 */
float fahrToCels(float temperature);

float celsToFahr(float temperature);

void convertTemperature();

int main() {
    printf(">>> Hello, C world! <<<\n");
    convertTemperature();
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

void showWorldsInLines() {
    int c;
    int counter = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t') {
            c = '\n';
            ++counter;
        } else {
            counter = 0;
        }
        if (counter <= 1) putchar(c);
    }
}

void verticalHistogramOfWordLen() {
    int lengthFrequency[WORLD_SIZE];
    int len, verticalSize;
    int c, i;
    len = verticalSize = 0;
    for (i = 0; i < WORLD_SIZE; ++i) lengthFrequency[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\n' && c != '\t') {
            ++len;
        } else if (len != 0) {
            if (len < WORLD_SIZE) {
                ++lengthFrequency[len - 1];
                if (verticalSize < lengthFrequency[len - 1])
                    verticalSize = lengthFrequency[len - 1];
            } else {
                ++lengthFrequency[WORLD_SIZE - 1];
                if (verticalSize < lengthFrequency[WORLD_SIZE - 1])
                    verticalSize = lengthFrequency[WORLD_SIZE - 1];
            }
            len = 0;
        }
    }

    showWordLenHistogram(lengthFrequency, verticalSize);

}

void showWordLenHistogram(const int *lengthFrequency, int verticalSize) {
    for (int i = verticalSize; i > 0; --i) {
        printf("%2d|", i);
        for (int j = 0; j < WORLD_SIZE; ++j) {
            if (lengthFrequency[j] >= i)
                printf("   #");
            else
                printf("    ");
        }
        printf("\n");
    }

    printf("  ∟");
    printf("____________________________________________");
    printf("\n   ");

    for (int i = 0; i < WORLD_SIZE; ++i) {
        if (i < WORLD_SIZE - 1)
            printf("%4d", i + 1);
        else
            printf(" +%d", i);
    }
    printf("\n");
}

void charFreqHistogram() {
    int charFreq[CHARS_SIZE];
    int c;
    int max = 0;

    for (int i = 0; i < CHARS_SIZE; ++i) charFreq[i] = 0;

    while ((c = getchar()) != EOF) {
        int value = c - 33;
        if (33 <= c && c <= 126) {
            ++charFreq[value];
            if (max < charFreq[value]) max = charFreq[value];
        }
    }
    for (int i = max; i > 0; --i) {
        printf("%4d|", i);
        for (int k = 0; k < CHARS_SIZE; ++k) {
            if (charFreq[k] >= i)
                printf("#");
            else
                printf(" ");
        }
        printf("\n");
    }
    printf("    +");
    for (int i = 0; i <= CHARS_SIZE - 1; ++i) printf("-");
    printf("\n     ");
    for (int i = 0; i <= CHARS_SIZE - 1; ++i) printf("%c", i + 33);
    printf("\n");
}

float fahrToCels(float temperature) {
    return (5.0 / 9.0) * (temperature - 32.0);
}

float celsToFahr(float temperature) {
    return (9.0 / 5.0 * temperature) + 32.0;
}

void convertTemperature() {
    printf("===Celsius to Fahrenheit: \n");
    int lower = 0, upper = 300, step = 20;
    float cel = lower;
    while (cel <= upper) {
        printf("%3.0f %6.1f\n", cel, celsToFahr(cel));
        cel = cel + step;
    }
    printf("\n");
    printf("===Fahrenheit to Celsius: \n");
    float farh = lower;
    while (farh <= upper) {
        printf("%3.0f %6.1f\n", farh, fahrToCels(farh));
        farh = farh + step;
    }

}
