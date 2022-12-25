#include <stdio.h>  // printf scanf
#include <string.h> // strlen strcat strcpy
#include <stdlib.h> // malloc
#include "fonctions.h"

char *milliards(long int n)
{
    const char *milliard = " milliard ";
    char *string;
    char *string2;
    char *total;
    int nbr = n / 1000000000;

    if (nbr >= 0 && nbr <= 19)
        string = from0to19(nbr, digits);
    else if (nbr >= 20 && nbr <= 99)
        string = from20to99(nbr, digits, tens);
    else if (nbr >= 100 && nbr <= 199)
        string = from100to199(nbr, digits, tens);
    else if (nbr >= 200 && nbr <= 999)
        string = from200to999(nbr, digits, tens);

    string2 = n % 1000000000 == 0 ? " " : FrenchNumbers(n % 1000000000);
    total = malloc(strlen(string) + strlen(milliard) + strlen(string2) + 1);
    strcpy(total, string);
    strcat(total, milliard);
    strcat(total, string2);
    return total;
}

char *billions(long int n)
{
    const char *billion = " billion ";

    char *string;
    char *string2;
    char *total;
    int nbr = n / 1000000000000;

    if (nbr >= 0 && nbr <= 19)
        string = from0to19(nbr, digits);
    else if (nbr >= 20 && nbr <= 99)
        string = from20to99(nbr, digits, tens);
    else if (nbr >= 100 && nbr <= 199)
        string = from100to199(nbr, digits, tens);
    else if (nbr >= 200 && nbr <= 999)
        string = from200to999(nbr, digits, tens);

    string2 = n % 1000000000000 == 0 ? " " : milliards(n % 1000000000000);
    total = malloc(strlen(string) + strlen(billion) + strlen(string2) + 1);
    strcpy(total, string);
    strcat(total, billion);
    strcat(total, string2);
    return total;
}

int main()
{
    long int n;

    printf("Entrez un nombre entre 0 et 999 999 999 999 999: ");
    scanf("%ld", &n);
    if (n >= 1000000000 && n <= 999999999999)
        printf("%ld = %s\n", n, Capitalize(RemoveDuplicateSpace(milliards(n))));
    else if (n >= 10000000000 && n <= 999999999999999)
        printf("%ld = %s\n", n, Capitalize(RemoveDuplicateSpace(billions(n))));
    else
        printf("%ld = %s\n", n, Capitalize(RemoveDuplicateSpace(FrenchNumbers(n))));

    return 0;
}
