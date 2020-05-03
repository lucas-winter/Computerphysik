#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXCHAR 500

///Computes the deteriminant of a 2x2 matrix
float determinant( float matrix[2][2])
{
    return matrix[0][0]*matrix[1][1] - matrix[1][0]*matrix[0][1];
}

//Requests 2x2 matrix from user 
void getMatrix( float matrix[2][2] )
{
    int size = 2;
    for(int x = 0; x < size; x++)
    {
        for(int y = 0; y < size; y++)
        {
            printf("Please enter a number for field [%d, %d]\n", x, y);
            scanf("%f", &matrix[x][y]);
        }
    }
}

//reads matrix from a .txt file
void readFile( float matrix[2][2], char* filename)
{
    FILE *fp;
    
    fp = fopen(filename, "r");
    if(fp == NULL)                 //quit if file is invalid
    {
        printf("Could not open file");
        return;
    }

    //Read file
    char str[MAXCHAR];
    int index = 0;
    while(fgets(str, MAXCHAR, fp) != NULL)
    {
        //Compute matrix indices
        int x = index % 2;
        int y = (index / 2) % 2;

        matrix[x][y] = (float) atof(str);
        index++;
    }
    //Close file
    fclose(fp);
}


int main(int argc, char * argv[])
{
    float matrix[2][2];
    if(argc == 1)
        getMatrix(matrix);
    else
        readFile(matrix, argv[1]);
    
    
    printf("Determinant is %f \n", determinant(matrix));
}