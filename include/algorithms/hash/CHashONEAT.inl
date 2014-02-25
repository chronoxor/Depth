/*!
 *  \file    CHashONEAT.inl ONEAT hash function algorithm.
 *  \brief   ONEAT hash function algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.03.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: ONEAT hash function algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Hash functions algorithms
    VERSION:   1.0
    CREATED:   11.03.2007 01:15:52

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
#ifndef __CHASHONEAT_INL__
#define __CHASHONEAT_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NHash {
/*==========================================================================*/
/* INLINE ALGORITHM IMPLEMENTATIONS                                         */
/*==========================================================================*/
inline CHashONEAT::CHashONEAT() :
  IHash(),
  m_A(0),
  m_B(0),
  m_C(0),
  m_Index(0),
  m_Size(0)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CHashONEAT::CHashONEAT(const CHashONEAT& a_crInstance) :
  IHash(),
  m_A(a_crInstance.m_A),
  m_B(a_crInstance.m_B),
  m_C(a_crInstance.m_C),
  m_Index(a_crInstance.m_Index),
  m_Size(a_crInstance.m_Size)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CHashONEAT::~CHashONEAT()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CHashONEAT& CHashONEAT::operator = (const CHashONEAT& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline void CHashONEAT::set(const CHashONEAT& a_crInstance)
{ CALL
  m_A = a_crInstance.m_A;
  m_B = a_crInstance.m_B;
  m_C = a_crInstance.m_C;
  m_Index = a_crInstance.m_Index;
  m_Size = a_crInstance.m_Size;
}
/*--------------------------------------------------------------------------*/
inline Tuint CHashONEAT::getHash() const
{ CALL
  return m_C;
}
/*--------------------------------------------------------------------------*/
inline Tbool CHashONEAT::initialize(const Tuint a_cSeed/* = 0x9E3779B9 */)
{ CALL
  m_A = a_cSeed;
  m_B = a_cSeed;
  m_C = a_cSeed;
  m_Index = 0;
  m_Size = 0;
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CHashONEAT::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NAlgorithms::NHash::CHashONEAT")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_A, STR("m_A")));
    CHECK(a_rArchive.doValue(m_B, STR("m_B")));
    CHECK(a_rArchive.doValue(m_C, STR("m_C")));
    CHECK(a_rArchive.doValue(m_Index, STR("m_Index")));
    CHECK(a_rArchive.doValue(m_Size, STR("m_Size")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
inline void CHashONEAT::swap(CHashONEAT& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_A, a_rInstance.m_A);
  NAlgorithms::NCommon::swap(m_B, a_rInstance.m_B);
  NAlgorithms::NCommon::swap(m_C, a_rInstance.m_C);
  NAlgorithms::NCommon::swap(m_Index, a_rInstance.m_Index);
  NAlgorithms::NCommon::swap(m_Size, a_rInstance.m_Size);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
