#include <stdio.h> 

int main()
{
    //For loop 
    for(int i = 0; i < 43; i++)
    {
        printf("For loop number is: %d \n", i);
    }

    //While loop
    int j = 0;
    while(j < 43)
    {
        printf("While loop number is: %d \n", j);
        j++;
    }

    //Do loop
    int k = 0;
    do
    {
        printf("Do loop number is: %d \n", k);
        k++;
    }while(k < 43);

}