#include <stdio.h>
void task_1_3();
void task_1_4();
void task_1_5();

int main(){
    printf("Hello, C world!\n");
    task_1_3();
    task_1_4();
    task_1_5();
    return 0;
}
/*
Show Fahrenheit to Celsius Conversion Table
(°F − 32) × 5/9 = °C
*/
void task_1_3(){
    float fahr, cel;
    int lower = 0, upper = 300, step = 20;
    fahr = lower;
    printf("Fahrenheit to Celsius: \n");
    while (fahr <= upper){
        cel = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, cel);
        fahr = fahr + step;
    }
}

/*
Show Celsius to Fahrenheit Conversion Table
(°C × 9/5) + 32 = °F
*/
void task_1_4(){
    float fahr, cel;
    int lower = 0, upper = 300, step = 20;
    cel = lower;
    printf("Celsius to Fahrenheit: \n");
    while (cel <= upper){
        fahr = (9.0 / 5.0 * cel)+32.0 ;
        printf("%3.0f %6.1f\n", cel, fahr);
        cel = cel + step;
    }
}

void task_1_5(){
    printf("Inverse table: \n");
    for (int fahr = 300; fahr >= 0; fahr -= 20) 
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));  
}