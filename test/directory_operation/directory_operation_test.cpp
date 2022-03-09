//!
//!
//!


#include "dirctory_operation"

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>


using namespace std;
using namespace dsp_work_utils;

void run_exist_directory();
void run_make_directory();

int main( int argc, char** argv )
{
    vector< string > args( argv, argv + argc );

    if ( args.at( 1 ) == string( "exist_directory" ) )
    {
        run_exist_directory();
    }
    else if ( args.at( 1 ) == string( "make_directory" ) )
    {
        run_make_directory();
    }
    else
    {
        fprintf( stderr, "Matching test is not exist.\n" );
        exit( -1 );
    }

    return 0;
}

void run_exist_directory()
{
    if ( exist_directory( string( "./test_exist_dir" ) ) )
    {
        printf( "exist\n" );
    }
    else
    {
        printf( "not exist\n" );
    }
    if ( exist_directory( string( "./test_dir" ) ) )
    {
        printf( "exist\n" );
    }
    else
    {
        printf( "not exist\n" );
    }
}

void run_make_directory()
{
    make_directory( string( "./test_make_dir" ) );
}