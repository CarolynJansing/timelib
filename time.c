#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "time.h"

int day_of_the_year(struct daydate date)
{

    int result = 0;
    int i;
    int days_for_month = 0;

    days_for_month = get_days_for_month(date.month, date.year);

    for (i = 0; i < date.month - 1; i++)
    {
        result = result + days_for_month;
    }

    result = result + date.day;
    return result;
}

void input_date(struct daydate date)
{

    printf("Geben Sie das Jahr ein: ");
    scanf("%d", &date.year);

    printf("Geben sie den Monat ein: ");
    scanf("%d", &date.month);

    printf("Geben Sie den Tag ein: ");
    scanf("%d", &date.day);
}

int is_leapyear(int year)
{

    if (year < 1582)
    {
        return -1;
    }

    if ((year % 4) == 0)
    {
        if ((year % 100) == 0)
        {
            if ((year % 400) == 0)
            {
                return 1; // Jahr ist ein Schaltjahr
            }
            else
            {
                return 0;
            } // Jahr ist kein Schaltjahr
        }
        else
        {
            return 1;
        } // Jahr ist ein Schaltjahr
    }
    else
    {
        return 0; // Jahr ist kein Schaltjahr
    }
}

int exists_date(struct daydate date)
{

    if (date.month > 12 || date.month < 1 || date.year < 1582 || date.year > 2400 || date.day < 1)
    {
        return 0;
    }

    if (date.day > get_days_for_month(date.month, date.year) || date.day < 0)
    {
        return 0;
    }

    return 1;
}

int get_days_for_month(int month, int year)
{
    int tage_pro_monat[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (is_leapyear(year) > 0)
    {
        tage_pro_monat[1] = 29;
    }

    return tage_pro_monat[month];
}

int day_of_week(struct daydate date)
{
    if (date.month < 3)
    {
        date.month += 12;
        date.year--;
    }
    return (((13 * date.month + 3) / 5 + date.day + date.year + date.year / 4 - date.year / 100 + date.year / 400) % 7);
}
