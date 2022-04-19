//!
//!
//!


#include <DspWorkUtils/file>
#include <DspWorkUtils/string>    // necessary for test
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

#ifdef _WIN32
    #include <windows.h>
#endif

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
#ifdef _MSC_VER
    char Path[MAX_PATH + 1];

    printf( "check full path\n" );
    if ( 0 != GetModuleFileName( NULL, Path, MAX_PATH ) )
    {    // 実行ファイルの完全パスを取得

        char drive[MAX_PATH + 1], dir[MAX_PATH + 1], fname[MAX_PATH + 1], ext[MAX_PATH + 1];

        //パス名を構成要素に分解します
        _splitpath_s( Path, drive, sizeof( drive ), dir, sizeof( dir ), fname, sizeof( fname ), ext, sizeof( ext ) );

    #ifdef DEBUG
        printf( "完全パス : %s\n", Path );
        printf( "ドライブ : %s\n", drive );
        printf( "ディレクトリ パス : %s\n", dir );
        printf( "ベース ファイル名 (拡張子なし) : %s\n", fname );
        printf( "ファイル名の拡張子 : %s\n", ext );
    #endif
        // read test
        FILE* fp = fileopen( format( "%s\\%s\\test_data.txt", drive, dir ), "r" );
        fclose( fp );

        // write test(create files)
        fp = fileopen( format( "%s\\%s\\test_data_.txt", drive, dir ), "w" );
        fclose( fp );
        fp = fileopen( format( "%s\\%s\\test_data_.txt", drive, dir ), "r" );
        fclose( fp );

        // mode test
        fp = fileopen( format( "%s\\%s\\test.dat", drive, dir ), "rb" );
        fclose( fp );
        fp = fileopen( format( "%s\\%s\\test_write.dat", drive, dir ), "wb" );
        fclose( fp );
    }
    else
    {
        exit( EXIT_FAILURE );
    }
#else
    // read test
    FILE* fp = fileopen( string( "./test_data.txt" ), "r" );
    fprintf( fp, "testtest" );
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
#endif

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
#ifdef _MSC_VER
    char Path[MAX_PATH + 1];

    printf( "check full path\n" );
    if ( 0 != GetModuleFileName( NULL, Path, MAX_PATH ) )
    {    // 実行ファイルの完全パスを取得

        char drive[MAX_PATH + 1], dir[MAX_PATH + 1], fname[MAX_PATH + 1], ext[MAX_PATH + 1];

        //パス名を構成要素に分解します
        _splitpath_s( Path, drive, sizeof( drive ), dir, sizeof( dir ), fname, sizeof( fname ), ext, sizeof( ext ) );

    #ifdef DEBUG
        printf( "完全パス : %s\n", Path );
        printf( "ドライブ : %s\n", drive );
        printf( "ディレクトリ パス : %s\n", dir );
        printf( "ベース ファイル名 (拡張子なし) : %s\n", fname );
        printf( "ファイル名の拡張子 : %s\n", ext );
    #endif
        string filename1( format( "%s\\%s\\test.dat", drive, dir ) );
        assert( 864000 == file_size( filename1 ) );

        string filename2( format( "%s\\%s\\test.wav", drive, dir ) );
        assert( 288044 == file_size( filename2 ) );
    }
    else
    {
        exit( EXIT_FAILURE );
    }
#else
    string filename1( "./test.dat" );
    assert( 864000 == file_size( filename1 ) );

    string filename2( "test.wav" );
    assert( 288044 == file_size( filename2 ) );
#endif
}