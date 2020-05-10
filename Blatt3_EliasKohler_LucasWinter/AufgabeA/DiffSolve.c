#include <stdio.h>
#include <math.h>
#include <stdlib.h> 

#define pi 3.1415926

//Define basic function parameters
#define DURATION 5
#define OMEGA 5
#define X0 1
#define V0 0

static double step = 0.01;
static double values[5][500];

double function(double x, double t);

double analyticFunction(double t);

double executeSolve(void (*f)(double, double, double*, double*), int col);

void eulerStep(double x, double v, double * xp, double * vp);

void rkStep(double x, double v, double * xp, double * vp);

void lfStep(double x, double v, double * xp, double * vp);

void printValues();
int main() 
{ 
    executeSolve(eulerStep, 2);
    executeSolve(rkStep, 3);
    executeSolve(lfStep, 4);

    printValues();
    
}

//Prints values to the console
void printValues()
{
    for(int i = 0; i < 500; i++)
    {
        for(int q = 0; q < 5; q++)
            printf("%G ", values[q][i]);
        
        printf("\n");
    }
}



/** Executes iteration process to solve differential equation
 *  @params takes process function
 */
double executeSolve(void (*f)(double, double, double*, double*), int col)
{
    //Set starting values
    double x = 1;
    double v = 0;
    
    double xp, vp;
    int iterations = ceil(DURATION / step);
    
    double totalError = 0;
    double error;
    double energy;
    int index = 0;
    for(float t = 0; t < DURATION; t += step)
    {
        //Execute step function
        (*f)(x, v, &xp, &vp);

        //printf("%g %g %g \n", t, x, v);
        error = x - analyticFunction(t);
        x = xp;
        v = vp;

        energy = (v * v + OMEGA * OMEGA * x * x)/2.0;

       
        values[col][index] = x;
        values[0][index] = t;
        values[1][index] = analyticFunction(t);
    
        totalError += fabs(error);
        index++;
        //printf("%G %G\n", t, error);
        
    }

    double avgError = totalError / DURATION * step;
    return avgError;
}


//Step function for euler solve
void eulerStep(double x, double v, double* xp, double *vp)
{
    *xp = x + step * v; //Update position
    *vp = v + step * function(x, 0);
}

//Step function for leap frog solve
void lfStep(double x, double v, double * xp, double * vp)
{
    *vp = v + step*function(x, 0);
    *xp = x + step * (*vp);
}

//Step function for runge kutta level 2
void rkStep(double x, double v, double * xp, double * vp)
{
    double kx1, kv1, kx2, kv2;
    kx1 = step * v;
    kv1 = step * function(x, 0);
    kx2 = step * (v + kv1/2);
    kv2 = step * function(x + kx1/2, 0);
    *xp = x + kx2;
    *vp = v + kv2;
}

//Function f
double function(double x, double t)
{
    return -OMEGA * OMEGA * x;
}

//Analytical solution to the problem
double analyticFunction(double t)
{
    return V0/OMEGA * sin(OMEGA*t) + X0 * cos(OMEGA * t);
}