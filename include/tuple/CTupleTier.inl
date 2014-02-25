/*!
 *  \file    CTupleTier.inl Utility class that helps to tie CTuple instances
 *           with specified references to values.
 *  \brief   Tuple tier class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    13.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tuple tier class (inline).

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
#ifndef __CTUPLETIER_INL__
#define __CTUPLETIER_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTuple {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <typename T_Type>
inline CTuple<NBase::CReference<T_Type> > CTupleTier::tie(T_Type& a_rValue)
{ CALL
  return CTuple<NBase::CReference<T_Type> >(NBase::CReference<T_Type>(a_rValue));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2>
inline CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2> > CTupleTier::tie(T_Type1& a_rValue1, T_Type2& a_rValue2)
{ CALL
  return CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2> >(NBase::CReference<T_Type1>(a_rValue1), NBase::CReference<T_Type2>(a_rValue2));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3>
inline CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3> > CTupleTier::tie(T_Type1& a_rValue1, T_Type2& a_rValue2, T_Type3& a_rValue3)
{ CALL
  return CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3> >(NBase::CReference<T_Type1>(a_rValue1), NBase::CReference<T_Type2>(a_rValue2), NBase::CReference<T_Type3>(a_rValue3));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4>
inline CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4> > CTupleTier::tie(T_Type1& a_rValue1, T_Type2& a_rValue2, T_Type3& a_rValue3, T_Type4& a_rValue4)
{ CALL
  return CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4> >(NBase::CReference<T_Type1>(a_rValue1), NBase::CReference<T_Type2>(a_rValue2), NBase::CReference<T_Type3>(a_rValue3), NBase::CReference<T_Type4>(a_rValue4));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5>
inline CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5> > CTupleTier::tie(T_Type1& a_rValue1, T_Type2& a_rValue2, T_Type3& a_rValue3, T_Type4& a_rValue4, T_Type5& a_rValue5)
{ CALL
  return CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5> >(NBase::CReference<T_Type1>(a_rValue1), NBase::CReference<T_Type2>(a_rValue2), NBase::CReference<T_Type3>(a_rValue3), NBase::CReference<T_Type4>(a_rValue4), NBase::CReference<T_Type5>(a_rValue5));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6>
inline CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6> > CTupleTier::tie(T_Type1& a_rValue1, T_Type2& a_rValue2, T_Type3& a_rValue3, T_Type4& a_rValue4, T_Type5& a_rValue5, T_Type6& a_rValue6)
{ CALL
  return CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6> >(NBase::CReference<T_Type1>(a_rValue1), NBase::CReference<T_Type2>(a_rValue2), NBase::CReference<T_Type3>(a_rValue3), NBase::CReference<T_Type4>(a_rValue4), NBase::CReference<T_Type5>(a_rValue5), NBase::CReference<T_Type6>(a_rValue6));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7>
inline CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7> > CTupleTier::tie(T_Type1& a_rValue1, T_Type2& a_rValue2, T_Type3& a_rValue3, T_Type4& a_rValue4, T_Type5& a_rValue5, T_Type6& a_rValue6, T_Type7& a_rValue7)
{ CALL
  return CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7> >(NBase::CReference<T_Type1>(a_rValue1), NBase::CReference<T_Type2>(a_rValue2), NBase::CReference<T_Type3>(a_rValue3), NBase::CReference<T_Type4>(a_rValue4), NBase::CReference<T_Type5>(a_rValue5), NBase::CReference<T_Type6>(a_rValue6), NBase::CReference<T_Type7>(a_rValue7));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8>
inline CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8> > CTupleTier::tie(T_Type1& a_rValue1, T_Type2& a_rValue2, T_Type3& a_rValue3, T_Type4& a_rValue4, T_Type5& a_rValue5, T_Type6& a_rValue6, T_Type7& a_rValue7, T_Type8& a_rValue8)
{ CALL
  return CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8> >(NBase::CReference<T_Type1>(a_rValue1), NBase::CReference<T_Type2>(a_rValue2), NBase::CReference<T_Type3>(a_rValue3), NBase::CReference<T_Type4>(a_rValue4), NBase::CReference<T_Type5>(a_rValue5), NBase::CReference<T_Type6>(a_rValue6), NBase::CReference<T_Type7>(a_rValue7), NBase::CReference<T_Type8>(a_rValue8));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9>
inline CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8>, NBase::CReference<T_Type9> > CTupleTier::tie(T_Type1& a_rValue1, T_Type2& a_rValue2, T_Type3& a_rValue3, T_Type4& a_rValue4, T_Type5& a_rValue5, T_Type6& a_rValue6, T_Type7& a_rValue7, T_Type8& a_rValue8, T_Type9& a_rValue9)
{ CALL
  return CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8>, NBase::CReference<T_Type9> >(NBase::CReference<T_Type1>(a_rValue1), NBase::CReference<T_Type2>(a_rValue2), NBase::CReference<T_Type3>(a_rValue3), NBase::CReference<T_Type4>(a_rValue4), NBase::CReference<T_Type5>(a_rValue5), NBase::CReference<T_Type6>(a_rValue6), NBase::CReference<T_Type7>(a_rValue7), NBase::CReference<T_Type8>(a_rValue8), NBase::CReference<T_Type9>(a_rValue9));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9, typename T_Type10>
inline CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8>, NBase::CReference<T_Type9>, NBase::CReference<T_Type10> > CTupleTier::tie(T_Type1& a_rValue1, T_Type2& a_rValue2, T_Type3& a_rValue3, T_Type4& a_rValue4, T_Type5& a_rValue5, T_Type6& a_rValue6, T_Type7& a_rValue7, T_Type8& a_rValue8, T_Type9& a_rValue9, T_Type10& a_rValue10)
{ CALL
  return CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8>, NBase::CReference<T_Type9>, NBase::CReference<T_Type10> >(NBase::CReference<T_Type1>(a_rValue1), NBase::CReference<T_Type2>(a_rValue2), NBase::CReference<T_Type3>(a_rValue3), NBase::CReference<T_Type4>(a_rValue4), NBase::CReference<T_Type5>(a_rValue5), NBase::CReference<T_Type6>(a_rValue6), NBase::CReference<T_Type7>(a_rValue7), NBase::CReference<T_Type8>(a_rValue8), NBase::CReference<T_Type9>(a_rValue9), NBase::CReference<T_Type10>(a_rValue10));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CTuple<NBase::CReference<T_Type> > CTupleTier::tie(CTuple<T_Type>& a_rInstance)
{ CALL
  return CTuple<NBase::CReference<T_Type> >(NBase::CReference<T_Type>(a_rInstance.getValue<1>()));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2>
inline CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2> > CTupleTier::tie(CTuple<T_Type1, T_Type2>& a_rInstance)
{ CALL
  return CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2> >(NBase::CReference<T_Type1>(a_rInstance.getValue<1>()), NBase::CReference<T_Type2>(a_rInstance.getValue<2>()));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3>
inline CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3> > CTupleTier::tie(CTuple<T_Type1, T_Type2, T_Type3>& a_rInstance)
{ CALL
  return CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3> >(NBase::CReference<T_Type1>(a_rInstance.getValue<1>()), NBase::CReference<T_Type2>(a_rInstance.getValue<2>()), NBase::CReference<T_Type3>(a_rInstance.getValue<3>()));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4>
inline CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4> > CTupleTier::tie(CTuple<T_Type1, T_Type2, T_Type3, T_Type4>& a_rInstance)
{ CALL
  return CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4> >(NBase::CReference<T_Type1>(a_rInstance.getValue<1>()), NBase::CReference<T_Type2>(a_rInstance.getValue<2>()), NBase::CReference<T_Type3>(a_rInstance.getValue<3>()), NBase::CReference<T_Type4>(a_rInstance.getValue<4>()));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5>
inline CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5> > CTupleTier::tie(CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5>& a_rInstance)
{ CALL
  return CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5> >(NBase::CReference<T_Type1>(a_rInstance.getValue<1>()), NBase::CReference<T_Type2>(a_rInstance.getValue<2>()), NBase::CReference<T_Type3>(a_rInstance.getValue<3>()), NBase::CReference<T_Type4>(a_rInstance.getValue<4>()), NBase::CReference<T_Type5>(a_rInstance.getValue<5>()));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6>
inline CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6> > CTupleTier::tie(CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6>& a_rInstance)
{ CALL
  return CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6> >(NBase::CReference<T_Type1>(a_rInstance.getValue<1>()), NBase::CReference<T_Type2>(a_rInstance.getValue<2>()), NBase::CReference<T_Type3>(a_rInstance.getValue<3>()), NBase::CReference<T_Type4>(a_rInstance.getValue<4>()), NBase::CReference<T_Type5>(a_rInstance.getValue<5>()), NBase::CReference<T_Type6>(a_rInstance.getValue<6>()));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7>
inline CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7> > CTupleTier::tie(CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7>& a_rInstance)
{ CALL
  return CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7> >(NBase::CReference<T_Type1>(a_rInstance.getValue<1>()), NBase::CReference<T_Type2>(a_rInstance.getValue<2>()), NBase::CReference<T_Type3>(a_rInstance.getValue<3>()), NBase::CReference<T_Type4>(a_rInstance.getValue<4>()), NBase::CReference<T_Type5>(a_rInstance.getValue<5>()), NBase::CReference<T_Type6>(a_rInstance.getValue<6>()), NBase::CReference<T_Type7>(a_rInstance.getValue<7>()));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8>
inline CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8> > CTupleTier::tie(CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8>& a_rInstance)
{ CALL
  return CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8> >(NBase::CReference<T_Type1>(a_rInstance.getValue<1>()), NBase::CReference<T_Type2>(a_rInstance.getValue<2>()), NBase::CReference<T_Type3>(a_rInstance.getValue<3>()), NBase::CReference<T_Type4>(a_rInstance.getValue<4>()), NBase::CReference<T_Type5>(a_rInstance.getValue<5>()), NBase::CReference<T_Type6>(a_rInstance.getValue<6>()), NBase::CReference<T_Type7>(a_rInstance.getValue<7>()), NBase::CReference<T_Type8>(a_rInstance.getValue<8>()));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9>
inline CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8>, NBase::CReference<T_Type9> > CTupleTier::tie(CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9>& a_rInstance)
{ CALL
  return CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8>, NBase::CReference<T_Type9> >(NBase::CReference<T_Type1>(a_rInstance.getValue<1>()), NBase::CReference<T_Type2>(a_rInstance.getValue<2>()), NBase::CReference<T_Type3>(a_rInstance.getValue<3>()), NBase::CReference<T_Type4>(a_rInstance.getValue<4>()), NBase::CReference<T_Type5>(a_rInstance.getValue<5>()), NBase::CReference<T_Type6>(a_rInstance.getValue<6>()), NBase::CReference<T_Type7>(a_rInstance.getValue<7>()), NBase::CReference<T_Type8>(a_rInstance.getValue<8>()), NBase::CReference<T_Type9>(a_rInstance.getValue<9>()));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9, typename T_Type10>
inline CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8>, NBase::CReference<T_Type9>, NBase::CReference<T_Type10> > CTupleTier::tie(CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>& a_rInstance)
{ CALL
  return CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8>, NBase::CReference<T_Type9>, NBase::CReference<T_Type10> >(NBase::CReference<T_Type1>(a_rInstance.getValue<1>()), NBase::CReference<T_Type2>(a_rInstance.getValue<2>()), NBase::CReference<T_Type3>(a_rInstance.getValue<3>()), NBase::CReference<T_Type4>(a_rInstance.getValue<4>()), NBase::CReference<T_Type5>(a_rInstance.getValue<5>()), NBase::CReference<T_Type6>(a_rInstance.getValue<6>()), NBase::CReference<T_Type7>(a_rInstance.getValue<7>()), NBase::CReference<T_Type8>(a_rInstance.getValue<8>()), NBase::CReference<T_Type9>(a_rInstance.getValue<9>()), NBase::CReference<T_Type10>(a_rInstance.getValue<10>()));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CTuple<NBase::CReference<T_Type> > CTupleTier::tie(CTuple<NBase::CReference<T_Type> >& a_rInstance)
{ CALL
  return CTuple<NBase::CReference<T_Type> >(a_rInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2>
inline CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2> > CTupleTier::tie(CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2> >& a_rInstance)
{ CALL
  return CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2> >(a_rInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3>
inline CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3> > CTupleTier::tie(CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3> >& a_rInstance)
{ CALL
  return CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3> >(a_rInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4>
inline CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4> > CTupleTier::tie(CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4> >& a_rInstance)
{ CALL
  return CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4> >(a_rInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5>
inline CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5> > CTupleTier::tie(CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5> >& a_rInstance)
{ CALL
  return CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5> >(a_rInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6>
inline CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6> > CTupleTier::tie(CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6> >& a_rInstance)
{ CALL
  return CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6> >(a_rInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7>
inline CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7> > CTupleTier::tie(CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7> >& a_rInstance)
{ CALL
  return CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7> >(a_rInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8>
inline CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8> > CTupleTier::tie(CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8> >& a_rInstance)
{ CALL
  return CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8> >(a_rInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9>
inline CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8>, NBase::CReference<T_Type9> > CTupleTier::tie(CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8>, NBase::CReference<T_Type9> >& a_rInstance)
{ CALL
  return CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8>, NBase::CReference<T_Type9> >(a_rInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9, typename T_Type10>
inline CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8>, NBase::CReference<T_Type9>, NBase::CReference<T_Type10> > CTupleTier::tie(CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8>, NBase::CReference<T_Type9>, NBase::CReference<T_Type10> >& a_rInstance)
{ CALL
  return CTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8>, NBase::CReference<T_Type9>, NBase::CReference<T_Type10> >(a_rInstance);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
