#ifndef FONCTIONS_H
#define FONCTIONS_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char *digits[] = {"zero", "un", "deux", "trois", "quatre", "cinq", "six", "sept", "huit", "neuf", "dix", "onze", "douze", "treize", "quatorze", "quinze", "seize", "dix-sept", "dix-huit", "dix-neuf"};
const char *tens[] = {"vingt", "trente", "quarante", "cinquante", "soixante", "Soixante-dix", "quatre-vingt", "quatre-vingt-dix"};

char *FrenchNumbers(int n);

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

char *from0to19(int n, const char **digits)
{
    return (char *)digits[n];
}

char *from20to99(int n, const char **digits, const char **tens)
{
    const char *string1;
    const char *string2;
    char *et = " et ";
    char *string3;
    char *Hyphen = "-";

    if (n % 10 == 0)
    {
        return (char *)tens[n / 10 - 2];
    }
    else if (n == 21 || n == 31 || n == 41 || n == 51 || n == 61 || n == 81)
    {
        string1 = tens[n / 10 - 2];
        string2 = digits[n % 10];
        string3 = malloc(strlen(string1) + strlen(et) + strlen(string2) + 1);
        strcpy(string3, string1);
        strcat(string3, et);
        strcat(string3, string2);
        return string3;
    }
    else if (n == 71 || n == 91)
    {
        string1 = tens[n / 10 - 3];
        string2 = digits[11];
        string3 = malloc(strlen(string1) + strlen(et) + strlen(string2) + 1);
        strcpy(string3, string1);
        strcat(string3, et);
        strcat(string3, string2);
        return string3;
    }
    else if ((n >= 71 && n <= 79) || (n >= 91 && n <= 99))
    {
        string1 = tens[n / 10 - 3];
        string2 = digits[(n % 10) + 10];
    }
    else
    {
        string1 = tens[n / 10 - 2];
        string2 = digits[n % 10];
    }
    string3 = malloc(strlen(string1) + strlen(Hyphen) + strlen(string2) + 1);
    strcpy(string3, string1);
    strcat(string3, Hyphen);
    strcat(string3, string2);
    return string3;
}

char *cents(int n)
{
    char *cent = " cent ";
    char *string;
    char *string2;
    char *total;
    int nbr = n / 100;

    if (nbr >= 0 && nbr <= 19)
    {
        if (nbr == 1)
            string = "";
        else
            string = from0to19(nbr, digits);
    }
    else if (nbr >= 20 && nbr <= 99)
        string = from20to99(nbr, digits, tens);

    string2 = n % 100 == 0 ? " " : FrenchNumbers(n % 100);
    total = malloc(strlen(string) + strlen(cent) + strlen(string2) + 1);
    strcpy(total, string);
    strcat(total, cent);
    strcat(total, string2);
    return total;
}

char *mille(int n)
{
    const char *mille = " mille ";
    char *string;
    char *string2;
    char *total;
    int nbr = n / 1000;

    if (nbr >= 0 && nbr <= 19)
        string = from0to19(nbr, digits);
    else if (nbr >= 20 && nbr <= 99)
        string = from20to99(nbr, digits, tens);
    else if (nbr >= 100 && nbr <= 999)
        string = cents(nbr);

    string2 = n % 1000 == 0 ? " " : FrenchNumbers(n % 1000);
    total = malloc(strlen(string) + strlen(mille) + strlen(string2) + 1);
    strcpy(total, string);
    strcat(total, mille);
    strcat(total, string2);
    return total;
}

char *millions(int n)
{
    const char *million = " million ";
    char *string;
    char *string2;
    char *total;
    int nbr = n / 1000000;

    if (nbr >= 0 && nbr <= 19)
        string = from0to19(nbr, digits);
    else if (nbr >= 20 && nbr <= 99)
        string = from20to99(nbr, digits, tens);
    else if (nbr >= 100 && nbr <= 999)
        string = cents(nbr);

    string2 = n % 1000000 == 0 ? " " : FrenchNumbers(n % 1000000);
    total = malloc(strlen(string) + strlen(million) + strlen(string2) + 1);
    strcpy(total, string);
    strcat(total, million);
    strcat(total, string2);
    return total;
}

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
    else if (nbr >= 100 && nbr <= 999)
        string = cents(nbr);

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
    else if (nbr >= 100 && nbr <= 999)
        string = cents(nbr);

    string2 = n % 1000000000000 == 0 ? " " : milliards(n % 1000000000000);
    total = malloc(strlen(string) + strlen(billion) + strlen(string2) + 1);
    strcpy(total, string);
    strcat(total, billion);
    strcat(total, string2);
    return total;
}

char *FrenchNumbers(int n)
{
    char *string;

    if (n >= 0 && n <= 19)
        string = from0to19(n, digits);
    else if (n >= 20 && n <= 99)
        string = from20to99(n, digits, tens);
    else if (n >= 100 && n <= 999)
        string = cents(n);
    else if (n >= 1000 && n <= 999999)
        string = mille(n);
    else if (n >= 1000000 && n <= 999999999)
        string = millions(n);
    else
        string = "le numero est trop grand";
    return string;
}

#endif