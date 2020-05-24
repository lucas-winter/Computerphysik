#include <stdio.h>
#include <math.h>

//FCTS parameters
#define TCOUNT 7000 //Number of time steps
#define SCOUNT 100  //Number of space steps

#define DURATION 70
#define LENGTH 1

const float deltaT = ((float) DURATION)/((float) TCOUNT);
const float deltaX = ((float) LENGTH)/ ((float) SCOUNT);

float values[SCOUNT][TCOUNT]; //Stores phi values for every t and x

//System parameters
#define D 0.001
#define X0 0.5
#define SIGMA 0.002

float alpha = 0;

//Solve using FCTS and print results
void runFCTS()
{
    //Iterate over t
    for(int q = 1; q < TCOUNT; q++)
    {
        float t = q * deltaT;

        //Iterate over x
        for(int i = 1; i < SCOUNT - 1; i++)
        {
            float x = i * deltaX;
            values[i][q] = values[i][q - 1] + alpha * (values[i - 1][q - 1] - 2.*values[i][q - 1] + values[i + 1][q - 1]);
            
            printf("%f %f %f \n", t, x, values[i][q]);
        }
        
        printf("\n");
    }
}

//Set shape of distrubution for t = 0
void setStartParameters()
{
    alpha = D*deltaT/(deltaX * deltaX);
    for(int i = 0; i < SCOUNT; i++)
    {
        float x = i*deltaX;
        values[i][0] = exp(-pow(x - X0, 2.)/((float)(2.*SIGMA*SIGMA))); //Gauß Glocke
        printf("%d %f %f \n", 0, x, values[i][0]);
    }
    printf("\n");
}


int main()
{
    
    setStartParameters();
    runFCTS();
    return 0;
}