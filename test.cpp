#include "test.h"

Errors ReadTests( FILE *test, double* a, double* b, double* c, double* x1test,
                  double* x2test, RootsNumber* nRootsTest, double* x1, double* x2 )
{
    assert ( a != NULL );
    assert ( b != NULL );
    assert ( c != NULL );
    assert ( x1test != NULL );
    assert ( x2test != NULL );
    assert ( nRootsTest != NULL );
    assert ( test );

    const int roots_num_len = 10;
    char RootsNum[roots_num_len] = {};

    while( fscanf( test, "%lg %lg %lg %lg %lg %s", 
                   a, b, c, x1test, x2test, RootsNum ) != EOF )
    {
        DoTest( a, b, c, x1test, x2test, RootsNum, nRootsTest, x1, x2 );
        *x1 = 0;
        *x2 = 0;

    }


}


Errors DoTest( double* a, double* b, double* c, double* x1test, double* x2test,
               char* RootsNum, RootsNumber* nRootsTest, double* x1, double* x2 )
{

    if( StrToRootsNum( RootsNum, nRootsTest ) != NO_ERRORS )
        return ENTERED_DATA_ERROR;


    RootsNumber nRoots = SolveSquare ( *a, *b, *c, x1, x2 );

    PrintRootsTest( nRoots, *nRootsTest, *x1, *x2, *x1test, *x2test );

    return NO_ERRORS;

}

void PrintRootsTest( RootsNumber nRoots, RootsNumber nRootsTest, double x1, 
                     double x2, double x1test, double x2test )
{

    if( nRoots == nRootsTest  &&  x1 == x1test  &&  x2 == x2test )
        printf( "\nTest is succesful:)\n\n" );

    else
    {
        printf( "\nTest is not succesful:(\n"
               "What was expected: " );
        printf( "nRoots = %d\n", nRootsTest );
        printf( "x1 = %lf, x2 = %lf\n",
               x1test, x2test );

        printf( "Result of program: " );
        printf( "nRoots = %d\n", nRoots );
        printf( "x1 = %lf, x2 = %lf\n\n",
               x1, x2 );

    }

}

Errors StrToRootsNum( char* RootsNum, RootsNumber* nRootsTest  )
{
    if( !strcmp ( RootsNum, "NO_ROOTS" ) )
        *nRootsTest = NO_ROOTS;

    else if( !strcmp ( RootsNum, "ONE_ROOT" ) )
        *nRootsTest = ONE_ROOT;

    else if( !strcmp ( RootsNum, "TWO_ROOTS" ) )
        *nRootsTest = TWO_ROOTS;

    else if( !strcmp ( RootsNum, "INF_ROOTS" ) )
        *nRootsTest = INF_ROOTS;

    else
    {
        printf("Incorrectly entered data\n");
        return ENTERED_DATA_ERROR;
    }

    return NO_ERRORS;

}

void ErrorHandling( Errors err )
{
    switch( err )
    {

         case FILE_OPEN_ERROR:  
            printf( "The file could not be opened\n" );
            break;

        case ENTERED_DATA_ERROR: 
            printf( "Incorrect data entered in the file\n" );
            break;
        
        case ARGS_NUM_ERROR: 
            printf( "Invalid number of args to program" );
            break;

    }


}
