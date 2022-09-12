#include <stdio.h>
#include <math.h>
int main()
{
    float fracNume, fracDeno, d;
    double p;

    printf("Input fraction numerator: ");
    scanf("%f", &fracNume);
    printf("Input fraction denominator: ");
    scanf("%f", &fracDeno);

    p = (fracNume / fracDeno);
    printf("Fraction to Decimal = %lf", p);

    return (0);
}
