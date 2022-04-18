//!
//!
//!


#include <DspWorkUtils/file>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>


using namespace std;
using namespace dsp_work_utils;

void run_fileopen();
void test_file_size();

int main( int argc, char** argv )
{
    vector< string > args( argv, argv + argc );

    if ( args.at( 1 ) == string( "fileopen" ) )
    {
        run_fileopen();
    }
    else if ( args.at( 1 ) == string( "file_size" ) )
    {
        test_file_size();
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
    // read test
    FILE* fp = fileopen( string( "./test_data.txt" ), "r" );
    fclose( fp );

    // write test(create files)
    fp = fileopen( string( "./test_data_.txt" ), "w" );
    fclose( fp );
    fp = fileopen( string( "./test_data_.txt" ), "r" );
    fclose( fp );

    // mode test
    fp = fileopen( "./test.dat", "rb" );
    fclose( fp );
    fp = fileopen( "./test_write.dat", "wb" );
    fclose( fp );

    /* Using exception is not recomended from LLVM.
        // error test
        try
        {
            fp = fileopen( "./test_da.txt", "r" );    // error(例外)発生
        }
        catch ( std::runtime_error e )    // 例外種別関係なくキャッチ
        {
            std::cerr << "some_exception: " << e.what() << std::endl;
            try
            {
                fp = fileopen( "./test_data.txt", "hoge" );    // error(例外)発生
            }
            catch ( std::invalid_argument e )    // 例外種別関係なくキャッチ
            {
                std::cerr << "some_exception: " << e.what() << std::endl;
                return;
            }
        }
        exit( EXIT_FAILURE );
    */
}

void test_file_size()
{
    string filename1( "./test.dat" );
    assert( 864000 == file_size( filename1 ) );

    string filename2( "./test.wav" );
    assert( 288044 == file_size( filename2 ) );
}