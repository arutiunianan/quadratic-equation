#include "function.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{    
    double a = 0;
    double b = 0;
    double c = 0;
    char words[100];

    double x1 = 0;
    double x2 = 0;

    //scanf ("%lg %lg %lg", &a, &b, &c);

    // поправить сканф на выявление ошибок
    if ( argc == 1 ) 
    {
        printf (" Enter a, b, c: ");

        while (scanf("%lg %lg %lg", &a, &b, &c) != 3)
        {
            scanf("%s\n", words);
            printf("Enter only numbers: ");
        }

        enum RootsNumber nRoots = SolveSquare (a, b, c, &x1, &x2);

        PrintRoots( nRoots, x1, x2 );
    }

    else if( argc == 2 )
    {

        double x1test = 0;
        double x2test = 0;
        enum RootsNumber nRootsTest;
        printf("+%x+\n",&nRootsTest);
        if( ReadingFile( argv, &a, &b, &c, &x1test, &x2test,  &nRootsTest ) == 0)
        {
            return 0;
        }

        enum RootsNumber nRoots = SolveSquare (a, b, c, &x1, &x2 );

        PrintRootsTest( nRoots, nRootsTest, x1, x2, x1test, x2test );
    }

    else
        printf( "Invalid number of args to program." );

}