#include "function.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>



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

        *x1 = *x2 = -b / (2*a);
        return ONE_ROOT;

    }
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
            printf("x = %lg\n", x1);
            break;
        
        case TWO_ROOTS: 
            printf("x1 = %lg, x2 = %lg\n", x1, x2);
            break;

        case INF_ROOTS: 
            printf("Any number");
            break;

        default: printf("main(): ERROR: nRoots = %d\n", nRoots);
        
    }

}


enum ValueOfNumber IsEqual( double num )
{
    return fabs(num) < e ? IsZero : IsNotZero;
}