/*!
 *  \file    MTupleValue.inl Contains set of meta-classes to get the fixed
 *           tuple value.
 *  \brief   Tuple value meta-classes (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tuple value meta-classes (inline).

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
#ifndef __MTUPLEVALUE_INL__
#define __MTUPLEVALUE_INL__
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
inline void MTupleValue<t_N, T_Type>::getValue(T_Type& a_rTuple)
{ CALL
  IGNORE_UNUSED(a_rTuple);
}
/*--------------------------------------------------------------------------*/
template <Tsint t_N, typename T_Type>
inline void MTupleValue<t_N, T_Type>::getValue(const T_Type& a_crTuple)
{ CALL
  IGNORE_UNUSED(a_crTuple);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2>
inline T_Type1& MTupleValue<1, NDetails::CDuo<T_Type1, T_Type2> >::getValue(NDetails::CDuo<T_Type1, T_Type2>& a_rTuple)
{ CALL
  return a_rTuple.getValue1();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2>
inline const T_Type1& MTupleValue<1, NDetails::CDuo<T_Type1, T_Type2> >::getValue(const NDetails::CDuo<T_Type1, T_Type2>& a_crTuple)
{ CALL
  return a_crTuple.getValue1();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2>
inline T_Type2& MTupleValue<2, NDetails::CDuo<T_Type1, T_Type2> >::getValue(NDetails::CDuo<T_Type1, T_Type2>& a_rTuple)
{ CALL
  return a_rTuple.getValue2();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2>
inline const T_Type2& MTupleValue<2, NDetails::CDuo<T_Type1, T_Type2> >::getValue(const NDetails::CDuo<T_Type1, T_Type2>& a_crTuple)
{ CALL
  return a_crTuple.getValue2();
}
/*--------------------------------------------------------------------------*/
template <Tsint t_N, typename T_Type1, typename T_Type2, typename T_Type3>
inline typename MTupleType<t_N - 1, NDetails::CDuo<T_Type2, T_Type3> >::TType& MTupleValue<t_N, NDetails::CDuo<T_Type1, NDetails::CDuo<T_Type2, T_Type3> > >::getValue(NDetails::CDuo<T_Type1, NDetails::CDuo<T_Type2, T_Type3> >& a_rTuple)
{ CALL
  return MTupleValue<t_N - 1, NDetails::CDuo<T_Type2, T_Type3> >::getValue(a_rTuple.getValue2());
}
/*--------------------------------------------------------------------------*/
template <Tsint t_N, typename T_Type1, typename T_Type2, typename T_Type3>
inline const typename MTupleType<t_N - 1, NDetails::CDuo<T_Type2, T_Type3> >::TType& MTupleValue<t_N, NDetails::CDuo<T_Type1, NDetails::CDuo<T_Type2, T_Type3> > >::getValue(const NDetails::CDuo<T_Type1, NDetails::CDuo<T_Type2, T_Type3> >& a_crTuple)
{ CALL
  return MTupleValue<t_N - 1, NDetails::CDuo<T_Type2, T_Type3> >::getValue(a_crTuple.getValue2());
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3>
inline T_Type1& MTupleValue<1, NDetails::CDuo<T_Type1, NDetails::CDuo<T_Type2, T_Type3> > >::getValue(NDetails::CDuo<T_Type1, NDetails::CDuo<T_Type2, T_Type3> >& a_rTuple)
{ CALL
  return a_rTuple.getValue1();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3>
inline const T_Type1& MTupleValue<1, NDetails::CDuo<T_Type1, NDetails::CDuo<T_Type2, T_Type3> > >::getValue(const NDetails::CDuo<T_Type1, NDetails::CDuo<T_Type2, T_Type3> >& a_crTuple)
{ CALL
  return a_crTuple.getValue1();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3>
inline T_Type2& MTupleValue<2, NDetails::CDuo<T_Type1, NDetails::CDuo<T_Type2, T_Type3> > >::getValue(NDetails::CDuo<T_Type1, NDetails::CDuo<T_Type2, T_Type3> >& a_rTuple)
{ CALL
  return a_rTuple.getValue2().getValue1();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3>
inline const T_Type2& MTupleValue<2, NDetails::CDuo<T_Type1, NDetails::CDuo<T_Type2, T_Type3> > >::getValue(const NDetails::CDuo<T_Type1, NDetails::CDuo<T_Type2, T_Type3> >& a_crTuple)
{ CALL
  return a_crTuple.getValue2().getValue1();
}
/*==========================================================================*/
/* INLINE FUNCTION IMPLEMENTATIONS                                          */
/*==========================================================================*/
template <Tsint t_N, typename T_Type1, typename T_Type2>
inline typename MTupleType<t_N, NDetails::CDuo<T_Type1, T_Type2> >::TType& getValue(NDetails::CDuo<T_Type1, T_Type2>& a_rTuple)
{ CALL
  return MTupleValue<t_N, NDetails::CDuo<T_Type1, T_Type2> >::getValue(a_rTuple);
}
/*--------------------------------------------------------------------------*/
template <Tsint t_N, typename T_Type1, typename T_Type2>
inline const typename MTupleType<t_N, NDetails::CDuo<T_Type1, T_Type2> >::TType& getValue(const NDetails::CDuo<T_Type1, T_Type2>& a_crTuple)
{ CALL
  return MTupleValue<t_N, NDetails::CDuo<T_Type1, T_Type2> >::getValue(a_crTuple);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
