//!
//! @file Math.hpp
//! @brief 数学関係のモジュール
//! @details
//!

#ifndef DSPWORK_MATH_HPP_
#define DSPWORK_MATH_HPP_

namespace dsp_work_utils
{
    ///
    /// @fn inline double pow2( double num )
    /// @brief ２乗値を高速に計算する関数
    /// @param[in] num 根の値
    /// @return double 2乗値
    /// @details std-11向けに作成したため、新しいバージョンでは同等の関数がstdにある可能性あり。
    ///
    inline double pow2( double num )
    {
        return ( num * num );
    }
}    // namespace dsp_work_utils
#endif /* DSPWORK_MATH_HPP_ */