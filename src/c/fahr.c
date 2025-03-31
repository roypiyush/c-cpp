#include <stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20
/* lower limit of table */
/* upper limit */
/* step size */
/* print Fahrenheit-Celsius table */
int main() {
    float fahr, celsius;
    int lower, upper, step;

    fahr = lower;
    for (float fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) {
        celsius = 5 * (fahr - 32) / 9;
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 0;
}
