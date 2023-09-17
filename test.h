#ifndef TEST_H_
#define TEST_H_

#include <string.h>

#include "solver.h"


// struct TestData
// { RootsNumber; double x1, x2;}

Errors DoTest( double* a, double* b, double* c, double* x1test, double* x2test,
               char* RootsNum, RootsNumber* nRootsTest, double* x1, double* x2 );

Errors StrToRootsNum( char* RootsNum, RootsNumber* nRootsTest );

Errors ReadTests( FILE *test, double* a, double* b, double* c, double* x1test, 
                  double* x2test, RootsNumber* nRootsTest, double* x1, double* x2 );

void PrintRootsTest( RootsNumber nRoots, RootsNumber nRootsTest, double x1, 
                     double x2, double x1test, double x2test );

void ErrorHandling( Errors err );

#endif // #define TEST_H_