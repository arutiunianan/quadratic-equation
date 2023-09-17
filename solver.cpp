#include "solver.h"


RootsNumber SolveSquare( double a, double b, double c, double* x1, double* x2 )
{

    assert ( isfinite (a) );
    assert ( isfinite (b) );
    assert ( isfinite (c) );

    assert ( x1 != NULL );
    assert ( x2 != NULL );
    assert ( x1 != x2 );

    if ( IsEqual(a) )
    {

        if( IsEqual(b) )
        {
            return ( IsEqual(c) ) ? INF_ROOTS : NO_ROOTS;
        }
        
        if ( IsEqual(-c / b))
            *x1 = 0;
        else
            *x1 = -c / b;

        return ONE_ROOT;

    }

    double d = b * b - 4 * a * c;

    if( IsEqual(d) )
    {
        *x1 = -b / (2*a);
        return ONE_ROOT;

    }
    
    if( d < 0 )
    {
        return NO_ROOTS;
    }

    double sqrt_d = sqrt(d);

    *x1 = (-b - sqrt_d) / (2*a);
    *x2 = (-b + sqrt_d) / (2*a);

    return TWO_ROOTS;

}


int IsEqual( double num )
{

    const double accuracy = 1e-6;

    return fabs(num) < accuracy;

}

