//!
//! @file String.hpp
//! @brief string関係のモジュール
//! @details
//!

#ifndef DSPWORK_STRING_OPERATION_HPP_
#define DSPWORK_STRING_OPERATION_HPP_

#include <sstream>
#include <string>
#include <vector>

namespace dsp_work_utils
{
    ///
    /// @fn std::string format( const std::string& fmt, Args... args )
    /// @brief printfと同じ用法で、stringに出力する関数
    /// @param[in] fmt printfの""～～"の部分。整形対象の文字列
    /// @param[in] args 整形対象の文字列に埋め込みたい変数など
    /// @return std::string 変数値などを埋め込んだ整形済み文字列
    /// @details 基本的にprintfと同じ用法で使用できる。std-11向けに作成したため、新しいバージョンでは同等の関数がstdにある。
    ///
    template< typename... Args >
    std::string format( const std::string& fmt, Args... args )
    {
        std::size_t len = static_cast< std::size_t >(
            snprintf( nullptr, 0, fmt.c_str(), args... ) );
        std::vector< char > buf( len + 1 );
        snprintf( &buf[0], len + 1, fmt.c_str(), args... );
        return std::string( &buf[0], &buf[0] + len );
    }

    ///
    /// @fn std::vector< std::string > split_char( std::string& str, char spliter )
    /// @brief 区切り文字によって文字列を分割する関数
    /// @param[in] str 分割対象の文字列
    /// @param[in] spliter 区切り文字
    /// @return std::vector< std::string > 分割された文字列の配列
    /// @details std-11向けに作成したため、新しいバージョンでは同等の関数がstdにある可能性あり。
    ///
    inline std::vector< std::string > split_char( std::string& str, char spliter )
    {
        std::stringstream ss { str };
        std::vector< std::string > strs;
        std::string buf;
        while ( std::getline( ss, buf, spliter ) )
        {
            strs.emplace_back( buf );
        }
        return strs;
    }
}    // namespace dsp_work_utils
#endif /* DSPWORK_STRING_OPERATION_HPP_ */