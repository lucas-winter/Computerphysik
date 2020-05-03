#include <stdio.h> 


float convertToFahreinheit(int celsius)
{
    return (float) 1.8*((float) celsius) + 32.0;
}

float convertToKelvin(int celsius)
{
    return (float) ((float)celsius) - 273.15;
}

int main()
{
    printf("Celsius | Fahreiheit | Kelvin \n");

    for(int i = 0; i < 100; i++)
    {
        float fahreinheit = convertToFahreinheit(i);
        float kelvin = convertToKelvin(i);
        printf(
            "%d C°     %f F   %f K \n", 
            i, 
            fahreinheit, 
            kelvin
            );
    }
}



