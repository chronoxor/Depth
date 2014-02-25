/*!
 *  \file    CCombinerSummation.inl Summation combiner class.
 *  \brief   Summation combiner class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    23.06.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Summation combiner class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Signal containers
    VERSION:   1.0
    CREATED:   23.06.2008 03:46:43

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
#ifndef __CCOMBINERSUMMATION_INL__
#define __CCOMBINERSUMMATION_INL__
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
inline CCombinerSummation<T_SlotReturn, T_SignalResult>::CCombinerSummation() :
  ICombiner<T_SlotReturn, T_SignalResult>(),
  m_Result()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_SlotReturn, typename T_SignalResult>
inline CCombinerSummation<T_SlotReturn, T_SignalResult>::CCombinerSummation(const CCombinerSummation<T_SlotReturn, T_SignalResult>& a_crInstance) :
  ICombiner<T_SlotReturn, T_SignalResult>(),
  m_Result(a_crInstance.m_Result)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_SlotReturn, typename T_SignalResult>
inline CCombinerSummation<T_SlotReturn, T_SignalResult>::~CCombinerSummation()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_SlotReturn, typename T_SignalResult>
inline Tbool operator == (const CCombinerSummation<T_SlotReturn, T_SignalResult>& a_crInstance1, const CCombinerSummation<T_SlotReturn, T_SignalResult>& a_crInstance2)
{ CALL
  return (a_crInstance1.m_Result == a_crInstance2.m_Result);
}
/*--------------------------------------------------------------------------*/
template <typename T_SlotReturn, typename T_SignalResult>
inline Tbool operator != (const CCombinerSummation<T_SlotReturn, T_SignalResult>& a_crInstance1, const CCombinerSummation<T_SlotReturn, T_SignalResult>& a_crInstance2)
{ CALL
  return (a_crInstance1.m_Result != a_crInstance2.m_Result);
}
/*--------------------------------------------------------------------------*/
template <typename T_SlotReturn, typename T_SignalResult>
inline CCombinerSummation<T_SlotReturn, T_SignalResult>& CCombinerSummation<T_SlotReturn, T_SignalResult>::operator = (const CCombinerSummation<T_SlotReturn, T_SignalResult>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_SlotReturn, typename T_SignalResult>
inline void CCombinerSummation<T_SlotReturn, T_SignalResult>::set(const CCombinerSummation<T_SlotReturn, T_SignalResult>& a_crInstance)
{ CALL
  m_Result = a_crInstance.m_Result;
}
/*--------------------------------------------------------------------------*/
template <typename T_SlotReturn, typename T_SignalResult>
inline Tbool CCombinerSummation<T_SlotReturn, T_SignalResult>::onStart()
{ CALL
  m_Result = T_SlotReturn();
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_SlotReturn, typename T_SignalResult>
inline Tbool CCombinerSummation<T_SlotReturn, T_SignalResult>::onNext(const T_SlotReturn& a_crSlotReturn)
{ CALL
  m_Result += a_crSlotReturn;
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_SlotReturn, typename T_SignalResult>
inline T_SignalResult CCombinerSummation<T_SlotReturn, T_SignalResult>::onEnd()
{ CALL
  return (T_SignalResult)m_Result;
}
/*--------------------------------------------------------------------------*/
template <typename T_SlotReturn, typename T_SignalResult>
template <class T_Archive>
inline Tbool CCombinerSummation<T_SlotReturn, T_SignalResult>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NSignals::NCombiners::CCombinerSummation<T_SlotReturn, T_SignalResult>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_Result, STR("m_Result")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_SlotReturn, typename T_SignalResult>
inline void CCombinerSummation<T_SlotReturn, T_SignalResult>::swap(CCombinerSummation<T_SlotReturn, T_SignalResult>& a_rInstance)
{ CALL
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
