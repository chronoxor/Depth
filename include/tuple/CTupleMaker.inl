/*!
 *  \file    CTupleMaker.inl Utility class that helps to make CTuple
 *           instances from specific values.
 *  \brief   Tuple maker class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    13.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tuple maker class (inline).

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
#ifndef __CTUPLEMAKER_INL__
#define __CTUPLEMAKER_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTuple {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
//*==========================================================================*/
template <typename T_Type>
inline CTuple<T_Type> CTupleMaker::make(const T_Type& a_crValue)
{ CALL
  return CTuple<T_Type>(a_crValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2>
inline CTuple<T_Type1, T_Type2> CTupleMaker::make(const T_Type1& a_crValue1, const T_Type2& a_crValue2)
{ CALL
  return CTuple<T_Type1, T_Type2>(a_crValue1, a_crValue2);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3>
inline CTuple<T_Type1, T_Type2, T_Type3> CTupleMaker::make(const T_Type1& a_crValue1, const T_Type2& a_crValue2, const T_Type3& a_crValue3)
{ CALL
  return CTuple<T_Type1, T_Type2, T_Type3>(a_crValue1, a_crValue2, a_crValue3);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4>
inline CTuple<T_Type1, T_Type2, T_Type3, T_Type4> CTupleMaker::make(const T_Type1& a_crValue1, const T_Type2& a_crValue2, const T_Type3& a_crValue3, const T_Type4& a_crValue4)
{ CALL
  return CTuple<T_Type1, T_Type2, T_Type3, T_Type4>(a_crValue1, a_crValue2, a_crValue3, a_crValue4);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5>
inline CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5> CTupleMaker::make(const T_Type1& a_crValue1, const T_Type2& a_crValue2, const T_Type3& a_crValue3, const T_Type4& a_crValue4, const T_Type5& a_crValue5)
{ CALL
  return CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5>(a_crValue1, a_crValue2, a_crValue3, a_crValue4, a_crValue5);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6>
inline CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6> CTupleMaker::make(const T_Type1& a_crValue1, const T_Type2& a_crValue2, const T_Type3& a_crValue3, const T_Type4& a_crValue4, const T_Type5& a_crValue5, const T_Type6& a_crValue6)
{ CALL
  return CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6>(a_crValue1, a_crValue2, a_crValue3, a_crValue4, a_crValue5, a_crValue6);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7>
inline CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7> CTupleMaker::make(const T_Type1& a_crValue1, const T_Type2& a_crValue2, const T_Type3& a_crValue3, const T_Type4& a_crValue4, const T_Type5& a_crValue5, const T_Type6& a_crValue6, const T_Type7& a_crValue7)
{ CALL
  return CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7>(a_crValue1, a_crValue2, a_crValue3, a_crValue4, a_crValue5, a_crValue6, a_crValue7);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8>
inline CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8> CTupleMaker::make(const T_Type1& a_crValue1, const T_Type2& a_crValue2, const T_Type3& a_crValue3, const T_Type4& a_crValue4, const T_Type5& a_crValue5, const T_Type6& a_crValue6, const T_Type7& a_crValue7, const T_Type8& a_crValue8)
{ CALL
  return CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8>(a_crValue1, a_crValue2, a_crValue3, a_crValue4, a_crValue5, a_crValue6, a_crValue7, a_crValue8);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9>
inline CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9> CTupleMaker::make(const T_Type1& a_crValue1, const T_Type2& a_crValue2, const T_Type3& a_crValue3, const T_Type4& a_crValue4, const T_Type5& a_crValue5, const T_Type6& a_crValue6, const T_Type7& a_crValue7, const T_Type8& a_crValue8, const T_Type9& a_crValue9)
{ CALL
  return CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9>(a_crValue1, a_crValue2, a_crValue3, a_crValue4, a_crValue5, a_crValue6, a_crValue7, a_crValue8, a_crValue9);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9, typename T_Type10>
inline CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10> CTupleMaker::make(const T_Type1& a_crValue1, const T_Type2& a_crValue2, const T_Type3& a_crValue3, const T_Type4& a_crValue4, const T_Type5& a_crValue5, const T_Type6& a_crValue6, const T_Type7& a_crValue7, const T_Type8& a_crValue8, const T_Type9& a_crValue9, const T_Type10& a_crValue10)
{ CALL
  return CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>(a_crValue1, a_crValue2, a_crValue3, a_crValue4, a_crValue5, a_crValue6, a_crValue7, a_crValue8, a_crValue9, a_crValue10);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CTuple<T_Type> CTupleMaker::make(const CTuple<T_Type>& a_crInstance)
{ CALL
  return CTuple<T_Type>(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2>
inline CTuple<T_Type1, T_Type2> CTupleMaker::make(const CTuple<T_Type1, T_Type2>& a_crInstance)
{ CALL
  return CTuple<T_Type1, T_Type2>(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3>
inline CTuple<T_Type1, T_Type2, T_Type3> CTupleMaker::make(const CTuple<T_Type1, T_Type2, T_Type3>& a_crInstance)
{ CALL
  return CTuple<T_Type1, T_Type2, T_Type3>(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4>
inline CTuple<T_Type1, T_Type2, T_Type3, T_Type4> CTupleMaker::make(const CTuple<T_Type1, T_Type2, T_Type3, T_Type4>& a_crInstance)
{ CALL
  return CTuple<T_Type1, T_Type2, T_Type3, T_Type4>(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5>
inline CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5> CTupleMaker::make(const CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5>& a_crInstance)
{ CALL
  return CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5>(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6>
inline CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6> CTupleMaker::make(const CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6>& a_crInstance)
{ CALL
  return CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6>(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7>
inline CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7> CTupleMaker::make(const CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7>& a_crInstance)
{ CALL
  return CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7>(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8>
inline CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8> CTupleMaker::make(const CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8>& a_crInstance)
{ CALL
  return CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8>(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9>
inline CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9> CTupleMaker::make(const CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9>& a_crInstance)
{ CALL
  return CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9>(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9, typename T_Type10>
inline CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10> CTupleMaker::make(const CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>& a_crInstance)
{ CALL
  return CTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>(a_crInstance);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
