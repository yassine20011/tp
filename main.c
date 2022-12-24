#include <stdio.h>     // printf scanf
#include <string.h>    // strlen strcat strcpy
#include <stdlib.h>    // malloc
#include "fonctions.h" // FrenchNumbers

char *RemoveDuplicateSpace(char *str)
{
    char *str2 = malloc(strlen(str) + 1);
    int i = 0;
    int j = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ' ' && str[i + 1] == ' ')
            i++;
        else
        {
            str2[j] = str[i];
            i++;
            j++;
        }
    }
    str2[j] = '\0';
    return str2;
}

char *Capitalize(char *str)
{
    int i = 0;
    int j = 0;

    if (str[strlen(str) - 1] == ' ')
        str[strlen(str) - 1] = '\0';

    char *str2 = malloc(strlen(str) + 1);

    while (str[i] != '\0')
    {
        if (str[i] == ' ' )
        {
            str2[j] = str[i];
            str2[j + 1] = str[i + 1] - 32;
            i++;
            j++;
        }
        else
            str2[j] = str[i];
        i++;
        j++;
    }
    str2[0] = str[0] - 32;
    str2[j] = '\0';
    return str2;
}

int main()
{
    // int n;
    // printf("Entrez un nombre entre 0 et 9 999 999: "); scanf("%d", &n);
    // printf("%d = %s\n", n, Capitalize(RemoveDuplicateSpace(FrenchNumbers(n))));
    // return 0;

     for (int i = 200000; i <= 1000000; i++)
        printf("%d = %s\n", i,Capitalize(RemoveDuplicateSpace(FrenchNumbers(i))));
}




