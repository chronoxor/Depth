/*!
 *  \file    CCombinerFirstValue.inl First value returning combiner class.
 *  \brief   First value returning combiner class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.06.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: First value returning combiner class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Signal containers
    VERSION:   1.0
    CREATED:   02.06.2006 02:36:52

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
#ifndef __CCOMBINERFIRSTVALUE_INL__
#define __CCOMBINERFIRSTVALUE_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSignals {
/*--------------------------------------------------------------------------*/
namespace NCombiners {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <typename T_SlotReturn, typename T_SignalResult>
inline CCombinerFirstValue<T_SlotReturn, T_SignalResult>::CCombinerFirstValue() :
  ICombiner<T_SlotReturn, T_SignalResult>(),
  m_FirstInited(false),
  m_Result()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_SlotReturn, typename T_SignalResult>
inline CCombinerFirstValue<T_SlotReturn, T_SignalResult>::CCombinerFirstValue(const CCombinerFirstValue<T_SlotReturn, T_SignalResult>& a_crInstance) :
  ICombiner<T_SlotReturn, T_SignalResult>(),
  m_FirstInited(a_crInstance.m_FirstInited),
  m_Result(a_crInstance.m_Result)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_SlotReturn, typename T_SignalResult>
inline CCombinerFirstValue<T_SlotReturn, T_SignalResult>::~CCombinerFirstValue()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_SlotReturn, typename T_SignalResult>
inline Tbool operator == (const CCombinerFirstValue<T_SlotReturn, T_SignalResult>& a_crInstance1, const CCombinerFirstValue<T_SlotReturn, T_SignalResult>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_FirstInited == a_crInstance2.m_FirstInited) && (a_crInstance1.m_Result == a_crInstance2.m_Result));
}
/*--------------------------------------------------------------------------*/
template <typename T_SlotReturn, typename T_SignalResult>
inline Tbool operator != (const CCombinerFirstValue<T_SlotReturn, T_SignalResult>& a_crInstance1, const CCombinerFirstValue<T_SlotReturn, T_SignalResult>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_FirstInited != a_crInstance2.m_FirstInited) || (a_crInstance1.m_Result != a_crInstance2.m_Result));
}
/*--------------------------------------------------------------------------*/
template <typename T_SlotReturn, typename T_SignalResult>
inline CCombinerFirstValue<T_SlotReturn, T_SignalResult>& CCombinerFirstValue<T_SlotReturn, T_SignalResult>::operator = (const CCombinerFirstValue<T_SlotReturn, T_SignalResult>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_SlotReturn, typename T_SignalResult>
inline void CCombinerFirstValue<T_SlotReturn, T_SignalResult>::set(const CCombinerFirstValue<T_SlotReturn, T_SignalResult>& a_crInstance)
{ CALL
  m_FirstInited = a_crInstance.m_FirstInited;
  m_Result = a_crInstance.m_Result;
}
/*--------------------------------------------------------------------------*/
template <typename T_SlotReturn, typename T_SignalResult>
inline Tbool CCombinerFirstValue<T_SlotReturn, T_SignalResult>::onStart()
{ CALL
  m_FirstInited = false;
  m_Result = T_SlotReturn();
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_SlotReturn, typename T_SignalResult>
inline Tbool CCombinerFirstValue<T_SlotReturn, T_SignalResult>::onNext(const T_SlotReturn& a_crSlotReturn)
{ CALL
  if (!m_FirstInited)
  {
    m_FirstInited = true;
    m_Result = a_crSlotReturn;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_SlotReturn, typename T_SignalResult>
inline T_SignalResult CCombinerFirstValue<T_SlotReturn, T_SignalResult>::onEnd()
{ CALL
  return (T_SignalResult)m_Result;
}
/*--------------------------------------------------------------------------*/
template <typename T_SlotReturn, typename T_SignalResult>
template <class T_Archive>
inline Tbool CCombinerFirstValue<T_SlotReturn, T_SignalResult>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NSignals::NCombiners::CCombinerFirstValue<T_SlotReturn, T_SignalResult>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_FirstInited, STR("m_FirstInited")));
    CHECK(a_rArchive.doValue(m_Result, STR("m_Result")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_SlotReturn, typename T_SignalResult>
inline void CCombinerFirstValue<T_SlotReturn, T_SignalResult>::swap(CCombinerFirstValue<T_SlotReturn, T_SignalResult>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_FirstInited, a_rInstance.m_FirstInited);
  NAlgorithms::NCommon::swap(m_Result, a_rInstance.m_Result);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
