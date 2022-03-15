//!
//! @file File.hpp
//! @brief ファイル操作関係のモジュール
//! @details
//!

#ifndef DSPWORK_FILE_OPERATION_HPP_
#define DSPWORK_FILE_OPERATION_HPP_

#include <cstdio>
#include <cstdlib>
#include <string>
#include <sys/stat.h>

namespace dsp_work_utils
{
    ///
    /// @brief 指定のモードでファイルを開く。正しくファイルを開けたかのチェック機構付き
    /// @param[in] filename 開くファイルのパス
    /// @param[in] mode fopenと同じ用法
    /// @return std::string 変数値などを埋め込んだ整形済み文字列
    /// @details 開くファイルのパスは絶対パスや実行ファイルからの相対パスで指定する。
    ///
    inline FILE* fileopen(
        const std::string& filename,
        const char mode,
        const std::string& call_file,
        const int call_line )
    {
        FILE* fp = fopen( filename.c_str(), &mode );
        if ( fp == NULL )
        {
            fprintf(
                stderr,
                "Error: [%s l.%d]Can't open file.(file name : %s, mode : %c)\n",
                call_file.c_str(), call_line, filename.c_str(), mode );
            exit( EXIT_FAILURE );
        }
        return fp;
    }

    ///
    /// @brief ファイルの大きさをバイト単位で返却
    /// @param[in] filename 調べるファイルのパス
    /// @return std::size_t 変数値などを埋め込んだ整形済み文字列
    /// @details 開くファイルのパスは絶対パスや実行ファイルからの相対パスで指定する。<br>
    /// ファイルが見つからない場合、エラー終了する。
    ///
    std::size_t file_size( std::string& file_name )
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

#endif /* DSPWORK_FILE_OPERATION_HPP_ */