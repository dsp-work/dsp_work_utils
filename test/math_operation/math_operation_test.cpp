//!
//!
//!


#include "math_operation"

#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>


using namespace std;
using namespace dsp_work_utils;

void test_pow2();

int main( int argc, char** argv )
{
    vector< string > args( argv, argv + argc );

    if ( args.at( 1 ) == string( "pow2" ) )
    {
        test_pow2();
    }
    else
    {
        fprintf( stderr, "Matching test is not exist.\n" );
        exit( -1 );
    }

    return 0;
}

void test_pow2()
{
    double a = 3.0;
    double ans = 9.0;
    const unsigned int acc = 1000;    // 10^-n(小数点以下n桁)まで精度を検査

    printf( "output: %.15f\n", static_cast< double >( static_cast< long int >( std::round( ans * acc ) ) ) / static_cast< double >( acc ) );
    printf( "correct: %.15f\n", static_cast< double >( static_cast< long int >( std::round( pow2( a ) * acc ) ) ) / static_cast< double >( acc ) );
    assert( static_cast< long int >( std::round( ans * acc ) ) == static_cast< long int >( std::round( pow2( a ) * acc ) ) );
}