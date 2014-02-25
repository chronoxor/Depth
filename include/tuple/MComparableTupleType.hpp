/*!
 *  \file    MComparableTupleType.hpp Contains set of meta-classes to
 *           determine the type of the fixed comparable tuple value.
 *  \brief   Comparable tuple type meta-classes.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    30.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Comparable tuple type meta-classes.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Tuple
    VERSION:   1.0
    CREATED:   30.01.2007 23:44:52

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
#ifndef __MCOMPARABLETUPLETYPE_HPP__
#define __MCOMPARABLETUPLETYPE_HPP__
/*==========================================================================*/
#include <Depth/include/tuple/details/CComparableDuoRecursive.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTuple {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Comparable tuple type meta-class (base version).
/*!
    This meta-class is a general comparable  tuple  type  meta-class.  It  has
    dummy implementation. Other meta-class specializations will provide  valid
    comparable tuple value types. By default comparable tuple value  number  N
    has type 'void'.
*/
template <Tsint t_N, typename T_Type>
class MComparableTupleType :
  public NDepth::NCommon::IStatic
{
public:
  //! Type for the N'th tuple value.
  typedef void TType;
};
/*--------------------------------------------------------------------------*/
//! Comparable tuple type meta-class (first comparable duo value specialization).
/*!
    Comparable tuple type specialization for the first  comparable  duo  value
    (comparable tuple with two values).
*/
template <typename T_Type1, typename T_Type2>
class MComparableTupleType<1, NDetails::CComparableDuo<T_Type1, T_Type2> > :
  public NDepth::NCommon::IStatic
{
public:
  //! Type for the first comparable duo value.
  typedef T_Type1 TType;
};
/*--------------------------------------------------------------------------*/
//! Comparable tuple type meta-class (second comparable duo value specialization).
/*!
    Comparable tuple type specialization for the second duo value  (comparable
    tuple with two values).
*/
template <typename T_Type1, typename T_Type2>
class MComparableTupleType<2, NDetails::CComparableDuo<T_Type1, T_Type2> > :
  public NDepth::NCommon::IStatic
{
public:
  //! Type for the second comparable duo value.
  typedef T_Type2 TType;
};
/*--------------------------------------------------------------------------*/
//! Comparable tuple type meta-class (N'th recursive comparable duo value specialization).
/*!
    Comparable tuple type specialization for the N'th recursive comparable duo
    value (comparable tuple with N values).
*/
template <Tsint t_N, typename T_Type1, typename T_Type2, typename T_Type3>
class MComparableTupleType<t_N, NDetails::CComparableDuo<T_Type1, NDetails::CComparableDuo<T_Type2, T_Type3> > > :
  public NDepth::NCommon::IStatic
{
public:
  //! Type for the N'th recursive comparable duo value.
  typedef typename MComparableTupleType<t_N - 1, NDetails::CComparableDuo<T_Type2, T_Type3> >::TType TType;
};
/*--------------------------------------------------------------------------*/
//! Comparable tuple type meta-class (first recursive comparable duo value specialization).
/*!
    Comparable tuple type specialization for the  first  recursive  comparable
    duo value (comparable tuple with N values).
*/
template <typename T_Type1, typename T_Type2, typename T_Type3>
class MComparableTupleType<1, NDetails::CComparableDuo<T_Type1, NDetails::CComparableDuo<T_Type2, T_Type3> > > :
  public NDepth::NCommon::IStatic
{
public:
  //! Type for the first recursive comparable duo value.
  typedef T_Type1 TType;
};
/*--------------------------------------------------------------------------*/
//! Comparable tuple type meta-class (second recursive comparable duo value specialization).
/*!
    Comparable tuple type specialization for the second  recursive  comparable
    duo value (comparable tuple with N values).
*/
template <typename T_Type1, typename T_Type2, typename T_Type3>
class MComparableTupleType<2, NDetails::CComparableDuo<T_Type1, NDetails::CComparableDuo<T_Type2, T_Type3> > > :
  public NDepth::NCommon::IStatic
{
public:
  //! Type for the second recursive comparable duo value.
  typedef T_Type2 TType;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
