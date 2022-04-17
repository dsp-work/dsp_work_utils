//!
//! @file stack_backtrace.hpp
//! @brief stack backtrace関係のモジュール
//! @details Boostのbacktraceを利用
//!

#ifndef DSPWORK_STACK_BACKTRACE_HPP_
#define DSPWORK_STACK_BACKTRACE_HPP_

#ifdef __unix__
    #define BOOST_STACKTRACE_USE_ADDR2LINE
#endif

#include <boost/stacktrace.hpp>
#include <boost/stacktrace/stacktrace_fwd.hpp>
#include <iosfwd>
#include <iostream>

namespace boost
{
    namespace stacktrace
    {

        template< class CharT, class TraitsT, class Allocator >
        std::basic_ostream< CharT, TraitsT >& do_stream_st( std::basic_ostream< CharT, TraitsT >& os, const basic_stacktrace< Allocator >& bt );

        template< class CharT, class TraitsT >
        std::basic_ostream< CharT, TraitsT >& operator<<( std::basic_ostream< CharT, TraitsT >& os, const stacktrace& bt )
        {
            return do_stream_st( os, bt );
        }

        ///
        /// @brief Boostのbacktraceを書式整形する
        /// @return stack backtraceの整形済み文字列
        /// @details 整形は<br>
        /// stack番号 : 関数名<br>
        ///     at 実装ファイル : 行番号<br>
        /// の順。symbol情報がない場合(主にWindows)、実行ファイル名＋stackのアドレスになる場合がある。<br>
        /// WindowsではClangまたはmsvcの使用を推奨する。
        ///
        template< class CharT, class TraitsT, class Allocator >
        std::basic_ostream< CharT, TraitsT >& do_stream_st( std::basic_ostream< CharT, TraitsT >& os, const basic_stacktrace< Allocator >& bt )
        {
            const std::streamsize w = os.width();

            // title
            os << "stack backtrace:"
               << "\n";

            // stack backtrace
            for ( std::size_t i = 0, frames = bt.size(); i < frames; ++i )
            {
                // stack frame number
                os.width( 4 );
                os << i;
                os.width( w );
                os << ": ";

                // stack frame information
#if defined( __MINGW32__ ) && defined( _WIN32 )
                boost::stacktrace::detail::location_from_symbol loc( bt[i].address() );
                if ( !loc.empty() )
                {
                    // if symbol information is not exist, output object file information.
                    os << bt[i].address() << "\n";
                    os.width( 8 );
                    os << "in " << loc.name() << "\n";
                }
                else
                {
                    os << bt[i].name() << "\n";
                    os.width( 12 );
                    if ( bt[i].source_file().size() != 0 )
                    {
                        os << "at " << bt[i].source_file() << ":" << bt[i].source_line() << "\n";
                    }
                }
#else
                os << bt[i].name() << "\n";
                os.width( 12 );
                if ( bt[i].source_file().size() != 0 )
                {
                    os << "at " << bt[i].source_file() << ":" << bt[i].source_line() << "\n";
                }
#endif
            }
            // boost default output
            // os << "(" << boost::stacktrace::detail::to_string( &bt.as_vector()[i], 1 ) << ")";

            return os;
        }

    }    // namespace stacktrace
}    // namespace boost

#endif /* DSPWORK_STACK_BACKTRACE_HPP_ */