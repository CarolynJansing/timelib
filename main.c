
/*
 * Tag des Jahres
 * Autor: Carolyn Jansing
 * Datum: 15.3.2022
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "time.h"


int main()
{
    int result = 0;
    struct daydate date;
    date.day = 0;
    date.month = 0;
    date.year = 0;

    printf(",-,-,-,-,-,-,-,-,-,-,-,-,-,-,-,-,-,-,-,-,-,-,\n");
    printf("Tag des Jahres\n");
    printf(",_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,\n");

    do
    {
        input_date(date);
    } while (exists_date(date) < 1);

    result = day_of_the_year(date);

    printf("Result: %d \n", result);

    return 0;
}
