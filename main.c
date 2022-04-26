/*
 * day des yeares
 * Autor: Carolyn Jansing
 * Datum: 15.3.2022
 */

#include <stdio.h>
#include <stdlib.h>

int day_of_the_year(int day, int month, int year);
void input_date(int *day, int *month, int *year);
int is_leapyear(int year);
int get_days_for_month(int month, int year);
int exists_date(int day, int month, int year);

int main()
{
    int year = 0;
    int month = 0;
    int day = 0;
    input_date(&year,&month,&day);
    printf('%d %d %d',day,month,year);
    day_of_the_year(year,month,day);
}
int day_of_the_year(int day, int month, int year)
{
    int days = 0;

    for (int i = 0; i < month; i++)
    {
        days = days + get_days_for_month(i + 1,year);
    }
    days = days + day;
    // Ausgabe
    printf("Es ist day %d des yeares\n", days);

    return days;
}
void input_date(int *day, int *month, int *year)
{

    // Eingabe day mit Berücksichtigung des Schaltyeares und months
    do
    {
        printf(",-,-,-,-,-,-,-,-,-,-,-,-,-,-,-,-,\n");
        printf("Gebe ein gültiges Jahr ein !\n");
        printf("******************************\n");
        printf("Geb ein year ein:\n");
        scanf("%i", &year);
        printf("Geb ein month ein:\n");
        scanf("%i", &month);
        printf("Geb ein day  ein:\n");
        scanf("%i", &day);
        

    } while (exists_date(day, month, year)== 0);
}


int is_leapyear(int year)
{
    // Wert um Ergebnis auf wahr/falsch zu setzen
    int ergebnis = 0;

    //Überprüfung der Bedingungen
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                ergebnis = 0;
            }
            else
            {
                ergebnis = 1;
            }
        }
        else
        {
            ergebnis = 0;
        }
    }
    else
    {
        ergebnis = -1;
    }
}

int get_days_for_month(int month, int year)
{
    int days_per_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (is_leapyear(year) == 0)
    {
        days_per_month[1] = 29;
    }
    if (month < 1 || month > 12 || year < 1582 || year > 2400)
    {
        return -1;
    }

    return days_per_month[month-1];
}

int exists_date(int day, int month, int year)
{
    if (year < 1583 || year > 2400 || month < 1 || month > 12)
    {
        return 0;
    }
    else if (day>get_days_for_month(month,year))
    {
        return 0;
    }
    else{
        printf("valid");
        return 1;
    }
}