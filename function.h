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
int ReadingFile( char* argv[], double* a, double* b, double* c, double* x1test, double* x2test, enum RootsNumber* nRootsTest );
//int ReadingFile( double* a, double* b, double* c, double* x1test, double* x2test, enum RootsNumber* nRootsTest );
void PrintRootsTest( enum RootsNumber nRoots, enum RootsNumber nRootsTest, double x1, double x2, double x1test, double x2test );


#endif // #define FUNCTION_H_