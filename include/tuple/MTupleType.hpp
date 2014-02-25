/*!
 *  \file    MTupleType.hpp Contains set of meta-classes to determine the
 *           type of the fixed tuple value.
 *  \brief   Tuple type meta-classes.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tuple type meta-classes.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Tuple
    VERSION:   1.0
    CREATED:   07.03.2006 02:44:25

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
#ifndef __MTUPLETYPE_HPP__
#define __MTUPLETYPE_HPP__
/*==========================================================================*/
#include <Depth/include/tuple/details/CDuoRecursive.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTuple {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Tuple type meta-class (base version).
/*!
    This  meta-class  is  a  general  tuple  type  meta-class.  It  has  dummy
    implementation. Other meta-class specializations will provide valid  tuple
    value types. By default tuple value number N has type 'void'.
*/
template <Tsint t_N, typename T_Type>
class MTupleType :
  public NDepth::NCommon::IStatic
{
public:
  //! Type for the N'th tuple value.
  typedef void TType;
};
/*--------------------------------------------------------------------------*/
//! Tuple type meta-class (first duo value specialization).
/*!
    Tuple type specialization for the first duo value (tuple with two values).
*/
template <typename T_Type1, typename T_Type2>
class MTupleType<1, NDetails::CDuo<T_Type1, T_Type2> > :
  public NDepth::NCommon::IStatic
{
public:
  //! Type for the first duo value.
  typedef T_Type1 TType;
};
/*--------------------------------------------------------------------------*/
//! Tuple type meta-class (second duo value specialization).
/*!
    Tuple type specialization  for  the  second  duo  value  (tuple  with  two
    values).
*/
template <typename T_Type1, typename T_Type2>
class MTupleType<2, NDetails::CDuo<T_Type1, T_Type2> > :
  public NDepth::NCommon::IStatic
{
public:
  //! Type for the second duo value.
  typedef T_Type2 TType;
};
/*--------------------------------------------------------------------------*/
//! Tuple type meta-class (N'th recursive duo value specialization).
/*!
    Tuple type specialization for the N'th recursive duo value (tuple  with  N
    values).
*/
template <Tsint t_N, typename T_Type1, typename T_Type2, typename T_Type3>
class MTupleType<t_N, NDetails::CDuo<T_Type1, NDetails::CDuo<T_Type2, T_Type3> > > :
  public NDepth::NCommon::IStatic
{
public:
  //! Type for the N'th recursive duo value.
  typedef typename MTupleType<t_N - 1, NDetails::CDuo<T_Type2, T_Type3> >::TType TType;
};
/*--------------------------------------------------------------------------*/
//! Tuple type meta-class (first recursive duo value specialization).
/*!
    Tuple type specialization for the first recursive duo value (tuple with  N
    values).
*/
template <typename T_Type1, typename T_Type2, typename T_Type3>
class MTupleType<1, NDetails::CDuo<T_Type1, NDetails::CDuo<T_Type2, T_Type3> > > :
  public NDepth::NCommon::IStatic
{
public:
  //! Type for the first recursive duo value.
  typedef T_Type1 TType;
};
/*--------------------------------------------------------------------------*/
//! Tuple type meta-class (second recursive duo value specialization).
/*!
    Tuple type specialization for the second recursive duo value (tuple with N
    values).
*/
template <typename T_Type1, typename T_Type2, typename T_Type3>
class MTupleType<2, NDetails::CDuo<T_Type1, NDetails::CDuo<T_Type2, T_Type3> > > :
  public NDepth::NCommon::IStatic
{
public:
  //! Type for the second recursive duo value.
  typedef T_Type2 TType;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
