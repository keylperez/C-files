#include <stdio.h>
#include <string.h>

char *greet(char greetee[])
{
    char greetTemplate[500] = "Good day to you sir, ";
    strcat(greetTemplate, greetee);
    return greetTemplate;
    // warning: return makes integer from pointer without a cast [-Wint-conversion] return greetTemplate;
    // warning: function returns address of local variable [-Wreturn-local-addr]
}

int main()
{
    printf("~~~~~~~~~~~~~~~~~~~START~~~~~~~~~~~~~~~~~~~\n");
    char TheName[99];
    printf("GIVE ME YOUR NAME: ");
    scanf("%s", TheName);
    printf("%s", greet(TheName));
    // it outputs (null) for some reason

    printf("\n~~~~~~~~~~~~~~~~~~~~END~~~~~~~~~~~~~~~~~~~");
    return 0;
}
