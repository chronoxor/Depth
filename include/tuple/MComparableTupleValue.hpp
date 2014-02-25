/*!
 *  \file    MComparableTupleValue.hpp Contains set of meta-classes to get the
 *           fixed comparable tuple value.
 *  \brief   Comparable tuple value meta-classes.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    30.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Comparable tuple value meta-classes.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Tuple
    VERSION:   1.0
    CREATED:   30.01.2007 23:49:27

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
#ifndef __MCOMPARABLETUPLEVALUE_HPP__
#define __MCOMPARABLETUPLEVALUE_HPP__
/*==========================================================================*/
#include <Depth/include/tuple/MComparableTupleType.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTuple {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Comparable tuple value meta-class (base version).
/*!
    This meta-class is a general comparable tuple value class.  Is  has  dummy
    implementation.  Other  meta-class  specializations  will  provide   valid
    comparable tuple get values  methods.  By  default  comparable  tuple  get
    values methods returns nothing ('void').
*/
template <Tsint t_N, typename T_Type>
class MComparableTupleValue :
  public NDepth::NCommon::IStatic
{
public:
  //! Get comparable tuple value.
  /*!
      \param a_rTuple - Reference to the comparable tuple.
  */
  static void getValue(T_Type& a_rTuple);

  //! Get comparable tuple value (constant version).
  /*!
      \param a_crTuple - Constant reference to the comparable tuple.
  */
  static void getValue(const T_Type& a_crTuple);
};
/*--------------------------------------------------------------------------*/
//! Comparable tuple value meta-class (first comparable tuple value specialization).
/*!
    Comparable tuple value specialization for the first comparable tuple value
    (comparable tuple with two values).
*/
template <typename T_Type1, typename T_Type2>
class MComparableTupleValue<1, NDetails::CComparableDuo<T_Type1, T_Type2> > :
  public NDepth::NCommon::IStatic
{
public:
  //! Get comparable tuple value.
  /*!
      \param a_rTuple - Reference to the comparable tuple base class (CComparableDuo).
      \return Reference to the first comparable tuple value.
  */
  static T_Type1& getValue(NDetails::CComparableDuo<T_Type1, T_Type2>& a_rTuple);

  //! Get comparable tuple value (constant version).
  /*!
      \param a_crTuple - Constant reference to the comparable tuple base class (CComparableDuo).
      \return Constant reference to the first comparable tuple value.
  */
  static const T_Type1& getValue(const NDetails::CComparableDuo<T_Type1, T_Type2>& a_crTuple);
};
/*--------------------------------------------------------------------------*/
//! Comparable tuple value meta-class (second comparable tuple value specialization).
/*!
    Comparable tuple value specialization  for  the  second  comparable  tuple
    value (comparable tuple with two values).
*/
template <typename T_Type1, typename T_Type2>
class MComparableTupleValue<2, NDetails::CComparableDuo<T_Type1, T_Type2> > :
  public NDepth::NCommon::IStatic
{
public:
  //! Get comparable tuple value.
  /*!
      \param a_rTuple - Reference to the comparable tuple base class (CComparableDuo).
      \return Reference to the second comparable tuple value.
  */
  static T_Type2& getValue(NDetails::CComparableDuo<T_Type1, T_Type2>& a_rTuple);

  //! Get comparable tuple value (constant version).
  /*!
      \param a_crTuple - Constant reference to the comparable tuple base class (CComparableDuo).
      \return Constant reference to the second comparable tuple value.
  */
  static const T_Type2& getValue(const NDetails::CComparableDuo<T_Type1, T_Type2>& a_crTuple);
};
/*--------------------------------------------------------------------------*/
//! Comparable tuple value meta-class (N'th recursive comparable tuple value specialization).
/*!
    Comparable tuple value specialization for the  N'th  recursive  comparable
    tuple value (comparable tuple with N values).

*/
template <Tsint t_N, typename T_Type1, typename T_Type2, typename T_Type3>
class MComparableTupleValue<t_N, NDetails::CComparableDuo<T_Type1, NDetails::CComparableDuo<T_Type2, T_Type3> > > :
  public NDepth::NCommon::IStatic
{
public:
  //! Get comparable tuple value.
  /*!
      \param a_rTuple - Reference to the recursive comparable tuple base class (CComparableDuo).
      \return Reference to the N'th recursive comparable tuple value.
  */
  static typename MComparableTupleType<t_N - 1, NDetails::CComparableDuo<T_Type2, T_Type3> >::TType& getValue(NDetails::CComparableDuo<T_Type1, NDetails::CComparableDuo<T_Type2, T_Type3> >& a_rTuple);

  //! Get comparable tuple value (constant version).
  /*!
      \param a_crTuple - Constant reference to the recursive comparable tuple base class (CComparableDuo).
      \return Constant reference to the N'th recursive comparable tuple value.
  */
  static const typename MComparableTupleType<t_N - 1, NDetails::CComparableDuo<T_Type2, T_Type3> >::TType& getValue(const NDetails::CComparableDuo<T_Type1, NDetails::CComparableDuo<T_Type2, T_Type3> >& a_crTuple);
};
/*--------------------------------------------------------------------------*/
//! Comparable tuple value meta-class (first recursive comparable tuple value specialization).
/*!
    Comparable tuple value specialization for the first  recursive  comparable
    tuple value (comparable tuple with N values).
*/
template <typename T_Type1, typename T_Type2, typename T_Type3>
class MComparableTupleValue<1, NDetails::CComparableDuo<T_Type1, NDetails::CComparableDuo<T_Type2, T_Type3> > > :
  public NDepth::NCommon::IStatic
{
public:
  //! Get comparable tuple value.
  /*!
      \param a_rTuple - Reference to the recursive comparable tuple base class (CComparableDuo).
      \return Reference to the first recursive comparable tuple value.
  */
  static T_Type1& getValue(NDetails::CComparableDuo<T_Type1, NDetails::CComparableDuo<T_Type2, T_Type3> >& a_rTuple);

  //! Get comparable tuple value (constant version).
  /*!
      \param a_crTuple - Constant reference to the recursive comparable tuple base class (CComparableDuo).
      \return Constant reference to the first comparable recursive tuple value.
  */
  static const T_Type1& getValue(const NDetails::CComparableDuo<T_Type1, NDetails::CComparableDuo<T_Type2, T_Type3> >& a_crTuple);
};
/*--------------------------------------------------------------------------*/
//! Comparable tuple value meta-class (second recursive comparable tuple value specialization).
/*!
    Comparable tuple value specialization for the second recursive  comparable
    tuple value (comparable tuple with N values).
*/
template <typename T_Type1, typename T_Type2, typename T_Type3>
class MComparableTupleValue<2, NDetails::CComparableDuo<T_Type1, NDetails::CComparableDuo<T_Type2, T_Type3> > > :
  public NDepth::NCommon::IStatic
{
public:
  //! Get comparable tuple value.
  /*!
      \param a_rTuple - Reference to the recursive comparable tuple base class (CComparableDuo).
      \return Reference to the first recursive comparable tuple value.
  */
  static T_Type2& getValue(NDetails::CComparableDuo<T_Type1, NDetails::CComparableDuo<T_Type2, T_Type3> >& a_rTuple);

  //! Get comparable tuple value (constant version).
  /*!
      \param a_crTuple - Constant reference to the recursive comparable tuple base class (CComparableDuo).
      \return Constant reference to the first recursive comparable tuple value.
  */
  static const T_Type2& getValue(const NDetails::CComparableDuo<T_Type1, NDetails::CComparableDuo<T_Type2, T_Type3> >& a_crTuple);
};
/*==========================================================================*/
/* FUNCTION DECLARATIONS                                                    */
/*==========================================================================*/
//! Get N'th comparable tuple value.
/*!
    \param a_rTuple - Reference to the comparable tuple.
    \return Reference to the N'th comparable tuple value.
*/
template <Tsint t_N, typename T_Type1, typename T_Type2>
typename MComparableTupleType<t_N, NDetails::CComparableDuo<T_Type1, T_Type2> >::TType& getValue(NDetails::CComparableDuo<T_Type1, T_Type2>& a_rTuple);
/*--------------------------------------------------------------------------*/
//! Get N'th comparable tuple value (constant version).
/*!
    \param a_crTuple - Constant reference to the comparable tuple.
    \return Constant reference to the N'th comparable tuple value.
*/
template <Tsint t_N, typename T_Type1, typename T_Type2>
const typename MComparableTupleType<t_N, NDetails::CComparableDuo<T_Type1, T_Type2> >::TType& getValue(const NDetails::CComparableDuo<T_Type1, T_Type2>& a_crTuple);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/tuple/MComparableTupleValue.inl>
/*==========================================================================*/
#endif
