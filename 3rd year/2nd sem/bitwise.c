#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 10;
    int y;
    for (y = 0; y < 32; y++)
    {
        if (x % 2 == 0)
        {

            // printf("0");
            printf("%d\n", x);
        }
        else
        {
            // printf("1", x);
            printf("%d\n", x);
        }
        x = x << 1;
    }
    return 0;
}
