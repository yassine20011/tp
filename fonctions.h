#ifndef FONCTIONS_H
#define FONCTIONS_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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

char *from100to199(int n, const char **digits, const char **tens)
{
    const char *cent = "cent ";
    char *string1;

    if (n == 100)
        return (char *)cent;
    else if (n >= 101 && n <= 119)
    {
        string1 = malloc(strlen(cent) + strlen(from0to19(n % 100, digits)) + 1);
        strcpy(string1, cent);
        return strcat(string1, from0to19(n % 100, digits));
    }
    else if (n >= 120 && n <= 199)
    {
        string1 = malloc(strlen(cent) + strlen(from20to99(n % 100, digits, tens)) + 1);
        strcpy(string1, cent);
        return strcat(string1, from20to99(n % 100, digits, tens));
    }
    return NULL;
}

char *from200to999(int n, const char **digits, const char **tens)
{
    const char *string1;
    const char *space = " ";
    const char *string2;
    char *string3;

    string1 = from0to19(n / 100, digits);
    string2 = from100to199(n - ((n / 100) - 1) * 100, digits, tens);

    string3 = malloc(strlen(string1) + strlen(space) + strlen(string2) + 1);
    strcpy(string3, string1);
    strcat(string3, space);
    strcat(string3, string2);
    return string3;
}

char *from1000to9999(int n, const char **digits, const char **tens)
{
    const char *string1;
    const char *mille = " mille ";
    const char *string2;
    char *total;

    if (n % 1000 == 0)
    {
        string1 = from0to19(n / 1000, digits);
        total = malloc(strlen(string1) + strlen(mille) + 1);
        strcpy(total, string1);
        strcat(total, mille);
        return total;
    }
    else if (n % 1000 <= 19)
        string2 = from0to19(n % 1000, digits);
    else if (n % 1000 >= 20 && n % 1000 <= 99)
        string2 = from20to99(n % 1000, digits, tens);
    else if (n % 1000 >= 100 && n % 1000 <= 199)
        string2 = from100to199(n % 1000, digits, tens);
    else if (n % 1000 >= 200 && n % 1000 <= 999)
        string2 = from200to999(n % 1000, digits, tens);
    string1 = from0to19(n / 1000, digits);
    total = malloc(strlen(string1) + strlen(mille) + strlen(string2) + 1);
    strcpy(total, string1);
    strcat(total, mille);
    strcat(total, string2);
    return total;
}

char *from10000to19999(int n, const char **digits, const char **tens)
{
    const char *string1;
    const char *string2 = " mille ";
    char *string3;
    char *total;

    if (n % 1000 == 0)
    {
        string1 = from0to19(n / 1000, digits);
        string3 = malloc(strlen(string1) + strlen(string2) + 1);
        strcpy(string3, string1);
        strcat(string3, string2);
        return string3;
    }
    else if (n % 1000 <= 19)
        string3 = from0to19(n % 1000, digits);
    else if (n % 1000 >= 20 && n % 1000 <= 99)
        string3 = from20to99(n % 1000, digits, tens);
    else if (n % 1000 >= 100 && n % 1000 <= 199) // 1000-1199
        string3 = from100to199(n % 1000, digits, tens);
    else if (n % 1000 >= 200 && n % 1000 <= 999) //
        string3 = from200to999(n % 1000, digits, tens);
    string1 = from0to19(n / 1000, digits);
    total = malloc(strlen(string1) + strlen(string2) + strlen(string3) + 1);
    strcpy(total, string1);
    strcat(total, string2);
    strcat(total, string3);
    return total;
}

char *from20000to99999(int n, const char **digits, const char **tens)
{
    const char *string1;
    const char *string2;
    const char *mille = " mille ";
    char *total;
    if (n % 1000 == 0)
    {
        string1 = from20to99(n / 1000, digits, tens);
        total = malloc(strlen(string1) + strlen(mille) + 1);
        strcpy(total, string1);
        strcat(total, mille);
        return total;
    }
    else if (n % 1000 <= 19)
        string2 = from0to19(n % 1000, digits);
    else if (n % 1000 >= 20 && n % 1000 <= 99)
        string2 = from20to99(n % 1000, digits, tens);
    else if (n % 1000 >= 100 && n % 1000 <= 199)
        string2 = from100to199(n % 1000, digits, tens);
    else if (n % 1000 >= 200 && n % 1000 <= 999)
        string2 = from200to999(n % 1000, digits, tens);
    string1 = from20to99(n / 1000, digits, tens);
    total = malloc(strlen(string1) + strlen(mille) + strlen(string2) + 1);
    strcpy(total, string1);
    strcat(total, mille);
    strcat(total, string2);
    return total;
}

