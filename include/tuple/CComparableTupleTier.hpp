/*!
 *  \file    CComparableTupleTier.hpp Utility class that helps to tie
 *           CComparableTuple instances with specified references to
 *           values.
 *  \brief   Comparable tuple tier class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    30.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Comparable tuple tier class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Tuple
    VERSION:   1.0
    CREATED:   30.01.2007 00:31:48

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
#ifndef __CCOMPARABLETUPLETIER_HPP__
#define __CCOMPARABLETUPLETIER_HPP__
/*==========================================================================*/
#include <Depth/include/base/CReference.hpp>
#include <Depth/include/common/IStatic.hpp>
#include <Depth/include/tuple/CComparableTuple.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTuple {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Comparable tuple tier class.
/*!
    With this utility class template CComparableTuple instances  can  be  tied
    with given references to values.
*/
class BASE_API CComparableTupleTier :
  public NDepth::NCommon::IStatic
{
public:
  //! Tie CComparableTuple instance with 1 specified reference to value.
  /*!
      \param a_rValue - Reference to the tuple value.
      \return CComparableTuple class instance.
  */
  template <typename T_Type>
  static CComparableTuple<NBase::CReference<T_Type> > tie(T_Type& a_rValue);
  //! Tie CComparableTuple instance with 2 specified references to values.
  /*!
      \param a_rValue1 - Reference to the 1'st comparable tuple value.
      \param a_rValue2 - Reference to the 2'nd comparable tuple value.
      \return CComparableTuple class instance.
  */
  template <typename T_Type1, typename T_Type2>
  static CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2> > tie(T_Type1& a_rValue1, T_Type2& a_rValue2);
  //! Tie CComparableTuple instance with 3 specified references to values.
  /*!
      \param a_rValue1 - Reference to the 1'st comparable tuple value.
      \param a_rValue2 - Reference to the 2'nd comparable tuple value.
      \param a_rValue3 - Reference to the 3'rd comparable tuple value.
      \return CComparableTuple class instance.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3>
  static CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3> > tie(T_Type1& a_rValue1, T_Type2& a_rValue2, T_Type3& a_rValue3);
  //! Tie CComparableTuple instance with 4 specified references to values.
  /*!
      \param a_rValue1 - Reference to the 1'st comparable tuple value.
      \param a_rValue2 - Reference to the 2'nd comparable tuple value.
      \param a_rValue3 - Reference to the 3'rd comparable tuple value.
      \param a_rValue4 - Reference to the 4'th comparable tuple value.
      \return CComparableTuple class instance.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4>
  static CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4> > tie(T_Type1& a_rValue1, T_Type2& a_rValue2, T_Type3& a_rValue3, T_Type4& a_rValue4);
  //! Tie CComparableTuple instance with 5 specified references to values.
  /*!
      \param a_rValue1 - Reference to the 1'st comparable tuple value.
      \param a_rValue2 - Reference to the 2'nd comparable tuple value.
      \param a_rValue3 - Reference to the 3'rd comparable tuple value.
      \param a_rValue4 - Reference to the 4'th comparable tuple value.
      \param a_rValue5 - Reference to the 5'th comparable tuple value.
      \return CComparableTuple class instance.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5>
  static CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5> > tie(T_Type1& a_rValue1, T_Type2& a_rValue2, T_Type3& a_rValue3, T_Type4& a_rValue4, T_Type5& a_rValue5);
  //! Tie CComparableTuple instance with 6 specified references to values.
  /*!
      \param a_rValue1 - Reference to the 1'st comparable tuple value.
      \param a_rValue2 - Reference to the 2'nd comparable tuple value.
      \param a_rValue3 - Reference to the 3'rd comparable tuple value.
      \param a_rValue4 - Reference to the 4'th comparable tuple value.
      \param a_rValue5 - Reference to the 5'th comparable tuple value.
      \param a_rValue6 - Reference to the 6'th comparable tuple value.
      \return CComparableTuple class instance.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6>
  static CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6> > tie(T_Type1& a_rValue1, T_Type2& a_rValue2, T_Type3& a_rValue3, T_Type4& a_rValue4, T_Type5& a_rValue5, T_Type6& a_rValue6);
  //! Tie CComparableTuple instance with 7 specified references to values.
  /*!
      \param a_rValue1 - Reference to the 1'st comparable tuple value.
      \param a_rValue2 - Reference to the 2'nd comparable tuple value.
      \param a_rValue3 - Reference to the 3'rd comparable tuple value.
      \param a_rValue4 - Reference to the 4'th comparable tuple value.
      \param a_rValue5 - Reference to the 5'th comparable tuple value.
      \param a_rValue6 - Reference to the 6'th comparable tuple value.
      \param a_rValue7 - Reference to the 7'th comparable tuple value.
      \return CComparableTuple class instance.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7>
  static CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7> > tie(T_Type1& a_rValue1, T_Type2& a_rValue2, T_Type3& a_rValue3, T_Type4& a_rValue4, T_Type5& a_rValue5, T_Type6& a_rValue6, T_Type7& a_rValue7);
  //! Tie CComparableTuple instance with 8 specified references to values.
  /*!
      \param a_rValue1 - Reference to the 1'st comparable tuple value.
      \param a_rValue2 - Reference to the 2'nd comparable tuple value.
      \param a_rValue3 - Reference to the 3'rd comparable tuple value.
      \param a_rValue4 - Reference to the 4'th comparable tuple value.
      \param a_rValue5 - Reference to the 5'th comparable tuple value.
      \param a_rValue6 - Reference to the 6'th comparable tuple value.
      \param a_rValue7 - Reference to the 7'th comparable tuple value.
      \param a_rValue8 - Reference to the 8'th comparable tuple value.
      \return CComparableTuple class instance.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8>
  static CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8> > tie(T_Type1& a_rValue1, T_Type2& a_rValue2, T_Type3& a_rValue3, T_Type4& a_rValue4, T_Type5& a_rValue5, T_Type6& a_rValue6, T_Type7& a_rValue7, T_Type8& a_rValue8);
  //! Tie CComparableTuple instance with 9 specified references to values.
  /*!
      \param a_rValue1 - Reference to the 1'st comparable tuple value.
      \param a_rValue2 - Reference to the 2'nd comparable tuple value.
      \param a_rValue3 - Reference to the 3'rd comparable tuple value.
      \param a_rValue4 - Reference to the 4'th comparable tuple value.
      \param a_rValue5 - Reference to the 5'th comparable tuple value.
      \param a_rValue6 - Reference to the 6'th comparable tuple value.
      \param a_rValue7 - Reference to the 7'th comparable tuple value.
      \param a_rValue8 - Reference to the 8'th comparable tuple value.
      \param a_rValue9 - Reference to the 9'th comparable tuple value.
      \return CComparableTuple class instance.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9>
  static CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8>, NBase::CReference<T_Type9> > tie(T_Type1& a_rValue1, T_Type2& a_rValue2, T_Type3& a_rValue3, T_Type4& a_rValue4, T_Type5& a_rValue5, T_Type6& a_rValue6, T_Type7& a_rValue7, T_Type8& a_rValue8, T_Type9& a_rValue9);
  //! Tie CComparableTuple instance with 10 specified references to values.
  /*!
      \param a_rValue1 - Reference to the 1'st comparable tuple value.
      \param a_rValue2 - Reference to the 2'nd comparable tuple value.
      \param a_rValue3 - Reference to the 3'rd comparable tuple value.
      \param a_rValue4 - Reference to the 4'th comparable tuple value.
      \param a_rValue5 - Reference to the 5'th comparable tuple value.
      \param a_rValue6 - Reference to the 6'th comparable tuple value.
      \param a_rValue7 - Reference to the 7'th comparable tuple value.
      \param a_rValue8 - Reference to the 8'th comparable tuple value.
      \param a_rValue9 - Reference to the 9'th comparable tuple value.
      \param a_rValue10 - Reference to the 10'th comparable tuple value.
      \return CComparableTuple class instance.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9, typename T_Type10>
  static CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8>, NBase::CReference<T_Type9>, NBase::CReference<T_Type10> > tie(T_Type1& a_rValue1, T_Type2& a_rValue2, T_Type3& a_rValue3, T_Type4& a_rValue4, T_Type5& a_rValue5, T_Type6& a_rValue6, T_Type7& a_rValue7, T_Type8& a_rValue8, T_Type9& a_rValue9, T_Type10& a_rValue10);

  //! Tie CComparableTuple instance with specified CComparableTuple class instance with 1 value.
  /*!
      \param a_rInstance - Reference to another instance of the CComparableTuple class.
      \return CComparableTuple class instance with tied references.
  */
  template <typename T_Type>
  static CComparableTuple<NBase::CReference<T_Type> > tie(CComparableTuple<T_Type>& a_rInstance);
  //! Tie CComparableTuple instance with specified CComparableTuple class instance with 2 values.
  /*!
      \param a_rInstance - Reference to another instance of the CComparableTuple class.
      \return CComparableTuple class instance with tied references.
  */
  template <typename T_Type1, typename T_Type2>
  static CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2> > tie(CComparableTuple<T_Type1, T_Type2>& a_rInstance);
  //! Tie CComparableTuple instance with specified CComparableTuple class instance with 3 values.
  /*!
      \param a_rInstance - Reference to another instance of the CComparableTuple class.
      \return CComparableTuple class instance with tied references.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3>
  static CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3> > tie(CComparableTuple<T_Type1, T_Type2, T_Type3>& a_rInstance);
  //! Tie CComparableTuple instance with specified CComparableTuple class instance with 4 values.
  /*!
      \param a_rInstance - Reference to another instance of the CComparableTuple class.
      \return CComparableTuple class instance with tied references.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4>
  static CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4> > tie(CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4>& a_rInstance);
  //! Tie CComparableTuple instance with specified CComparableTuple class instance with 5 values.
  /*!
      \param a_rInstance - Reference to another instance of the CComparableTuple class.
      \return CComparableTuple class instance with tied references.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5>
  static CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5> > tie(CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5>& a_rInstance);
  //! Tie CComparableTuple instance with specified CComparableTuple class instance with 6 values.
  /*!
      \param a_rInstance - Reference to another instance of the CComparableTuple class.
      \return CComparableTuple class instance with tied references.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6>
  static CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6> > tie(CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6>& a_rInstance);
  //! Tie CComparableTuple instance with specified CComparableTuple class instance with 7 values.
  /*!
      \param a_rInstance - Reference to another instance of the CComparableTuple class.
      \return CComparableTuple class instance with tied references.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7>
  static CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7> > tie(CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7>& a_rInstance);
  //! Tie CComparableTuple instance with specified CComparableTuple class instance with 8 values.
  /*!
      \param a_rInstance - Reference to another instance of the CComparableTuple class.
      \return CComparableTuple class instance with tied references.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8>
  static CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8> > tie(CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8>& a_rInstance);
  //! Tie CComparableTuple instance with specified CComparableTuple class instance with 9 values.
  /*!
      \param a_rInstance - Reference to another instance of the CComparableTuple class.
      \return CComparableTuple class instance with tied references.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9>
  static CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8>, NBase::CReference<T_Type9> > tie(CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9>& a_rInstance);
  //! Tie CComparableTuple instance with specified CComparableTuple class instance with 10 values.
  /*!
      \param a_rInstance - Reference to another instance of the CComparableTuple class.
      \return CComparableTuple class instance with tied references.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9, typename T_Type10>
  static CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8>, NBase::CReference<T_Type9>, NBase::CReference<T_Type10> > tie(CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>& a_rInstance);

  //! Tie CComparableTuple instance with another tied CComparableTuple class instance with 1 value.
  /*!
      \param a_rInstance - Reference to another instance of the tied CComparableTuple class.
      \return CComparableTuple class instance with tied references.
  */
  template <typename T_Type>
  static CComparableTuple<NBase::CReference<T_Type> > tie(CComparableTuple<NBase::CReference<T_Type> >& a_rInstance);
  //! Tie CComparableTuple instance with another tied CComparableTuple class instance with 2 values.
  /*!
      \param a_rInstance - Reference to another instance of the tied CComparableTuple class.
      \return CComparableTuple class instance with tied references.
  */
  template <typename T_Type1, typename T_Type2>
  static CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2> > tie(CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2> >& a_rInstance);
  //! Tie CComparableTuple instance with another tied CComparableTuple class instance with 3 values.
  /*!
      \param a_rInstance - Reference to another instance of the tied CComparableTuple class.
      \return CComparableTuple class instance with tied references.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3>
  static CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3> > tie(CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3> >& a_rInstance);
  //! Tie CComparableTuple instance with another tied CComparableTuple class instance with 4 values.
  /*!
      \param a_rInstance - Reference to another instance of the tied CComparableTuple class.
      \return CComparableTuple class instance with tied references.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4>
  static CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4> > tie(CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4> >& a_rInstance);
  //! Tie CComparableTuple instance with another tied CComparableTuple class instance with 5 values.
  /*!
      \param a_rInstance - Reference to another instance of the tied CComparableTuple class.
      \return CComparableTuple class instance with tied references.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5>
  static CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5> > tie(CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5> >& a_rInstance);
  //! Tie CComparableTuple instance with another tied CComparableTuple class instance with 6 values.
  /*!
      \param a_rInstance - Reference to another instance of the tied CComparableTuple class.
      \return CComparableTuple class instance with tied references.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6>
  static CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6> > tie(CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6> >& a_rInstance);
  //! Tie CComparableTuple instance with another tied CComparableTuple class instance with 7 values.
  /*!
      \param a_rInstance - Reference to another instance of the tied CComparableTuple class.
      \return CComparableTuple class instance with tied references.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7>
  static CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7> > tie(CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7> >& a_rInstance);
  //! Tie CComparableTuple instance with another tied CComparableTuple class instance with 8 values.
  /*!
      \param a_rInstance - Reference to another instance of the tied CComparableTuple class.
      \return CComparableTuple class instance with tied references.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8>
  static CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8> > tie(CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8> >& a_rInstance);
  //! Tie CComparableTuple instance with another tied CComparableTuple class instance with 9 values.
  /*!
      \param a_rInstance - Reference to another instance of the tied CComparableTuple class.
      \return CComparableTuple class instance with tied references.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9>
  static CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8>, NBase::CReference<T_Type9> > tie(CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8>, NBase::CReference<T_Type9> >& a_rInstance);
  //! Tie CComparableTuple instance with another tied CComparableTuple class instance with 10 values.
  /*!
      \param a_rInstance - Reference to another instance of the tied CComparableTuple class.
      \return CComparableTuple class instance with tied references.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9, typename T_Type10>
  static CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8>, NBase::CReference<T_Type9>, NBase::CReference<T_Type10> > tie(CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8>, NBase::CReference<T_Type9>, NBase::CReference<T_Type10> >& a_rInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/tuple/CComparableTupleTier.inl>
/*==========================================================================*/
#endif
