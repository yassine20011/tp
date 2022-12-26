#include <stdio.h>  // printf scanf
#include <string.h> // strlen strcat strcpy
#include <stdlib.h> // malloc
#include "fonctions.h"

int main()
{
    long int n;

    printf("Entrez un nombre entre 0 et 999 999 999 999 999 999: ");
    scanf("%ld", &n);

    printf("%ld = %s\n", n, RemoveDuplicateSpace(FrenchNumbers(n)));

    return 0;
}