char *from100000to199999(int n, const char **digits, const char **tens)
{
    const char *string1;
    const char *string2;
    const char *mille = " mille ";
    char *total;

    if (n % 1000 == 0)
    {
        string1 = from100to199(n / 1000, digits, tens);
        total = malloc(strlen(string1) + strlen(mille) + 1);
        strcpy(total, string1);
        strcat(total, mille);
        return total;
    }
    else if (n % 1000 <= 19)
        string2 = from0to19(n % 1000, digits);
    else if (n % 1000 >= 20 && n % 1000 <= 99)
        string2 = from20to99(n % 1000, digits, tens);
    else if (n % 1000 >= 100 && n % 1000 <= 199)
        string2 = from100to199(n % 1000, digits, tens);
    else if (n % 1000 >= 200 && n % 1000 <= 999)
        string2 = from200to999(n % 1000, digits, tens);
    string1 = from100to199(n / 1000, digits, tens);

    total = malloc(strlen(string1) + strlen(mille) + strlen(string2) + 1);
    strcpy(total, string1);
    strcat(total, mille);
    strcat(total, string2);
    return total;
}

char *from200000to999999(int n, const char **digits, const char **tens)
{
    const char *string1;
    const char *string2;
    const char *mille = " mille ";
    char *total;

    if (n % 1000 == 0)
    {
        string1 = from200to999(n / 1000, digits, tens);
        total = malloc(strlen(string1) + strlen(mille) + 1);
        strcpy(total, string1);
        strcat(total, mille);
        return total;
    }
    else if (n % 1000 <= 19)
        string2 = from0to19(n % 1000, digits);
    else if (n % 1000 >= 20 && n % 1000 <= 99)
        string2 = from20to99(n % 1000, digits, tens);
    else if (n % 1000 >= 100 && n % 1000 <= 199)
        string2 = from100to199(n % 1000, digits, tens);
    else if (n % 1000 >= 200 && n % 1000 <= 999)
        string2 = from200to999(n % 1000, digits, tens);
    string1 = from200to999(n / 1000, digits, tens);
    total = malloc(strlen(string1) + strlen(mille) + strlen(string2) + 1);
    strcpy(total, string1);
    strcat(total, mille);
    strcat(total, string2);
    return total;
}

char *fromMillionTo9999999(int n, const char **digits, const char **tens)
{
    const char *string1;
    const char *string2;
    const char *million = " million ";
    char *total;

    if (n % 1000000 == 0)
    {
        string1 = from0to19(n / 1000000, digits);
        total = malloc(strlen(string1) + strlen(million) + 1);
        strcpy(total, string1);
        strcat(total, million);
        return total;
    }
    else if (n % 1000000 <= 19)
        string2 = from0to19(n % 1000000, digits);
    else if (n % 1000000 >= 20 && n % 1000000 <= 99)
        string2 = from20to99(n % 1000000, digits, tens);
    else if (n % 1000000 >= 100 && n % 1000000 <= 199)
        string2 = from100to199(n % 1000000, digits, tens);
    else if (n % 1000000 >= 200 && n % 1000000 <= 999)
        string2 = from200to999(n % 1000000, digits, tens);
    else if (n % 1000000 >= 1000 && n % 1000000 <= 9999)
        string2 = from1000to9999(n % 1000000, digits, tens);
    else if (n % 1000000 >= 10000 && n % 1000000 <= 19999)
        string2 = from10000to19999(n % 1000000, digits, tens);
    else if (n % 1000000 >= 20000 && n % 1000000 <= 99999)
        string2 = from20000to99999(n % 1000000, digits, tens);
    else if (n % 1000000 >= 100000 && n % 1000000 <= 199999)
        string2 = from100000to199999(n % 1000000, digits, tens);
    else if (n % 1000000 >= 200000 && n % 1000000 <= 999999)
        string2 = from200000to999999(n % 1000000, digits, tens);
    string1 = from0to19(n / 1000000, digits);
    total = malloc(strlen(string1) + strlen(million) + strlen(string2) + 1);
    strcpy(total, string1);
    strcat(total, million);
    strcat(total, string2);
    return total;
}

char *FrenchNumbers(int n)
{
    char *string;
    const char *digits[] = {"zero", "un", "deux", "trois", "quatre", "cinq", "six", "sept", "huit", "neuf", "dix", "onze", "douze", "treize", "quatorze", "quinze", "seize", "dix-sept", "dix-huit", "dix-neuf"};
    const char *tens[] = {"vingt", "trente", "quarante", "cinquante", "soixante", "Soixante-dix", "quatre-vingt", "quatre-vingt-dix"};

    if (n >= 0 && n <= 19)
        string = from0to19(n, digits);
    else if (n >= 20 && n <= 99)
        string = from20to99(n, digits, tens);
    else if (n >= 100 && n <= 199)
        string = from100to199(n, digits, tens);
    else if (n >= 200 && n <= 999)
        string = from200to999(n, digits, tens);
    else if (n >= 1000 && n <= 9999)
        string = from1000to9999(n, digits, tens);
    else if (n >= 10000 && n <= 19999)
        string = from10000to19999(n, digits, tens);
    else if (n >= 20000 && n <= 99999)
        string = from20000to99999(n, digits, tens);
    else if (n >= 100000 && n <= 199999)
        string = from100000to199999(n, digits, tens);
    else if (n >= 200000 && n <= 999999)
        string = from200000to999999(n, digits, tens);
    else if (n >= 1000000 && n <= 9999999)
        string = fromMillionTo9999999(n, digits, tens);
    else
        string = "le numero est trop grand";
    return string;
}


#endif