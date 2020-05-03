#include <stdio.h>




int main() 
{
    //Test cases
    int a = 5;
    float f = 2.332;
    double d = 2;
    char c = 'a';
    long l =  5;
    short s = 3;
    

    printf("int size: %d\n", sizeof(a));
    printf("float size: %d\n", sizeof(f));
    printf("double size: %d\n", sizeof(d));
    printf("char size: %d\n", sizeof(c));
    printf("long size: %d\n", sizeof(l));
    printf("short size: %d\n", sizeof(s));
  
    return 0;
}

