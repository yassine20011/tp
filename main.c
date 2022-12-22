#include <stdio.h>  // printf scanf
#include <string.h> // strlen strcat strcpy
#include <stdlib.h> // malloc
#include "fonctions.h"



int main()
{

    int n;
    printf("Entrez un nombre entre 0 et 9 999 999: ");
    scanf("%d", &n);

    if (n < 0 || n > 10000000)
        printf("Le nombre doit être compris entre 0 et 9 999 999\n");
    printf("%d: ", n);
    FrenchNumbers(n);

    // int i;
    // for (i = 9999991; i <= 9999999; i++)
    // {
    //     printf("%d: ", i);
    //     FrenchNumbers(i);
    // }

    return 0;
}
