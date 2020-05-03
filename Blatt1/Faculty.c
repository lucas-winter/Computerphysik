#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    //Get argument value and set up result
    int n = atoi(argv[1]);
    int result = 1;

    //Compute faculty via loop
    for(int i = 1; i <= n; i++)
    {
        result *= i;
    }
    
    //Print out result
    char str [200];
    int spr = sprintf(str, "Your result is: %d. Input Number was %s", result, argv[0]);
    printf(str, spr);
    
    
    return result;
    /* Für große n kann es zu einem Überlauf des int Datentyps kommen, 
    da Fakultät sehr schnell wächst*/
}