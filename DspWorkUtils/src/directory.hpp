//!
//! @file Directory.hpp
//! @brief フォルダ操作関係のモジュール
//! @details
//!

#ifndef DSPWORK_DIRECTORY_HPP_
#define DSPWORK_DIRECTORY_HPP_

#include <sys/stat.h>
//#include <sys/types.h>
#include <string>

#ifdef _WIN32
    #include <direct.h>
#endif


namespace dsp_work_utils
{
    ///
    /// @brief クロスプラットフォームなフォルダ存在確認関数
    /// @param[in] dir_name 作成するフォルダのパス
    /// @return bool 存在しているか、true : 存在、false : 存在なし
    /// @details dir_nameのパスにフォルダがあるか確認をする。パスは絶対パスや実行ファイルからの相対パスで指定する。
    ///
    inline bool exist_directory( std::string dir_name )
    {
        struct stat statBuf;

        if ( stat( dir_name.c_str(), &statBuf ) == 0 )
        {
            printf( "ディレクトリ%sは存在します。\n", dir_name.c_str() );
            return true;
        }
        else
        {
            printf( "ディレクトリ%sは存在しません。\n", dir_name.c_str() );
            return false;
        }
    }

    ///
    /// @fn inline void Make_directory( std::string dir_name )
    /// @brief クロスプラットフォームなフォルダ作成関数
    /// @param[in] dir_name 作成するフォルダのパス
    /// @details dir_nameのパスにフォルダーを作成する。パスは絶対パスや実行ファイルからの相対パスで指定する。
    ///
    inline void make_directory( std::string dir_name )
    {
        if ( !exist_directory( dir_name.c_str() ) )
        {
#if defined( _WIN32 )
            if ( mkdir( dir_name.c_str() ) == 0 )
#else
            if ( mkdir( dir_name.c_str(), 0777 ) == 0 )
#endif
            {
                printf( "create directory '%s'\n", dir_name.c_str() );
            }
            else
            {
                printf( "can't create directory '%s'\n", dir_name.c_str() );
                exit( -1 );
            }
        }
    }
}    // namespace dsp_work_utils
#endif /* DSPWORK_DIRECTORY_HPP_ */