#ifndef SOLVER_H_
#define SOLVER_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

typedef enum RootsNumber
{
    NO_ROOTS,
    ONE_ROOT, 
    TWO_ROOTS,
    INF_ROOTS
} RootsNumber;

typedef enum Errors
{
    NO_ERRORS,
    FILE_OPEN_ERROR,
    ENTERED_DATA_ERROR,
    ARGS_NUM_ERROR

} Errors;

RootsNumber SolveSquare (double a, double b, double c, double* x1, double* x2);

int IsEqual( double num );

#endif // #define SOLVER_H_