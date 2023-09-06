#ifndef FUNCTION_H_
#define FUNCTION_H_

#define e 0.00001

enum ValueOfNumber
{
    IsZero,
    IsNotZero
};

enum RootsNumber
{
    NO_ROOTS,
    ONE_ROOT, 
    TWO_ROOTS,
    INF_ROOTS
};

enum RootsNumber SolveSquare (double a, double b, double c, double* x1, double* x2);
void PrintRoots( enum RootsNumber nRoots, double x1, double x2 );
enum ValueOfNumber IsEqual( double num );


#endif // #define FUNCTION_H_