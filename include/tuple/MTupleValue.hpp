/*!
 *  \file    MTupleValue.hpp Contains set of meta-classes to get the fixed
 *           tuple value.
 *  \brief   Tuple value meta-classes.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tuple value meta-classes.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Tuple
    VERSION:   1.0
    CREATED:   07.03.2006 20:10:25

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
#ifndef __MTUPLEVALUE_HPP__
#define __MTUPLEVALUE_HPP__
/*==========================================================================*/
#include <Depth/include/tuple/MTupleType.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTuple {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Tuple value meta-class (base version).
/*!
    This  meta-class  is  a  general  tuple  value   class.   Is   has   dummy
    implementation. Other meta-class specializations will provide valid  tuple
    get values methods. By default tuple get values  methods  returns  nothing
    ('void').
*/
template <Tsint t_N, typename T_Type>
class MTupleValue :
  public NDepth::NCommon::IStatic
{
public:
  //! Get tuple value.
  /*!
      \param a_rTuple - Reference to the tuple.
  */
  static void getValue(T_Type& a_rTuple);

  //! Get tuple value (constant version).
  /*!
      \param a_crTuple - Constant reference to the tuple.
  */
  static void getValue(const T_Type& a_crTuple);
};
/*--------------------------------------------------------------------------*/
//! Tuple value meta-class (first tuple value specialization).
/*!
    Tuple value specialization for the  first  tuple  value  (tuple  with  two
    values).
*/
template <typename T_Type1, typename T_Type2>
class MTupleValue<1, NDetails::CDuo<T_Type1, T_Type2> > :
  public NDepth::NCommon::IStatic
{
public:
  //! Get tuple value.
  /*!
      \param a_rTuple - Reference to the tuple base class (CDuo).
      \return Reference to the first tuple value.
  */
  static T_Type1& getValue(NDetails::CDuo<T_Type1, T_Type2>& a_rTuple);

  //! Get tuple value (constant version).
  /*!
      \param a_crTuple - Constant reference to the tuple base class (CDuo).
      \return Constant reference to the first tuple value.
  */
  static const T_Type1& getValue(const NDetails::CDuo<T_Type1, T_Type2>& a_crTuple);
};
/*--------------------------------------------------------------------------*/
//! Tuple value meta-class (second tuple value specialization).
/*!
    Tuple value specialization for the second  tuple  value  (tuple  with  two
    values).
*/
template <typename T_Type1, typename T_Type2>
class MTupleValue<2, NDetails::CDuo<T_Type1, T_Type2> > :
  public NDepth::NCommon::IStatic
{
public:
  //! Get tuple value.
  /*!
      \param a_rTuple - Reference to the tuple base class (CDuo).
      \return Reference to the second tuple value.
  */
  static T_Type2& getValue(NDetails::CDuo<T_Type1, T_Type2>& a_rTuple);

  //! Get tuple value (constant version).
  /*!
      \param a_crTuple - Constant reference to the tuple base class (CDuo).
      \return Constant reference to the second tuple value.
  */
  static const T_Type2& getValue(const NDetails::CDuo<T_Type1, T_Type2>& a_crTuple);
};
/*--------------------------------------------------------------------------*/
//! Tuple value meta-class (N'th recursive tuple value specialization).
/*!
    Tuple value specialization for the N'th recursive tuple value (tuple  with
    N values).
*/
template <Tsint t_N, typename T_Type1, typename T_Type2, typename T_Type3>
class MTupleValue<t_N, NDetails::CDuo<T_Type1, NDetails::CDuo<T_Type2, T_Type3> > > :
  public NDepth::NCommon::IStatic
{
public:
  //! Get tuple value.
  /*!
      \param a_rTuple - Reference to the recursive tuple base class (CDuo).
      \return Reference to the N'th recursive tuple value.
  */
  static typename MTupleType<t_N - 1, NDetails::CDuo<T_Type2, T_Type3> >::TType& getValue(NDetails::CDuo<T_Type1, NDetails::CDuo<T_Type2, T_Type3> >& a_rTuple);

  //! Get tuple value (constant version).
  /*!
      \param a_crTuple - Constant reference to the recursive tuple base class (CDuo).
      \return Constant reference to the N'th recursive tuple value.
  */
  static const typename MTupleType<t_N - 1, NDetails::CDuo<T_Type2, T_Type3> >::TType& getValue(const NDetails::CDuo<T_Type1, NDetails::CDuo<T_Type2, T_Type3> >& a_crTuple);
};
/*--------------------------------------------------------------------------*/
//! Tuple value meta-class (first recursive tuple value specialization).
/*!
    Tuple value specialization for the first recursive tuple value (tuple with
    N values).
*/
template <typename T_Type1, typename T_Type2, typename T_Type3>
class MTupleValue<1, NDetails::CDuo<T_Type1, NDetails::CDuo<T_Type2, T_Type3> > > :
  public NDepth::NCommon::IStatic
{
public:
  //! Get tuple value.
  /*!
      \param a_rTuple - Reference to the recursive tuple base class (CDuo).
      \return Reference to the first recursive tuple value.
  */
  static T_Type1& getValue(NDetails::CDuo<T_Type1, NDetails::CDuo<T_Type2, T_Type3> >& a_rTuple);

  //! Get tuple value (constant version).
  /*!
      \param a_crTuple - Constant reference to the recursive tuple base class (CDuo).
      \return Constant reference to the first recursive tuple value.
  */
  static const T_Type1& getValue(const NDetails::CDuo<T_Type1, NDetails::CDuo<T_Type2, T_Type3> >& a_crTuple);
};
/*--------------------------------------------------------------------------*/
//! Tuple value meta-class (second recursive tuple value specialization).
/*!
    Tuple value specialization for the second  recursive  tuple  value  (tuple
    with N values).
*/
template <typename T_Type1, typename T_Type2, typename T_Type3>
class MTupleValue<2, NDetails::CDuo<T_Type1, NDetails::CDuo<T_Type2, T_Type3> > > :
  public NDepth::NCommon::IStatic
{
public:
  //! Get tuple value.
  /*!
      \param a_rTuple - Reference to the recursive tuple base class (CDuo).
      \return Reference to the first recursive tuple value.
  */
  static T_Type2& getValue(NDetails::CDuo<T_Type1, NDetails::CDuo<T_Type2, T_Type3> >& a_rTuple);

  //! Get tuple value (constant version).
  /*!
      \param a_crTuple - Constant reference to the recursive tuple base class (CDuo).
      \return Constant reference to the first recursive tuple value.
  */
  static const T_Type2& getValue(const NDetails::CDuo<T_Type1, NDetails::CDuo<T_Type2, T_Type3> >& a_crTuple);
};
/*==========================================================================*/
/* FUNCTION DECLARATIONS                                                    */
/*==========================================================================*/
//! Get N'th tuple value.
/*!
    \param a_rTuple - Reference to the tuple.
    \return Reference to the N'th tuple value.
*/
template <Tsint t_N, typename T_Type1, typename T_Type2>
typename MTupleType<t_N, NDetails::CDuo<T_Type1, T_Type2> >::TType& getValue(NDetails::CDuo<T_Type1, T_Type2>& a_rTuple);
/*--------------------------------------------------------------------------*/
//! Get N'th tuple value (constant version).
/*!
    \param a_crTuple - Constant reference to the tuple.
    \return Constant reference to the N'th tuple value.
*/
template <Tsint t_N, typename T_Type1, typename T_Type2>
const typename MTupleType<t_N, NDetails::CDuo<T_Type1, T_Type2> >::TType& getValue(const NDetails::CDuo<T_Type1, T_Type2>& a_crTuple);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/tuple/MTupleValue.inl>
/*==========================================================================*/
#endif
