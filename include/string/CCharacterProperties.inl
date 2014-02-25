/*!
 *  \file    CCharacterProperties.inl Character properties class provides
 *           special information about ASCII/Unicode character.
 *  \brief   Character properties class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.10.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Character properties class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String
    VERSION:   1.0
    CREATED:   20.10.2009 20:48:38

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
#ifndef __CCHARACTERPROPERTIES_INL__
#define __CCHARACTERPROPERTIES_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NString {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CCharacterProperties::CCharacterProperties() :
  m_Value(0),
  m_UCDIndex(-1)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CCharacterProperties::CCharacterProperties(const Tschar a_cCharacter) :
  m_Value(0),
  m_UCDIndex(-1)
{ CALL
  set(a_cCharacter);
}
/*--------------------------------------------------------------------------*/
inline CCharacterProperties::CCharacterProperties(const Twchar a_cCharacter) :
  m_Value(0),
  m_UCDIndex(-1)
{ CALL
  set(a_cCharacter);
}
/*--------------------------------------------------------------------------*/
inline CCharacterProperties::CCharacterProperties(const Tuint a_cCharacter) :
  m_Value(0),
  m_UCDIndex(-1)
{ CALL
  set(a_cCharacter);
}
/*--------------------------------------------------------------------------*/
inline CCharacterProperties::CCharacterProperties(const CCharacter& a_crCharacter) :
  m_Value(0),
  m_UCDIndex(-1)
{ CALL
  set(a_crCharacter);
}
/*--------------------------------------------------------------------------*/
inline CCharacterProperties::CCharacterProperties(const CCharacterProperties& a_crInstance) :
  m_Value(a_crInstance.m_Value),
  m_UCDIndex(a_crInstance.m_UCDIndex)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CCharacterProperties::~CCharacterProperties()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator == (const CCharacterProperties& a_crInstance1, const CCharacterProperties& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_Value == a_crInstance2.m_Value) && (a_crInstance1.m_UCDIndex == a_crInstance2.m_UCDIndex));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator != (const CCharacterProperties& a_crInstance1, const CCharacterProperties& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_Value != a_crInstance2.m_Value) || (a_crInstance1.m_UCDIndex != a_crInstance2.m_UCDIndex));
}
/*--------------------------------------------------------------------------*/
inline CCharacterProperties& CCharacterProperties::operator = (const Tschar a_cCharacter)
{ CALL
  set(a_cCharacter);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CCharacterProperties& CCharacterProperties::operator = (const Twchar a_cCharacter)
{ CALL
  set(a_cCharacter);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CCharacterProperties& CCharacterProperties::operator = (const Tuint a_cCharacter)
{ CALL
  set(a_cCharacter);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CCharacterProperties& CCharacterProperties::operator = (const CCharacter& a_crCharacter)
{ CALL
  set(a_crCharacter);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CCharacterProperties& CCharacterProperties::operator = (const CCharacterProperties& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline void CCharacterProperties::set(const CCharacterProperties& a_crInstance)
{ CALL
  m_Value = a_crInstance.m_Value;
  m_UCDIndex = a_crInstance.m_UCDIndex;
}
/*--------------------------------------------------------------------------*/
inline Tbool CCharacterProperties::isValid() const
{ CALL
  return (m_UCDIndex >= 0);
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CCharacterProperties::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NString::CCharacterProperties")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_Value, STR("m_Value")));
    CHECK(a_rArchive.doValue(m_UCDIndex, STR("m_UCDIndex")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
inline void CCharacterProperties::swap(CCharacterProperties& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_Value, a_rInstance.m_Value);
  NAlgorithms::NCommon::swap(m_UCDIndex, a_rInstance.m_UCDIndex);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
