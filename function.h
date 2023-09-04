#ifndef FUNCTION_H_
#define FUNCTION_H_

#include <float.h>

#define SS_INF_ROOTS DBL_MAX

enum RootsNumber
{
    NO_ROOTS,
    ONE_ROOT, 
    TWO_ROOTS,
    INF_ROOTS
};

enum RootsNumber SolveSquare (double a, double b, double c, double* x1, double* x2);

#endif // #define FUNCTION_H_