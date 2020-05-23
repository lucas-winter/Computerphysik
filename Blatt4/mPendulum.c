#include <stdio.h>
#include <math.h>
#include <stdlib.h>


//System 1111
#define MCOUNT 3
#define MRAD 0.4
#define OMEGA 0.6
#define GAMMA 0.35
#define MAGSTRENGTH -1
#define Z 0.2
//Solving parameters

#define DURATION 5000
#define SCOUNT 100000
const float ssize = ((float)DURATION)/((float)SCOUNT);

//Define basic vector struct with basic methods
struct vector
{
    float val[2];
}; 
struct vector magnetPos[MCOUNT];

struct vector position[SCOUNT]; 

struct vector addVec(struct vector vec1, struct vector vec2 )
{
    struct vector result;
    for(int i = 0; i < 2;i++)
        result.val[i] = vec1.val[i] + vec2.val[i];

    return result;
}

struct vector addVecTo(struct vector *vec1, struct vector vec2 )
{
    for(int i = 0; i < 2;i++)
        (*vec1).val[i] += vec2.val[i];
}

struct vector multiply(struct vector vec, float scalar)
{
    struct vector result;
    for(int i = 0; i < 2; i++)
        result.val[i] = vec.val[i] * scalar;

    return result;
}

struct vector createVec(float x, float y)
{
    struct vector vec;
    vec.val[0] = x;
    vec.val[1] = y;
    return vec;
};


float magnitude(struct vector vec)
{
    
    return sqrtf(powf(vec.val[0], 2) + powf(vec.val[1], 2));
}

void printVec(struct vector vec)
{
    for(int i = 0; i < 2; i++)
        printf("%f ", vec.val[i]);

    printf("\n");
}

struct vector negate(struct vector vec)
{
    struct vector result;
    for(int i = 0; i < 2; i++)
        result.val[i] = -vec.val[i];

    return result;
}


struct vector computeForces(struct vector position, struct vector velocity)
{
    struct vector result = createVec(0,0);
    //Add magnet forces
    for(int m = 0; m < MCOUNT; m++)
    {
        struct vector diff = addVec(position, negate(magnetPos[m]));
        float mag = sqrt(pow(magnitude(diff),2) + Z*Z);
        float temp = powf(mag, 3);
     
        addVecTo(&result, multiply(diff, temp == 0 ? 0 : MAGSTRENGTH/temp));
    }

    //Add Rückstellkraft
    addVecTo(&result, multiply(position, -OMEGA*OMEGA));

    //Add resitance forve
    addVecTo(&result, multiply(velocity, -GAMMA));

    return result;
}

void initializeMagnets()
{
    float w = 2*M_PI/MCOUNT;
    for(int i = 0; i < MCOUNT; i++)
    {
        magnetPos[i].val[0] = MRAD * cosf(w*i);
        magnetPos[i].val[1] = MRAD * sinf(w*i);
    }
}

void initalizeStartParameters(float x0, float y0, float vx0, float vy0)
{
    position[0] = createVec(x0, y0);
    position[1] = createVec(x0 + ssize * vx0, y0 + ssize *vy0);
}

void printVerlet()
{
    
    for(int i = 2; i < SCOUNT; i++)
    {
        struct vector velocity = multiply(addVec(position[i - 1], negate(position[i - 2])), 1 / ssize);
        struct vector f = computeForces(position[i - 1], velocity);
        struct vector newPos = addVec(multiply(position[i - 1], 2), multiply(f, ssize*ssize));
        addVecTo(&newPos, negate(position[i - 2]));

        position[i] = newPos;

        //Print
        float t = i * ssize;
        printf("%f %f %f\n", t, newPos.val[0], newPos.val[1]);
    }
}

struct vector differentiate(int i)
{
    return multiply(addVec(position[i + 1], negate(position[i - 1])), 1/(2*ssize));
}
float computeAverageMovement(int startI, int endI)
{
    struct vector sum = createVec(0,0);
    for(int i = startI; i < endI; i++)
        addVecTo(&sum, differentiate(i));

    return magnitude(sum)/(endI - startI);
}

struct vector computeEndPosition(float startX, float startY)
{
    for(int i = 2; i < SCOUNT; i++)
    {
        struct vector velocity = multiply(addVec(position[i - 1], negate(position[i - 2])), 1 / ssize);
        struct vector f = computeForces(position[i - 1], velocity);
        struct vector newPos = addVec(multiply(position[i - 1], 2), multiply(f, ssize*ssize));
        addVecTo(&newPos, negate(position[i - 2]));

        position[i] = newPos;

        //Print
        if(i % 12 == 0)
        {
            if(computeAverageMovement(i - 1, i - 6) < 0.01)
                return position[i];
        }

        
    }

    return position[SCOUNT - 1];
}

int getClosestMagnet(struct vector pos)
{
    float minDist = powf(10, 8);
    int mag = -1;
    for(int i = 0; i < MCOUNT; i++)
    {
        float dist = magnitude(addVec(pos, negate(magnetPos[i])));
        if(dist < minDist)
        {
            minDist = dist;
            mag = i; 
        }
    }

    return mag;
}

void printEndPosition()
{
    float res = 0.02;
    float size = 2;
    for(float x = -size; x < size; x+=res)
    {
        for(float y = -size; y < size; y+=res)
        {
            initalizeStartParameters(x,y,0,0);
            struct vector endPos = computeEndPosition(x,y);
            int mag = getClosestMagnet(endPos);
            printf("%f %f %i \n", x, y, mag);
        }
    }
}


int main()
{
    initializeMagnets();
    initalizeStartParameters(0.6,0.5,0,-1);
    //printVerlet();
    printEndPosition();
    
    return 1;

}