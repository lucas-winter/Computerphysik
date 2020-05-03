#include <stdio.h>
#include<stdlib.h>

/**
 * Computes start of a given layer
 * */
int computeLayerStart(int layer)
{
    if(layer == 0)
    {
        return layer;
    }
    return layer*(layer - 1) + 1;
}


/**creates pascal triangle and store in array
 */
void createPascal(int n, int pascal[])
{
    
    pascal[0] = 1;

    //Loop over all layers of pascal triangle
    for(int layer = 1; layer < n; layer++)
    {
        //Set Bounds to 1
        int lBound = computeLayerStart(layer);
        int rBound  = lBound + layer;
        pascal[lBound] = 1;
        pascal[rBound] = 1;

        //Compute elements between bounds
        for(int i = lBound + 1; i < rBound; i++)
        {
            int prev = computeLayerStart(layer - 1) + i - lBound - 1;
            pascal[i] = pascal[prev] + pascal[prev + 1];
        }
        
    }
    
}

/**Print pascal Triangle
 */
void printPascal(int pascal[], int n)
{
    printf("printing....\n");
    for(int layer = 0; layer < n; layer++)
    {
        //Formatting
        int blanks = (n - layer + 1) /2;
        for(int b = 0; b < blanks; b++)
            printf("  ");

        if(layer % 2 == 1)
            printf(" ");

        //Print individual elements
        int lStart = computeLayerStart(layer);
        for(int q = 0;  q < layer + 1; q++)
        {
            printf("%d ", pascal[q + lStart]);
        }
        printf("\n");
    }
}

int main()
{
    int n = 7;
    int size = (n + 1)*(n+2)/2;
    int * pascal = (int *) malloc(size * sizeof(int));
    createPascal(n, pascal);
    printPascal(pascal, n);
}
