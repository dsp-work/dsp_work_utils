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
        const std::string filename,
        const std::string mode )
    {
        // mode checking
        if ( mode.size() >= 3 || mode.size() == 0 )
        {
            throw std::invalid_argument( "The mode is require 'r'(read), 'w'(write),...others. See official `fopen` documents." );
        }

        FILE* fp = fopen( filename.c_str(), mode.c_str() );

        // error handling
        if ( fp == NULL )
        {
            throw std::runtime_error( format( "Can't open file.(file name : %s, mode : %s)\n", filename.c_str(), mode.c_str() ) );
        }
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