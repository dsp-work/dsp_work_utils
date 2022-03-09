//!
//!
//!


#include "file_operation"

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>


using namespace std;
using namespace dsp_work_utils;

void run_fileopen();

int main( int argc, char** argv )
{
    vector< string > args( argv, argv + argc );

    if ( args.at( 1 ) == string( "fileopen" ) )
    {
        run_fileopen();
    }
    else
    {
        fprintf( stderr, "Matching test is not exist.\n" );
        exit( -1 );
    }

    return 0;
}

void run_fileopen()
{
    // resd test
    FILE* fp = fileopen( string( "./test_data.txt" ), 'r', __FILE__, __LINE__ );
    fclose( fp );

    // write test(create files)
    fp = fileopen( string( "./test_data_.txt" ), 'w', __FILE__, __LINE__ );
    fclose( fp );
    fp = fileopen( string( "./test_data_.txt" ), 'r', __FILE__, __LINE__ );
    fclose( fp );
}