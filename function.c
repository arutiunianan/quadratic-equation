#include "function.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <string.h>



// 0.00001 * 100000 = 1.00000000001
// 
// 1   2 1  -1 
// a, b, c, x1, x2
// TestSquareSolver()
//

enum RootsNumber SolveSquare(double a, double b, double c, double* x1, double* x2)
{

    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));

    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    // isEqual
    if ( IsEqual(a) == IsZero )
    {

        if( IsEqual(b) == IsZero )
        {

            return ( IsEqual(c) == IsZero ) ? INF_ROOTS : NO_ROOTS;

        }
        
        *x1 = -c / b;
        return ONE_ROOT;

    }

    double d = b * b - 4 * a * c;

    if( IsEqual(d) == IsZero )
    {

        *x1 = -b / (2*a);
        return ONE_ROOT;

    }
    
    if( d < 0 )
        return NO_ROOTS;

    double sqrt_d = sqrt(d);

    *x1 = (-b - sqrt_d) / (2*a);
    *x2 = (-b + sqrt_d) / (2*a);

    return TWO_ROOTS;

}

void PrintRoots( enum RootsNumber nRoots, double x1, double x2 )
{

    switch (nRoots)
    {
        case NO_ROOTS:  
            printf("No roots\n");
            break;

        case ONE_ROOT: 
            printf("x1 = %lg\n", x1, x2);
            break;
        
        case TWO_ROOTS: 
            printf("x1 = %lg, x2 = %lg\n", x1, x2);
            break;

        case INF_ROOTS: 
            printf("Any number\n");
            break;

        default: printf("main(): ERROR: nRoots = %d\n", nRoots);
        
    }

}


enum ValueOfNumber IsEqual( double num )
{
    return fabs(num) < e ? IsZero : IsNotZero;
}

int ReadingFile( char* argv[], double* a, double* b, double* c, double* x1test, double* x2test, enum RootsNumber* nRootsTest )
{

    assert (a != NULL);
    assert (b != NULL);
    assert (c != NULL);
    assert (x1test != NULL);
    assert (x2test != NULL);
    assert (nRootsTest != NULL);
    assert (x1test != x2test);
    assert (a != b);
    assert (a != c);
    assert (a != x1test);
    assert (a != x2test);
    assert (b != c);
    assert (b != x1test);
    assert (b != x2test);
    assert (c != x1test);
    assert (c != x2test);
    assert (x1test != x2test);

    FILE *test;
    char name[strlen(argv[1]) + 1];
    strcpy( name, argv[1] );

    if ((test = fopen(name, "r")) == NULL)
    {
        printf( "The file could not be opened\n" );
        return 0;
    }


    char RootsNum[10];
    if( fscanf( test, "%lg %lg %lg %lg %lg %s", a, b, c, x1test, x2test, RootsNum ) != 6 )
        return 0;

    if( !strcmp ( RootsNum, "NO_ROOTS" ) )
        nRootsTest = NO_ROOTS;
    else if( !strcmp ( RootsNum, "ONE_ROOT" ) )
        nRootsTest = ONE_ROOT;
    else if( !strcmp ( RootsNum, "TWO_ROOTS" ) )
        nRootsTest = TWO_ROOTS;
    else if( !strcmp ( RootsNum, "INF_ROOTS" ) )
        nRootsTest = INF_ROOTS;
    else
    {
        printf("Incorrectly entered data\n");
        return 0;
    }

    printf("+%x+\n",&nRootsTest);

    return 1;


}

void PrintRootsTest( enum RootsNumber nRoots, enum RootsNumber nRootsTest, double x1, double x2, double x1test, double x2test )
{

    if( nRoots == nRootsTest  &&  x1 == x1test  &&  x2 == x2test )
        printf("Test is succesful:)\n");

    else
    {
        printf("Test is not succesful:(\nWhat was expected: ");
        PrintRoots( nRootsTest, x1test, x2test );
        printf("Result of program: ");
        PrintRoots( nRoots, x1, x2 );

    }

}