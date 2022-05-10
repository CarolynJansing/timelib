#ifndef ZEIT_H_INCLUDED
#define ZEIT_H_INCLUDED

// Struct für das Datum
struct daydate
{
   int day;
   int month;
   int year;
};

//die verscheidenen Funktionen :
int is_leapyear(int year);
int day_of_the_year(struct daydate);
void input_date(struct daydate);
int exists_date(struct daydate);
int get_days_for_month(int month, int year);




#endif

