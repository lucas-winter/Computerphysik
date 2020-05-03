#include<stdio.h>
#include<float.h>
float floatPrecision(float epsilon)
{
    float x;
    do
    {
        epsilon *= 0.5;
        x = 1.0 + epsilon;
        x = x - 1.0;
    } while (x > 0);
    return epsilon;    
}

double doublePrecision(double epsilon)
{
    double x;
    do
    {
        epsilon *= 0.5;
        x = 1.0 + epsilon;
        x = x - 1.0;
    } while (x > 0);
    return epsilon;    
}


int main()
{
    int d = DECIMAL_DIG;
    printf("float precision is %.*e \n", d, floatPrecision(1.0));
    printf("double precision is %.*e \n", d, doublePrecision(1.0));
}




