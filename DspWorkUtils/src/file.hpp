//!
//! @file File.hpp
//! @brief ファイル操作関係のモジュール
//! @details
//!

#ifndef DSPWORK_FILE_HPP_
#define DSPWORK_FILE_HPP_

#include <DspWorkUtils/string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
#include <sys/stat.h>


namespace dsp_work_utils
{
    ///
    /// @brief 指定のモードでファイルを開く。正しくファイルを開けたかのチェック機構付き
    /// @param[in] filename 開くファイルのパス
    /// @param[in] mode fopenと同じ用法
    /// @return FILE* 開いたファイルのポインタ
    /// @details 開くファイルのパスは絶対パスや実行ファイルからの相対パスで指定する。
    ///
    inline FILE* fileopen(
        const std::string filepath,
        const std::string mode )
    {
        // mode checking
        if ( mode != std::string( "r" ) && mode != std::string( "w" ) && mode != std::string( "a" ) && mode != std::string( "rb" ) && mode != std::string( "wb" ) && mode != std::string( "ab" ) && mode != std::string( "r+" ) && mode != std::string( "w+" ) && mode != std::string( "a+" ) && mode != std::string( "r+b" ) && mode != std::string( "rb+" ) && mode != std::string( "w+b" ) && mode != std::string( "wb+" ) && mode != std::string( "a+b" ) && mode != std::string( "ab+" ) )
        {
            fprintf(
                stderr,
                "The mode is require 'r'(read), 'w'(write),...others. Input is %s. See official `fopen` documents.\n",
                mode.c_str() );
            exit( EXIT_FAILURE );
        }

        FILE* fp = NULL;
#ifdef _MSC_VER
        errno_t error = fopen_s( &fp, filepath.c_str(), mode.c_str() );

        // error handling
        if ( error != 0 )
        {
            fprintf(
                stderr,
                "Error: Can't open file.(file name : %s, mode : %s, errno : %d)\n",
                filepath.c_str(), mode.c_str(), error );
            exit( EXIT_FAILURE );
        }
#else
        fp = fopen( filepath.c_str(), mode.c_str() );

        // error handling
        if ( fp == NULL )
        {
            fprintf(
                stderr,
                "Error: Can't open file.(file name : %s, mode : %s)\n",
                filepath.c_str(), mode.c_str() );
            exit( EXIT_FAILURE );
        }
#endif
        return fp;
    }

    ///
    /// @brief ファイルの大きさをバイト単位で返却
    /// @param[in] filename 調べるファイルのパス
    /// @return std::size_t バイト単位のファイルの大きさ
    /// @details 開くファイルのパスは絶対パスや実行ファイルからの相対パスで指定する。<br>
    /// ファイルが見つからない場合、エラー終了する。
    ///
    inline std::size_t file_size( std::string& file_name )
    {
        FILE* fp = NULL;
        fp = fopen( file_name.c_str(), "rb" );
        if ( fp == NULL )
        {
            fprintf(
                stderr,
                "Error: Can't find the file.(path : %s)\n", file_name.c_str() );
            exit( EXIT_FAILURE );
        }

        struct stat stbuf;
        if ( stat( file_name.c_str(), &stbuf ) != 0 )
        {
            fprintf(
                stderr,
                "Error: Can't get the file infomation.(path : %s)\n", file_name.c_str() );
            exit( EXIT_FAILURE );
        }

        return stbuf.st_size;
    }

}    // namespace dsp_work_utils

#endif /* DSPWORK_FILE_HPP_ */