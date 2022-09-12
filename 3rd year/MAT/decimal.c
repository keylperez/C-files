#include <stdio.h>
#include <string.h>
#include <math.h>

/****************************************************************
expected problem
- decimal number to fraction
- fraction to decimal number

 */

void decToFrac();
void fracToDec();

int main()
{

    int operation;

    printf(
        "Choose Task: \n"
        "1. Decimal to Fraction\n"
        "2. Fraction to Decimal\n\n"
        "Enter Choice: ");
    scanf("%d", &operation);

    switch (operation)
    {
    case 1:
        decToFrac();
        break;
    case 2:
        fracToDec();
        break;
    }

    return 0;
}

void decToFrac()
{
    double input;
    float denominator1;

    printf("\n\nInput a decimal number: ");
    scanf("%lf", &input);
    float numerator1 = input * 1000;
    int nume1Int = numerator1 / 10;
    printf("%d", nume1Int);
    int numerator2 = numerator1 - nume1Int;
    printf("%d", numerator2);
}

void fracToDec()
{
    float fracNume, fracDeno, d;

    printf("Input fraction numerator: ");
    scanf("%f", &fracNume);
    printf("Input fraction denominator: ");
    scanf("%f", &fracDeno);

    if (fracDeno == 0)
    {
        printf("Mathematical Error");
        return 0;
    }

    float a, b, r, ans, tmp;

    a = fracNume;
    b = fracDeno;

    if (a < b)
    {
        tmp = a;
        a = b;
        b = tmp;
    }
    r = fmodf(a, b);

    while (r != 0)
    { // Euclidean Algorithm
        a = b;
        b = r;
        r = fmodf(a, b);
    }
    // b is the greatest common divisor

    fracNume = fracNume / b;
    fracDeno = fracDeno / b;
    ans = fracNume / fracDeno;

    printf("Fraction to Decimal = %6f", ans);

    /*	//normal
        float p;
        p= fracNume/fracDeno;
        printf("Fraction to Decimal = %6f",p);
    */
}