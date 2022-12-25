#include <stdio.h>     // printf scanf
#include <string.h>    // strlen strcat strcpy
#include <stdlib.h>    // malloc
#include "fonctions.h" // FrenchNumbers

int main()
{
    int n;
    printf("Entrez un nombre entre 0 et 9 999 999: "); scanf("%d", &n);
    printf("%d = %s\n", n, Capitalize(RemoveDuplicateSpace(FrenchNumbers(n))));
    return 0;
}
