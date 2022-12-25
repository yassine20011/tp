#include <stdio.h>  // printf scanf
#include <string.h> // strlen strcat strcpy
#include <stdlib.h> // malloc
#include "fonctions.h"

int main()
{
    long int n;

    printf("Entrez un nombre entre 0 et 999 999 999 999 999: "); scanf("%ld", &n);
    if (n >= 1000000000 && n <= 999999999999)
        printf("%ld = %s\n", n, Capitalize(RemoveDuplicateSpace(milliards(n))));
    else if (n >= 10000000000 && n <= 999999999999999)
        printf("%ld = %s\n", n, Capitalize(RemoveDuplicateSpace(billions(n))));
    else
        printf("%ld = %s\n", n, Capitalize(RemoveDuplicateSpace(FrenchNumbers(n))));

    return 0;
}
