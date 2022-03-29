/*
 * Tag des Jahres
 * Autor: Carolyn Jansing
 * Datum: 15.3.2022
 */

#include <stdio.h>
#include <stdlib.h>
int schaltjahr(int jahreszahl)
{
    // Wert um Ergebnis auf wahr/falsch zu setzen
    int ergebnis = 0;

    //Überprüfung der Bedingungen
    if (jahreszahl % 4 == 0)
    {
        if (jahreszahl % 100 == 0)
        {
            if (jahreszahl % 400 == 0)
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
        ergebnis = 1;
    }
}
int main()
{
    //Initialisierung Variablen
    int tage_pro_monat[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int jahr = 0;
    int monat = 0;
    int tag = 0;
    int tage = 0;

 
   //Eingabe Jahr
    do
    {
       printf("Geb ein Jahr ein:\n");
       scanf("%i", &jahr);
    }while (jahr==0 || jahr<1000 ||jahr>2030);
  
    //Eingabe Monat
    do
    {
      printf("Geb ein Monat ein:\n");
      scanf("%i", &monat);
    }while (monat<=0 || monat>12 );
    //Eingabe Tag mit Berücksichtigung des Schaltjahres und Monats
    do
    {
         printf("Geb ein Tag  ein:\n");
         scanf("%i", &tag);
         if ((monat == 1 || monat == 3 || monat == 5 || monat==7|| monat ==8 || monat == 10 || monat==12) && (tag>31))
         { 
            tag = 0;
         }
         else if (monat == 2){
             if (schaltjahr(jahr)==0 && tag > 29)
             {
                 tag = 0;
             }
             if(schaltjahr(jahr)==0 && tag>28){
                 tag = 0;
             }
         }
         else if (tag>30){
             tag = 0;
         }
         else{

         }
    } while (tag<=0);
    
    //Rechnung der Tage
    if (schaltjahr(jahr) == 0)
    {
        tage_pro_monat[1] = 29;
    }
    for (int i = 0; i < monat; i++)
    {
        tage = tage + tage_pro_monat[i];
    }
    tage = tage + tag;
    //Ausgabe
    printf("Es ist Tag %d des Jahres\n", tage);

    return 0;
}
