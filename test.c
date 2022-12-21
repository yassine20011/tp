
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main()
{
    char *str1 = "Hello";
    char *str2 = "World";
    char *str3 = malloc(strlen(str1) + strlen(str2) + 1);
    strcpy(str3, str1);
    strcat(str3, str2);
    printf("%s",str3);
    return 0;
}




// from 20 to 99
    // if (n >= 20 && n <= 99)
    // {
    //     if (n % 10 == 0)
    //     {
    //         printf("%s\n", tens[n / 10 - 2]); // -2 car le tableau commence à 0
    //     }
    //     else if (n == 21 || n == 31 || n == 41 || n == 51 || n == 61 || n == 81)
    //     {
    //         printf("%s et %s\n", tens[n / 10 - 2], digits[n % 10]);
    //     }
    //     else if (n == 71 || n == 91)
    //     {
    //         printf("%s et %s\n", tens[n / 10 - 3], digits[11]);
    //     }

    //     else if ((n >= 71 && n <= 79) || (n >= 91 && n <= 99))
    //     {
    //         printf("%s-%s\n", tens[n / 10 - 3], digits[(n % 10) + 10]);
    //     }
    //     else
    //     {
    //         printf("%s-%s\n", tens[n / 10 - 2], digits[n % 10]);
    //     }
    // }