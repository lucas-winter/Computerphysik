#include <stdio.h>
#include <math.h>
#include <float.h>

double function(double x)
{
    return (cos(x) - 1.0)/(pow(x,2));
}

void main()
{
    int d = DECIMAL_DIG;
    for(int i = 0; i < 12; i++)
    {
        double x = pow(10, -i);
        double y = function(x);
        printf("Current value is: %.*e Input value is %.*e \n", d, y, d, x );
    }

    /* Zu Beginn nähert sich der Grenzwert dem korrekten Grenzwert von -1/2 an. 
    Für x = 10^-9 wird x² allerdings 0, aufgrund der Ungenauigkeit des double
    Datentyps. Da durch 0 geteilt wird, wird die Ausgabe dann eigentlich 
    undefiniert und repräsentiert nicht mehr den korrekten Grenzwert.*/
}