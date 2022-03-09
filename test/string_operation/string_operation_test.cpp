//!
//!
//!


#include "string_operation"

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;
using namespace dsp_work_utils;

void test_format();
void test_split_char();

int main( int argc, char** argv )
{
    vector< string > args( argv, argv + argc );

    if ( args.at( 1 ) == string( "format" ) )
    {
        test_format();
    }
    else if ( args.at( 1 ) == string( "split_char" ) )
    {
        test_split_char();
    }
    else
    {
        fprintf( stderr, "Matching test is not exist.\n" );
        exit( -1 );
    }

    return 0;
}

void test_format()
{
    double a = 3.0;
    double ans = 9.0;

    printf( "%2.2fの二乗は%2.2fです。", a, ans );

    auto str_result = format( "%2.2fの二乗は%2.2fです。", a, ans );
    assert( string( "3.00の二乗は9.00です。" ) == str_result );
}

void test_split_char()
{
    // separator = ','
    string base_str1( "No,test,try,success,fail" );
    auto split_str1 = split_char( base_str1, ',' );

    assert( 5 == split_str1.size() );
    assert( string( "No" ) == split_str1.at( 0 ) );
    assert( string( "test" ) == split_str1.at( 1 ) );
    assert( string( "try" ) == split_str1.at( 2 ) );
    assert( string( "success" ) == split_str1.at( 3 ) );
    assert( string( "fail" ) == split_str1.at( 4 ) );

    // separator = ':'
    string base_str2( "bird:cat:dog:dolphin:sheep:giraf:pig" );
    auto split_str2 = split_char( base_str2, ':' );

    assert( 7 == split_str2.size() );
    assert( string( "bird" ) == split_str2.at( 0 ) );
    assert( string( "cat" ) == split_str2.at( 1 ) );
    assert( string( "dog" ) == split_str2.at( 2 ) );
    assert( string( "dolphin" ) == split_str2.at( 3 ) );
    assert( string( "sheep" ) == split_str2.at( 4 ) );
    assert( string( "giraf" ) == split_str2.at( 5 ) );
    assert( string( "pig" ) == split_str2.at( 6 ) );
}