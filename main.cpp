#include "test.h"
#include "io.h"
#include "solver.h"

int main( int argc, const char* argv[] )
{    
    double a = 0;
    double b = 0;
    double c = 0;

    double x1 = 0;
    double x2 = 0;

    Errors err = NO_ERRORS;

    if ( argc == 1 ) 
    {
        printf (" Enter a, b, c: ");
        InputCoeffs( &a, &b, &c );

        RootsNumber nRoots = SolveSquare ( a, b, c, &x1, &x2 );

        PrintRoots( nRoots, x1, x2 );
    }

    else if( argc == 2 )
    {

        FILE *test = fopen( argv[1], "r" );

        double x1test = 0;
        double x2test = 0;
        RootsNumber nRootsTest = NO_ROOTS;

        if ( test == NULL )
            err == FILE_OPEN_ERROR;
        else
            err = ReadTests( test, &a, &b, &c, &x1test, &x2test,  &nRootsTest,
                            &x1, &x2 );

    }

    else
        err = ARGS_NUM_ERROR;


    ErrorHandling( err );

}