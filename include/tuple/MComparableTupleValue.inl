/*!
 *  \file    MComparableTupleValue.inl Contains set of meta-classes to get the
 *           fixed comparable tuple value.
 *  \brief   Comparable tuple value meta-classes (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    30.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Comparable tuple value meta-classes (inline).

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
#ifndef __MCOMPARABLETUPLEVALUE_INL__
#define __MCOMPARABLETUPLEVALUE_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTuple {
/*==========================================================================*/
/* INLINE META-CLASS IMPLEMENTATIONS                                        */
/*==========================================================================*/
template <Tsint t_N, typename T_Type>
inline void MComparableTupleValue<t_N, T_Type>::getValue(T_Type& a_rTuple)
{ CALL
  IGNORE_UNUSED(a_rTuple);
}
/*--------------------------------------------------------------------------*/
template <Tsint t_N, typename T_Type>
inline void MComparableTupleValue<t_N, T_Type>::getValue(const T_Type& a_crTuple)
{ CALL
  IGNORE_UNUSED(a_crTuple);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2>
inline T_Type1& MComparableTupleValue<1, NDetails::CComparableDuo<T_Type1, T_Type2> >::getValue(NDetails::CComparableDuo<T_Type1, T_Type2>& a_rTuple)
{ CALL
  return a_rTuple.getValue1();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2>
inline const T_Type1& MComparableTupleValue<1, NDetails::CComparableDuo<T_Type1, T_Type2> >::getValue(const NDetails::CComparableDuo<T_Type1, T_Type2>& a_crTuple)
{ CALL
  return a_crTuple.getValue1();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2>
inline T_Type2& MComparableTupleValue<2, NDetails::CComparableDuo<T_Type1, T_Type2> >::getValue(NDetails::CComparableDuo<T_Type1, T_Type2>& a_rTuple)
{ CALL
  return a_rTuple.getValue2();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2>
inline const T_Type2& MComparableTupleValue<2, NDetails::CComparableDuo<T_Type1, T_Type2> >::getValue(const NDetails::CComparableDuo<T_Type1, T_Type2>& a_crTuple)
{ CALL
  return a_crTuple.getValue2();
}
/*--------------------------------------------------------------------------*/
template <Tsint t_N, typename T_Type1, typename T_Type2, typename T_Type3>
inline typename MComparableTupleType<t_N - 1, NDetails::CComparableDuo<T_Type2, T_Type3> >::TType& MComparableTupleValue<t_N, NDetails::CComparableDuo<T_Type1, NDetails::CComparableDuo<T_Type2, T_Type3> > >::getValue(NDetails::CComparableDuo<T_Type1, NDetails::CComparableDuo<T_Type2, T_Type3> >& a_rTuple)
{ CALL
  return MComparableTupleValue<t_N - 1, NDetails::CComparableDuo<T_Type2, T_Type3> >::getValue(a_rTuple.getValue2());
}
/*--------------------------------------------------------------------------*/
template <Tsint t_N, typename T_Type1, typename T_Type2, typename T_Type3>
inline const typename MComparableTupleType<t_N - 1, NDetails::CComparableDuo<T_Type2, T_Type3> >::TType& MComparableTupleValue<t_N, NDetails::CComparableDuo<T_Type1, NDetails::CComparableDuo<T_Type2, T_Type3> > >::getValue(const NDetails::CComparableDuo<T_Type1, NDetails::CComparableDuo<T_Type2, T_Type3> >& a_crTuple)
{ CALL
  return MComparableTupleValue<t_N - 1, NDetails::CComparableDuo<T_Type2, T_Type3> >::getValue(a_crTuple.getValue2());
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3>
inline T_Type1& MComparableTupleValue<1, NDetails::CComparableDuo<T_Type1, NDetails::CComparableDuo<T_Type2, T_Type3> > >::getValue(NDetails::CComparableDuo<T_Type1, NDetails::CComparableDuo<T_Type2, T_Type3> >& a_rTuple)
{ CALL
  return a_rTuple.getValue1();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3>
inline const T_Type1& MComparableTupleValue<1, NDetails::CComparableDuo<T_Type1, NDetails::CComparableDuo<T_Type2, T_Type3> > >::getValue(const NDetails::CComparableDuo<T_Type1, NDetails::CComparableDuo<T_Type2, T_Type3> >& a_crTuple)
{ CALL
  return a_crTuple.getValue1();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3>
inline T_Type2& MComparableTupleValue<2, NDetails::CComparableDuo<T_Type1, NDetails::CComparableDuo<T_Type2, T_Type3> > >::getValue(NDetails::CComparableDuo<T_Type1, NDetails::CComparableDuo<T_Type2, T_Type3> >& a_rTuple)
{ CALL
  return a_rTuple.getValue2().getValue1();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3>
inline const T_Type2& MComparableTupleValue<2, NDetails::CComparableDuo<T_Type1, NDetails::CComparableDuo<T_Type2, T_Type3> > >::getValue(const NDetails::CComparableDuo<T_Type1, NDetails::CComparableDuo<T_Type2, T_Type3> >& a_crTuple)
{ CALL
  return a_crTuple.getValue2().getValue1();
}
/*==========================================================================*/
/* INLINE FUNCTION IMPLEMENTATIONS                                          */
/*==========================================================================*/
template <Tsint t_N, typename T_Type1, typename T_Type2>
inline typename MComparableTupleType<t_N, NDetails::CComparableDuo<T_Type1, T_Type2> >::TType& getValue(NDetails::CComparableDuo<T_Type1, T_Type2>& a_rTuple)
{ CALL
  return MComparableTupleValue<t_N, NDetails::CComparableDuo<T_Type1, T_Type2> >::getValue(a_rTuple);
}
/*--------------------------------------------------------------------------*/
template <Tsint t_N, typename T_Type1, typename T_Type2>
inline const typename MComparableTupleType<t_N, NDetails::CComparableDuo<T_Type1, T_Type2> >::TType& getValue(const NDetails::CComparableDuo<T_Type1, T_Type2>& a_crTuple)
{ CALL
  return MComparableTupleValue<t_N, NDetails::CComparableDuo<T_Type1, T_Type2> >::getValue(a_crTuple);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
