//!
//!
//!

#include <DspWorkUtils/stack_backtrace>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>


using namespace std;
// using namespace dsp_work_utils;

void run_basic_backtrace();

int main( int argc, char** argv )
{
    vector< string > args( argv, argv + argc );

    if ( args.at( 1 ) == string( "basic_backtrace" ) )
    {
        run_basic_backtrace();
    }
    else
    {
        fprintf( stderr, "Matching test is not exist.\n" );
        exit( -1 );
    }

    return 0;
}

void sub_func( int );
void run_basic_backtrace()
{
    sub_func( 5 );
}