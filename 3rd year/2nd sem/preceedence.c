/*
1. create a char array
2. have per char input and added to array
3. traverse through array and find open parenthesis, if none proceed to 4
    a. traverse and find closing parenthesis
    b. perform operation from open to close parenthesis
    c. resrart loop
4. perform last operation
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int computeExpression(char string[50], int openPar, int closePar);
int getOperandChar(char string[50], int begindex);
int performOperand(int left, int right, char operand);
void mutateArr(char string[50], int openPar, int closePar, int mutated);
// int checkDigit(char string[50], int begIndex, int endIndex);

// ((65+5)x(4+3))/((4x3)-(87-2))

int main()
{
    char operation[50], operand;

    printf("input algebraic operation & please start with an open parenthesis & end with a closed parenthesis: \n");
    scanf("%s", operation);

    int i = 0, j = i, loop = 0;

    while (operation[i] != '\0')
    { //  i = 6

        if (operation[i] == '(') // get index of digit
        {
            j = i + 1; // index after open parenthesis
        }              //  j = 2
        i++;
        if (operation[i] == ')') // index of closed parenthesis
        {
            printf("\nopenPar index: %d, closePar index: %d", j, i);
            loop = computeExpression(operation, j, i); //  i = 6
            // (70x(4+3)/(4*3)-(87-2))
            i = 0;
        }

    } // while index has not reached end of string
    for (i = 0; operation[i] != '\0' || isdigit(operation[i]);)
    {
        if (isdigit(operation[i]))
        {
            j = i;
        }
    }

    operation = atoid(operation);
    printf("\nResult: %s", operation);

    return 0;
}

int computeExpression(char string[50], int openPar, int closePar) // OP = 2, CP = 6
{
    int k, leftDigit, rightDigit, output, result = 0;
    char operand;

    leftDigit = atoi(string + openPar);  // get left digit using atoi = 65
    k = getOperandChar(string, openPar); // k = 4
    rightDigit = atoi(string + (k + 1)); // get right digit using atoi = 5
    printf("\nleft(%d) and right(%d) taken from %s", leftDigit, rightDigit, string);
    if (leftDigit != 0 && rightDigit != 0)
    {
        output = performOperand(leftDigit, rightDigit, string[k]); // get solved expression

        mutateArr(string, openPar - 1, closePar + 1, output);
        result = 1;
    }
    return result;
}

int getOperandChar(char string[50], int begindex)
{
    for (begindex += 1; isdigit(string[begindex]); begindex++)
    {
    } // get operand by finding non digit character after open parenthesis
    return begindex;
}

int performOperand(int left, int right, char operand)
{

    int result = 0;

    switch (operand)
    {
    case '+':
        result = left + right;
        break;
    case '-':
        result = left - right;
        break;
    case '/':
        result = left / right;
        break;
    case 'x':
        result = left * right;
        break;
    }

    return result;
}

void mutateArr(char string[50], int openPar, int closePar, int mutated) // OP = 1, CP = 6
{
    int i, j;
    char str[50];

    sprintf(str, "%d", mutated);

    for (i = 0; str[i] != '\0'; i++)
    {
    } // find length of str

    for (j = 0; string[j] != '\0'; j++)
    {
    } // find length of string

    strncat(str, string + closePar, j);

    memmove(string + openPar, str, j);
}

// int checkDigit(char operation[50], int begIndex, int endIndex)
// {
//     char digit[20];

//     int x = j;

//     if (k != (j + 1))
//     {
//         strncpy(digit, operation + j, k - j);
//         x = digit - '0';
//     }

//     if (isdigit(x))
//     {
//         return x;
//     }
//     else
//     {
//         return 0;
//     }
// }
