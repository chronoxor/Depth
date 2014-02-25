/*!
 *  \file    CTupleMaker.hpp Utility class that helps to make CTuple
 *           instances from specific values.
 *  \brief   Tuple maker class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    13.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tuple maker class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Tuple
    VERSION:   1.0
    CREATED:   13.03.2006 20:58:42

    EMAIL:     chronoxor@gmail.com
    WWW:       http://code.google.com/p/depth

    COPYRIGHT: (C) 2005-2010 The NULL workgroup. All Rights Reserved.
*/
/*--------------------------------------------------------------------------*/
/*
    Copyright (C) 2005-2010 The NULL workgroup.

    This program is free software; you can redistribute it  and/or  modify  it
    under the terms of the GNU General Public License as published by the Free
    Software Foundation; either version 2 of the License, or (at your  option)
    any later version.

    This program is distributed in the  hope  that  it  will  be  useful,  but
    WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
    or FITNESS FOR A PARTICULAR PURPOSE. See the GNU  General  Public  License
    for more details.

    You should have received a copy of the GNU General  Public  License  along
    with this program; if not, write to the Free Software Foundation, Inc., 59
    Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/
/*--------------------------------------------------------------------------*/
/*
    FILE ID: $Id$

    CHANGE LOG:

    $Log$
*/
/*==========================================================================*/
#ifndef __CTUPLEMAKER_HPP__
#define __CTUPLEMAKER_HPP__
/*==========================================================================*/
#include <Depth/include/common/IStatic.hpp>
#include <Depth/include/tuple/CTuple.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTuple {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Tuple maker class.
/*!
    With this utility class template CTuple  instances  can  be  made  without
    specifying template arguments.
*/
class BASE_API CTupleMaker :
  public NDepth::NCommon::IStatic
{
public:
  //! Make CTuple instance from 1 specified value.
  /*!
      \param a_crValue - Constant reference to the tuple value.
      \return CTuple class instance.
  */
  template <typename T_Type>
  static CTuple<T_Type> make(const T_Type& a_crValue);
  //! Make CTuple instance from 2 specified values.
  /*!
      \param a_crValue1 - Constant reference to the 1'st tuple value.
      \param a_crValue2 - Constant reference to the 2'nd tuple value.
      \return CTuple class instance.
  */
  template <typename T_Type1, typename T_Type2>
  static CTuple<T_Type1, T_Type2> make(const T_Type1& a_crValue1, const T_Type2& a_crValue2);
  //! Make CTuple instance from 3 specified values.
  /*!
      \param a_crValue1 - Constant reference to the 1'st tuple value.
      \param a_crValue2 - Constant reference to the 2'nd tuple value.
      \param a_crValue3 - Constant reference to the 3'rd tuple value.
      \return CTuple class instance.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3>
  static CTuple<T_Type1, T_Type2, T_Type3> make(const T_Type1& a_crValue1, const T_Type2& a_crValue2, const T_Type3& a_crValue3);
  //! Make CTuple instance from 4 specified values.
  /*!
      \param a_crValue1 - Constant reference to the 1'st tuple value.
      \param a_crValue2 - Constant reference to the 2'nd tuple value.
      \param a_crValue3 - Constant reference to the 3'rd tuple value.
      \param a_crValue4 - Constant reference to the 4'th tuple value.
      \return CTuple class instance.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4>
  static CTuple<T_Type1, T_Type2, T_Type3, T_Type4> make(const T_Type1& a_crValue1, const T_Type2& a_crValue2, const T_Type3& a_crValue3, const T_Type4& a_crValue4);
  //! Make CTuple instance from 5 specified values.
  /*!
      \param a_crValue1 - Constant reference to the 1'st tuple value.
      \param a_crValue2 - Constant reference to the 2'nd tuple value.
      \param a_crValue3 - Constant reference to the 3'rd tuple value.
      \param a_crValue4 - Constant reference to the 4'th tuple value.
      \param a_crValue5 - Constant reference to the 5'th tuple value.
      \return CTuple class instance.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5>
  static CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5> make(const T_Type1& a_crValue1, const T_Type2& a_crValue2, const T_Type3& a_crValue3, const T_Type4& a_crValue4, const T_Type5& a_crValue5);
  //! Make CTuple instance from 6 specified values.
  /*!
      \param a_crValue1 - Constant reference to the 1'st tuple value.
      \param a_crValue2 - Constant reference to the 2'nd tuple value.
      \param a_crValue3 - Constant reference to the 3'rd tuple value.
      \param a_crValue4 - Constant reference to the 4'th tuple value.
      \param a_crValue5 - Constant reference to the 5'th tuple value.
      \param a_crValue6 - Constant reference to the 6'th tuple value.
      \return CTuple class instance.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6>
  static CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6> make(const T_Type1& a_crValue1, const T_Type2& a_crValue2, const T_Type3& a_crValue3, const T_Type4& a_crValue4, const T_Type5& a_crValue5, const T_Type6& a_crValue6);
  //! Make CTuple instance from 7 specified values.
  /*!
      \param a_crValue1 - Constant reference to the 1'st tuple value.
      \param a_crValue2 - Constant reference to the 2'nd tuple value.
      \param a_crValue3 - Constant reference to the 3'rd tuple value.
      \param a_crValue4 - Constant reference to the 4'th tuple value.
      \param a_crValue5 - Constant reference to the 5'th tuple value.
      \param a_crValue6 - Constant reference to the 6'th tuple value.
      \param a_crValue7 - Constant reference to the 7'th tuple value.
      \return CTuple class instance.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7>
  static CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7> make(const T_Type1& a_crValue1, const T_Type2& a_crValue2, const T_Type3& a_crValue3, const T_Type4& a_crValue4, const T_Type5& a_crValue5, const T_Type6& a_crValue6, const T_Type7& a_crValue7);
  //! Make CTuple instance from 8 specified values.
  /*!
      \param a_crValue1 - Constant reference to the 1'st tuple value.
      \param a_crValue2 - Constant reference to the 2'nd tuple value.
      \param a_crValue3 - Constant reference to the 3'rd tuple value.
      \param a_crValue4 - Constant reference to the 4'th tuple value.
      \param a_crValue5 - Constant reference to the 5'th tuple value.
      \param a_crValue6 - Constant reference to the 6'th tuple value.
      \param a_crValue7 - Constant reference to the 7'th tuple value.
      \param a_crValue8 - Constant reference to the 8'th tuple value.
      \return CTuple class instance.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8>
  static CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8> make(const T_Type1& a_crValue1, const T_Type2& a_crValue2, const T_Type3& a_crValue3, const T_Type4& a_crValue4, const T_Type5& a_crValue5, const T_Type6& a_crValue6, const T_Type7& a_crValue7, const T_Type8& a_crValue8);
  //! Make CTuple instance from 9 specified values.
  /*!
      \param a_crValue1 - Constant reference to the 1'st tuple value.
      \param a_crValue2 - Constant reference to the 2'nd tuple value.
      \param a_crValue3 - Constant reference to the 3'rd tuple value.
      \param a_crValue4 - Constant reference to the 4'th tuple value.
      \param a_crValue5 - Constant reference to the 5'th tuple value.
      \param a_crValue6 - Constant reference to the 6'th tuple value.
      \param a_crValue7 - Constant reference to the 7'th tuple value.
      \param a_crValue8 - Constant reference to the 8'th tuple value.
      \param a_crValue9 - Constant reference to the 9'th tuple value.
      \return CTuple class instance.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9>
  static CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9> make(const T_Type1& a_crValue1, const T_Type2& a_crValue2, const T_Type3& a_crValue3, const T_Type4& a_crValue4, const T_Type5& a_crValue5, const T_Type6& a_crValue6, const T_Type7& a_crValue7, const T_Type8& a_crValue8, const T_Type9& a_crValue9);
  //! Make CTuple instance from 10 specified values.
  /*!
      \param a_crValue1 - Constant reference to the 1'st tuple value.
      \param a_crValue2 - Constant reference to the 2'nd tuple value.
      \param a_crValue3 - Constant reference to the 3'rd tuple value.
      \param a_crValue4 - Constant reference to the 4'th tuple value.
      \param a_crValue5 - Constant reference to the 5'th tuple value.
      \param a_crValue6 - Constant reference to the 6'th tuple value.
      \param a_crValue7 - Constant reference to the 7'th tuple value.
      \param a_crValue8 - Constant reference to the 8'th tuple value.
      \param a_crValue9 - Constant reference to the 9'th tuple value.
      \param a_crValue10 - Constant reference to the 10'th tuple value.
      \return CTuple class instance.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9, typename T_Type10>
  static CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10> make(const T_Type1& a_crValue1, const T_Type2& a_crValue2, const T_Type3& a_crValue3, const T_Type4& a_crValue4, const T_Type5& a_crValue5, const T_Type6& a_crValue6, const T_Type7& a_crValue7, const T_Type8& a_crValue8, const T_Type9& a_crValue9, const T_Type10& a_crValue10);

  //! Make CTuple instance from specified CTuple class instance with 1 value.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTuple class.
      \return CTuple class instance.
  */
  template <typename T_Type>
  static CTuple<T_Type> make(const CTuple<T_Type>& a_crInstance);
  //! Make CTuple instance from specified CTuple class instance with 2 values.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTuple class.
      \return CTuple class instance.
  */
  template <typename T_Type1, typename T_Type2>
  static CTuple<T_Type1, T_Type2> make(const CTuple<T_Type1, T_Type2>& a_crInstance);
  //! Make CTuple instance from specified CTuple class instance with 3 values.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTuple class.
      \return CTuple class instance.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3>
  static CTuple<T_Type1, T_Type2, T_Type3> make(const CTuple<T_Type1, T_Type2, T_Type3>& a_crInstance);
  //! Make CTuple instance from specified CTuple class instance with 4 values.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTuple class.
      \return CTuple class instance.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4>
  static CTuple<T_Type1, T_Type2, T_Type3, T_Type4> make(const CTuple<T_Type1, T_Type2, T_Type3, T_Type4>& a_crInstance);
  //! Make CTuple instance from specified CTuple class instance with 5 values.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTuple class.
      \return CTuple class instance.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5>
  static CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5> make(const CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5>& a_crInstance);
  //! Make CTuple instance from specified CTuple class instance with 6 values.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTuple class.
      \return CTuple class instance.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6>
  static CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6> make(const CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6>& a_crInstance);
  //! Make CTuple instance from specified CTuple class instance with 7 values.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTuple class.
      \return CTuple class instance.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7>
  static CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7> make(const CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7>& a_crInstance);
  //! Make CTuple instance from specified CTuple class instance with 8 values.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTuple class.
      \return CTuple class instance.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8>
  static CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8> make(const CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8>& a_crInstance);
  //! Make CTuple instance from specified CTuple class instance with 9 values.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTuple class.
      \return CTuple class instance.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9>
  static CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9> make(const CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9>& a_crInstance);
  //! Make CTuple instance from specified CTuple class instance with 10 values.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTuple class.
      \return CTuple class instance.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9, typename T_Type10>
  static CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10> make(const CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>& a_crInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/tuple/CTupleMaker.inl>
/*==========================================================================*/
#endif
