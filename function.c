#include "function.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

enum RootsNumber SolveSquare(double a, double b, double c, double* x1, double* x2)
{

    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));

    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    if (a == 0)
    {

        if(b == 0)
        {

            return (c == 0)? INF_ROOTS : NO_ROOTS;

        }
        else
        {

            *x1 = -c / b;
            return ONE_ROOT;

        }

    }
    else
    {

        double d = b*b - 4*a*c;

        if(d ==0)
        {

            *x1 = *x2 = -b / (2*a);
            return ONE_ROOT;

        }
        else
        {

            double sqrt_d = sqrt(d);

            *x1 = (-b - sqrt_d) / (2*a);
            *x2 = (-b + sqrt_d) / (2*a);

            return TWO_ROOTS;

        }

    }

}