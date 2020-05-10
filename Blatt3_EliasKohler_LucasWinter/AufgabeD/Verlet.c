#include <stdio.h>
#include <math.h>

#define H 0.005
#define MAXT 1000
#define OMEGA 1.0
#define STEPCOUNT 200000
#define X0 1
#define V0 0

#define F 0.2
static float values[STEPCOUNT];
static float D = 0;
static float omega = 0.5;

void verlet();

float fFunction(float t);

float differentiate();

float findAmplitude();

int main()
{
    values[0] = X0;
    values[1] = X0 + H * V0;

    float dampStep = 0.003;
    float omegaStep = 0.015;
    for(float d = 2*dampStep; d < 0.16; d+=dampStep)
    {
        D = d;
        for(float o = 0.6; o < 1.5; o+= omegaStep)
        {
            omega = o;
            verlet();
            float amp = findAmplitude(STEPCOUNT - 2);
            printf("%f %f %f\n", omega,D, amp);
        }
        printf("\n");
    }
    
    return 0;
}

float findAmplitude(int start)
{
    int slope = differentiate(start) < 0 ? -1 : 1;
    for(int i = start - 1; i > 0; i--)
    {
        int currentSlope = differentiate(i) < 0 ? -1 : 1;
        if(currentSlope != slope)
        {
            return fabs(values[i]);
        }
    }

    printf("ERROR: Point of last amplitude not found\n");
    return 0.0;
}
void verlet()
{
    float t;
    for(int i = 2; i < STEPCOUNT; i += 1)
    {
        t = i*H;
        float alpha = fFunction(t);
        float c1  = 2.0*H*H*alpha;
        float c2 = 2*values[i-1]*(2.0 - H*H*OMEGA*OMEGA);
        float c3 = values[i-2]*(D*H-2);
        values[i] = 1.0/(2.0+D*H)*(c1 + c2 + c3);
        //printf("%f %f\n", t,values[i]);
    }

}

float differentiate(int i)
{
    return (values[i + 1] - values[i - 1])/(2 * H); 
}

float fFunction(float t)
{
    return F*sin(omega* t);
}