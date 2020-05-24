#include <stdio.h>
#include <math.h>


//Solving Parameters
#define SCOUNT 20000
#define RANGE 20
double ssize = ((float) RANGE)/((float) SCOUNT);
double fval[SCOUNT];
double epsilon = 2;
double chi[SCOUNT];
double phi[SCOUNT];


double c1 = 0;
double c2 = 0;

//charge density
double calculateRho(double r)
{
    return exp(-r)/(8.0*M_PI);
}

double calculateF(double r)
{
    return -r * calculateRho(r)/(epsilon);
}

double analyticalSolutionPhi(double r)
{
    return (1./r - ((1./r + 1./2.)*exp(-r)))/(4.*M_PI*epsilon);
}

double analyticalSolutionChi(double r)
{
    return (1. - ((1. + r/2.)*exp(-r)))/(4.*M_PI*epsilon);
}


//Perferms numerov procedure to solve differential equation
void Numerov()
{
    for(int i = 2; i < SCOUNT; i++)
    {
        //Calculate r for different steps
        double prevPrevR = (i - 2)*ssize;
        double prevR = (i - 1)*ssize;
        double curR = i * ssize;

        //Calculate numorov step
        double a1 = (calculateF(curR) + 10. * calculateF(prevR) + calculateF(prevPrevR))*ssize*ssize/((float) 12.);
        chi[i] = a1 + 2. * chi[i - 1] - chi[i - 2]; 
        phi[i] = chi[i]/curR;
    }
}

//Subtracts linear term from solution
double correct(double r, double val)
{
   double slope = (chi[SCOUNT - 10] - chi[SCOUNT - 20])/(10.*ssize);
   return val - slope * r;
}

//Prints solution to console
void printResults()
{

    for(int i = 2; i < SCOUNT; i++)
    {
        double curR = i * ssize;
        //Format: r chi(numerov), chi(corrected numorov), chi(analytical)
        printf("%f %f %f %f \n", curR, chi[i], correct(curR, chi[i]), analyticalSolutionChi(curR));
    }
}

//Sets start parameters
void initializeParameters()
{
    chi[0] = 0;
    chi[1] = 1*ssize;
    phi[1] = chi[1]/ssize;
}

int main()
{
    initializeParameters();
    Numerov();
    printResults();
}
