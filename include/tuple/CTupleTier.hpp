/*!
 *  \file    CTupleTier.hpp Utility class that helps to tie CTuple instances
 *           with specified references to values.
 *  \brief   Tuple tier class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    13.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tuple tier class.

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
#ifndef __CTUPLETIER_HPP__
#define __CTUPLETIER_HPP__
/*==========================================================================*/
#include <Depth/include/base/CReference.hpp>
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
//! Tuple tier class.
/*!
    With this utility class template CTuple instances can be tied  with  given
    references to values.
*/
class BASE_API CTupleTier :
  public NDepth::NCommon::IStatic
{
public:
  //! Tie CTuple instance with 1 specified reference to value.
  /*!
      \param a_rValue - Reference to the tuple value.
      \return CTuple class instance.
  */
  template <typename T_Type>
  static CTuple<NBase::CReference<T_Type> > tie(T_Type& a_rValue);
  //! Tie CTuple instance with 2 specified references to values.
  /*!
      \param a_rValue1 - Reference to the 1'st tuple value.
      \param a_rValue2 - Reference to the 2'nd tuple value.
      \return CTuple class instance.
  */
  template <typename T_Type1, typename T_Type2>
  static CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2> > tie(T_Type1& a_rValue1, T_Type2& a_rValue2);
  //! Tie CTuple instance with 3 specified references to values.
  /*!
      \param a_rValue1 - Reference to the 1'st tuple value.
      \param a_rValue2 - Reference to the 2'nd tuple value.
      \param a_rValue3 - Reference to the 3'rd tuple value.
      \return CTuple class instance.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3>
  static CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3> > tie(T_Type1& a_rValue1, T_Type2& a_rValue2, T_Type3& a_rValue3);
  //! Tie CTuple instance with 4 specified references to values.
  /*!
      \param a_rValue1 - Reference to the 1'st tuple value.
      \param a_rValue2 - Reference to the 2'nd tuple value.
      \param a_rValue3 - Reference to the 3'rd tuple value.
      \param a_rValue4 - Reference to the 4'th tuple value.
      \return CTuple class instance.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4>
  static CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4> > tie(T_Type1& a_rValue1, T_Type2& a_rValue2, T_Type3& a_rValue3, T_Type4& a_rValue4);
  //! Tie CTuple instance with 5 specified references to values.
  /*!
      \param a_rValue1 - Reference to the 1'st tuple value.
      \param a_rValue2 - Reference to the 2'nd tuple value.
      \param a_rValue3 - Reference to the 3'rd tuple value.
      \param a_rValue4 - Reference to the 4'th tuple value.
      \param a_rValue5 - Reference to the 5'th tuple value.
      \return CTuple class instance.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5>
  static CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5> > tie(T_Type1& a_rValue1, T_Type2& a_rValue2, T_Type3& a_rValue3, T_Type4& a_rValue4, T_Type5& a_rValue5);
  //! Tie CTuple instance with 6 specified references to values.
  /*!
      \param a_rValue1 - Reference to the 1'st tuple value.
      \param a_rValue2 - Reference to the 2'nd tuple value.
      \param a_rValue3 - Reference to the 3'rd tuple value.
      \param a_rValue4 - Reference to the 4'th tuple value.
      \param a_rValue5 - Reference to the 5'th tuple value.
      \param a_rValue6 - Reference to the 6'th tuple value.
      \return CTuple class instance.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6>
  static CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6> > tie(T_Type1& a_rValue1, T_Type2& a_rValue2, T_Type3& a_rValue3, T_Type4& a_rValue4, T_Type5& a_rValue5, T_Type6& a_rValue6);
  //! Tie CTuple instance with 7 specified references to values.
  /*!
      \param a_rValue1 - Reference to the 1'st tuple value.
      \param a_rValue2 - Reference to the 2'nd tuple value.
      \param a_rValue3 - Reference to the 3'rd tuple value.
      \param a_rValue4 - Reference to the 4'th tuple value.
      \param a_rValue5 - Reference to the 5'th tuple value.
      \param a_rValue6 - Reference to the 6'th tuple value.
      \param a_rValue7 - Reference to the 7'th tuple value.
      \return CTuple class instance.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7>
  static CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7> > tie(T_Type1& a_rValue1, T_Type2& a_rValue2, T_Type3& a_rValue3, T_Type4& a_rValue4, T_Type5& a_rValue5, T_Type6& a_rValue6, T_Type7& a_rValue7);
  //! Tie CTuple instance with 8 specified references to values.
  /*!
      \param a_rValue1 - Reference to the 1'st tuple value.
      \param a_rValue2 - Reference to the 2'nd tuple value.
      \param a_rValue3 - Reference to the 3'rd tuple value.
      \param a_rValue4 - Reference to the 4'th tuple value.
      \param a_rValue5 - Reference to the 5'th tuple value.
      \param a_rValue6 - Reference to the 6'th tuple value.
      \param a_rValue7 - Reference to the 7'th tuple value.
      \param a_rValue8 - Reference to the 8'th tuple value.
      \return CTuple class instance.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8>
  static CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8> > tie(T_Type1& a_rValue1, T_Type2& a_rValue2, T_Type3& a_rValue3, T_Type4& a_rValue4, T_Type5& a_rValue5, T_Type6& a_rValue6, T_Type7& a_rValue7, T_Type8& a_rValue8);
  //! Tie CTuple instance with 9 specified references to values.
  /*!
      \param a_rValue1 - Reference to the 1'st tuple value.
      \param a_rValue2 - Reference to the 2'nd tuple value.
      \param a_rValue3 - Reference to the 3'rd tuple value.
      \param a_rValue4 - Reference to the 4'th tuple value.
      \param a_rValue5 - Reference to the 5'th tuple value.
      \param a_rValue6 - Reference to the 6'th tuple value.
      \param a_rValue7 - Reference to the 7'th tuple value.
      \param a_rValue8 - Reference to the 8'th tuple value.
      \param a_rValue9 - Reference to the 9'th tuple value.
      \return CTuple class instance.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9>
  static CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8>, NBase::CReference<T_Type9> > tie(T_Type1& a_rValue1, T_Type2& a_rValue2, T_Type3& a_rValue3, T_Type4& a_rValue4, T_Type5& a_rValue5, T_Type6& a_rValue6, T_Type7& a_rValue7, T_Type8& a_rValue8, T_Type9& a_rValue9);
  //! Tie CTuple instance with 10 specified references to values.
  /*!
      \param a_rValue1 - Reference to the 1'st tuple value.
      \param a_rValue2 - Reference to the 2'nd tuple value.
      \param a_rValue3 - Reference to the 3'rd tuple value.
      \param a_rValue4 - Reference to the 4'th tuple value.
      \param a_rValue5 - Reference to the 5'th tuple value.
      \param a_rValue6 - Reference to the 6'th tuple value.
      \param a_rValue7 - Reference to the 7'th tuple value.
      \param a_rValue8 - Reference to the 8'th tuple value.
      \param a_rValue9 - Reference to the 9'th tuple value.
      \param a_rValue10 - Reference to the 10'th tuple value.
      \return CTuple class instance.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9, typename T_Type10>
  static CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8>, NBase::CReference<T_Type9>, NBase::CReference<T_Type10> > tie(T_Type1& a_rValue1, T_Type2& a_rValue2, T_Type3& a_rValue3, T_Type4& a_rValue4, T_Type5& a_rValue5, T_Type6& a_rValue6, T_Type7& a_rValue7, T_Type8& a_rValue8, T_Type9& a_rValue9, T_Type10& a_rValue10);

  //! Tie CTuple instance with specified CTuple class instance with 1 value.
  /*!
      \param a_rInstance - Reference to another instance of the CTuple class.
      \return CTuple class instance with tied references.
  */
  template <typename T_Type>
  static CTuple<NBase::CReference<T_Type> > tie(CTuple<T_Type>& a_rInstance);
  //! Tie CTuple instance with specified CTuple class instance with 2 values.
  /*!
      \param a_rInstance - Reference to another instance of the CTuple class.
      \return CTuple class instance with tied references.
  */
  template <typename T_Type1, typename T_Type2>
  static CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2> > tie(CTuple<T_Type1, T_Type2>& a_rInstance);
  //! Tie CTuple instance with specified CTuple class instance with 3 values.
  /*!
      \param a_rInstance - Reference to another instance of the CTuple class.
      \return CTuple class instance with tied references.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3>
  static CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3> > tie(CTuple<T_Type1, T_Type2, T_Type3>& a_rInstance);
  //! Tie CTuple instance with specified CTuple class instance with 4 values.
  /*!
      \param a_rInstance - Reference to another instance of the CTuple class.
      \return CTuple class instance with tied references.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4>
  static CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4> > tie(CTuple<T_Type1, T_Type2, T_Type3, T_Type4>& a_rInstance);
  //! Tie CTuple instance with specified CTuple class instance with 5 values.
  /*!
      \param a_rInstance - Reference to another instance of the CTuple class.
      \return CTuple class instance with tied references.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5>
  static CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5> > tie(CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5>& a_rInstance);
  //! Tie CTuple instance with specified CTuple class instance with 6 values.
  /*!
      \param a_rInstance - Reference to another instance of the CTuple class.
      \return CTuple class instance with tied references.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6>
  static CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6> > tie(CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6>& a_rInstance);
  //! Tie CTuple instance with specified CTuple class instance with 7 values.
  /*!
      \param a_rInstance - Reference to another instance of the CTuple class.
      \return CTuple class instance with tied references.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7>
  static CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7> > tie(CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7>& a_rInstance);
  //! Tie CTuple instance with specified CTuple class instance with 8 values.
  /*!
      \param a_rInstance - Reference to another instance of the CTuple class.
      \return CTuple class instance with tied references.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8>
  static CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8> > tie(CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8>& a_rInstance);
  //! Tie CTuple instance with specified CTuple class instance with 9 values.
  /*!
      \param a_rInstance - Reference to another instance of the CTuple class.
      \return CTuple class instance with tied references.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9>
  static CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8>, NBase::CReference<T_Type9> > tie(CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9>& a_rInstance);
  //! Tie CTuple instance with specified CTuple class instance with 10 values.
  /*!
      \param a_rInstance - Reference to another instance of the CTuple class.
      \return CTuple class instance with tied references.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9, typename T_Type10>
  static CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8>, NBase::CReference<T_Type9>, NBase::CReference<T_Type10> > tie(CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>& a_rInstance);

  //! Tie CTuple instance with another tied CTuple class instance with 1 value.
  /*!
      \param a_rInstance - Reference to another instance of the tied CTuple class.
      \return CTuple class instance with tied references.
  */
  template <typename T_Type>
  static CTuple<NBase::CReference<T_Type> > tie(CTuple<NBase::CReference<T_Type> >& a_rInstance);
  //! Tie CTuple instance with another tied CTuple class instance with 2 values.
  /*!
      \param a_rInstance - Reference to another instance of the tied CTuple class.
      \return CTuple class instance with tied references.
  */
  template <typename T_Type1, typename T_Type2>
  static CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2> > tie(CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2> >& a_rInstance);
  //! Tie CTuple instance with another tied CTuple class instance with 3 values.
  /*!
      \param a_rInstance - Reference to another instance of the tied CTuple class.
      \return CTuple class instance with tied references.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3>
  static CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3> > tie(CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3> >& a_rInstance);
  //! Tie CTuple instance with another tied CTuple class instance with 4 values.
  /*!
      \param a_rInstance - Reference to another instance of the tied CTuple class.
      \return CTuple class instance with tied references.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4>
  static CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4> > tie(CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4> >& a_rInstance);
  //! Tie CTuple instance with another tied CTuple class instance with 5 values.
  /*!
      \param a_rInstance - Reference to another instance of the tied CTuple class.
      \return CTuple class instance with tied references.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5>
  static CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5> > tie(CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5> >& a_rInstance);
  //! Tie CTuple instance with another tied CTuple class instance with 6 values.
  /*!
      \param a_rInstance - Reference to another instance of the tied CTuple class.
      \return CTuple class instance with tied references.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6>
  static CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6> > tie(CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6> >& a_rInstance);
  //! Tie CTuple instance with another tied CTuple class instance with 7 values.
  /*!
      \param a_rInstance - Reference to another instance of the tied CTuple class.
      \return CTuple class instance with tied references.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7>
  static CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7> > tie(CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7> >& a_rInstance);
  //! Tie CTuple instance with another tied CTuple class instance with 8 values.
  /*!
      \param a_rInstance - Reference to another instance of the tied CTuple class.
      \return CTuple class instance with tied references.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8>
  static CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8> > tie(CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8> >& a_rInstance);
  //! Tie CTuple instance with another tied CTuple class instance with 9 values.
  /*!
      \param a_rInstance - Reference to another instance of the tied CTuple class.
      \return CTuple class instance with tied references.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9>
  static CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8>, NBase::CReference<T_Type9> > tie(CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8>, NBase::CReference<T_Type9> >& a_rInstance);
  //! Tie CTuple instance with another tied CTuple class instance with 10 values.
  /*!
      \param a_rInstance - Reference to another instance of the tied CTuple class.
      \return CTuple class instance with tied references.
  */
  template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9, typename T_Type10>
  static CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8>, NBase::CReference<T_Type9>, NBase::CReference<T_Type10> > tie(CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8>, NBase::CReference<T_Type9>, NBase::CReference<T_Type10> >& a_rInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/tuple/CTupleTier.inl>
/*==========================================================================*/
#endif
