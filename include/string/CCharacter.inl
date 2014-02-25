/*!
 *  \file    CCharacter.inl Character class wraps operations with a single
 *           ASCII/Unicode character.
 *  \brief   Character wrapper class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.08.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Character wrapper class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String
    VERSION:   1.0
    CREATED:   28.08.2007 22:38:11

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
#ifndef __CCHARACTER_INL__
#define __CCHARACTER_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NString {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CCharacter::CCharacter() :
  m_Value(0)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CCharacter::CCharacter(const Tschar a_cCharacter) :
  m_Value(0)
{ CALL
  set(a_cCharacter);
}
/*--------------------------------------------------------------------------*/
inline CCharacter::CCharacter(const Twchar a_cCharacter) :
  m_Value(0)
{ CALL
  set(a_cCharacter);
}
/*--------------------------------------------------------------------------*/
inline CCharacter::CCharacter(const Tuint a_cCharacter) :
  m_Value(0)
{ CALL
  set(a_cCharacter);
}
/*--------------------------------------------------------------------------*/
inline CCharacter::CCharacter(const Tuint08 a_cCell, const Tuint08 a_cRow) :
  m_Value(0)
{ CALL
  set(a_cCell, a_cRow);
}
/*--------------------------------------------------------------------------*/
inline CCharacter::CCharacter(const CCharacter& a_crInstance) :
  m_Value(a_crInstance.m_Value)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CCharacter::~CCharacter()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator == (const CCharacter& a_crInstance1, const CCharacter& a_crInstance2)
{ CALL
  return (a_crInstance1.m_Value == a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator != (const CCharacter& a_crInstance1, const CCharacter& a_crInstance2)
{ CALL
  return (a_crInstance1.m_Value != a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator < (const CCharacter& a_crInstance1, const CCharacter& a_crInstance2)
{ CALL
  return (a_crInstance1.m_Value < a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator > (const CCharacter& a_crInstance1, const CCharacter& a_crInstance2)
{ CALL
  return (a_crInstance1.m_Value > a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator <= (const CCharacter& a_crInstance1, const CCharacter& a_crInstance2)
{ CALL
  return (a_crInstance1.m_Value <= a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator >= (const CCharacter& a_crInstance1, const CCharacter& a_crInstance2)
{ CALL
  return (a_crInstance1.m_Value >= a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tsint operator + (const CCharacter& a_crInstance1, const CCharacter& a_crInstance2)
{ CALL
  return a_crInstance1.m_Value + a_crInstance2.m_Value;
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tsint operator - (const CCharacter& a_crInstance1, const CCharacter& a_crInstance2)
{ CALL
  return a_crInstance1.m_Value - a_crInstance2.m_Value;
}
/*--------------------------------------------------------------------------*/
inline CCharacter& CCharacter::operator = (const Tschar a_cCharacter)
{ CALL
  set(a_cCharacter);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CCharacter& CCharacter::operator = (const Twchar a_cCharacter)
{ CALL
  set(a_cCharacter);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CCharacter& CCharacter::operator = (const Tuint a_cCharacter)
{ CALL
  set(a_cCharacter);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CCharacter& CCharacter::operator = (const CCharacter& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CCharacter::operator Tschar () const
{ CALL
  return getASCII();
}
/*--------------------------------------------------------------------------*/
inline CCharacter::operator Twchar () const
{ CALL
  return getUnicode();
}
/*--------------------------------------------------------------------------*/
inline void CCharacter::set(const Tschar a_cCharacter)
{ CALL
  m_Value = (Tuint)a_cCharacter;
}
/*--------------------------------------------------------------------------*/
inline void CCharacter::set(const Twchar a_cCharacter)
{ CALL
  m_Value = (Tuint)a_cCharacter;
}
/*--------------------------------------------------------------------------*/
inline void CCharacter::set(const Tuint a_cCharacter)
{ CALL
  m_Value = a_cCharacter;
}
/*--------------------------------------------------------------------------*/
inline void CCharacter::set(const Tuint08 a_cCell, const Tuint08 a_cRow)
{ CALL
  m_Value = ((a_cRow << 8) | a_cCell);
}
/*--------------------------------------------------------------------------*/
inline void CCharacter::set(const CCharacter& a_crInstance)
{ CALL
  m_Value = a_crInstance.m_Value;
}
/*--------------------------------------------------------------------------*/
inline void CCharacter::setCell(const Tuint08 a_cCell)
{ CALL
  m_Value = (m_Value & 0xFF00) + a_cCell;
}
/*--------------------------------------------------------------------------*/
inline void CCharacter::setRow(const Tuint08 a_cRow)
{ CALL
  m_Value = (a_cRow << 8) + (m_Value & 0xFF);
}
/*--------------------------------------------------------------------------*/
inline Tuint08 CCharacter::getCell() const
{ CALL
  return (Tuint08)(m_Value & 0xFF);
}
/*--------------------------------------------------------------------------*/
inline Tuint08 CCharacter::getRow() const
{ CALL
  return (Tuint08)((m_Value >> 8) & 0xFF);
}
/*--------------------------------------------------------------------------*/
inline Tbool CCharacter::isValidSystem() const
{ CALL
  return ((m_Value >= getSystemAbsMin()) && (m_Value <= getSystemAbsMax()));
}
/*--------------------------------------------------------------------------*/
inline Tbool CCharacter::isValidASCII() const
{ CALL
  return ((m_Value >= getASCIIAbsMin()) && (m_Value <= getASCIIAbsMax()));
}
/*--------------------------------------------------------------------------*/
inline Tbool CCharacter::isValidUnicode() const
{ CALL
  return ((m_Value >= getUnicodeAbsMin()) && (m_Value <= getUnicodeAbsMax()));
}
/*--------------------------------------------------------------------------*/
inline Tbool CCharacter::isZero() const
{ CALL
  return (m_Value == 0);
}
/*--------------------------------------------------------------------------*/
inline Tuint CCharacter::getUnsigned() const
{ CALL
  return m_Value;
}
/*--------------------------------------------------------------------------*/
inline void CCharacter::clear()
{ CALL
  m_Value = 0;
}
/*--------------------------------------------------------------------------*/
inline Tbool CCharacter::isSystemASCII()
{ CALL
  return NConstants::CConstants::isASCII;
}
/*--------------------------------------------------------------------------*/
inline Tbool CCharacter::isSystemUnicode()
{ CALL
  return NConstants::CConstants::isUnicode;
}
/*--------------------------------------------------------------------------*/
inline Tchar CCharacter::getSystemMin()
{ CALL
  return NConstants::CConstants::charMin;
}
/*--------------------------------------------------------------------------*/
inline Tchar CCharacter::getSystemMax()
{ CALL
  return NConstants::CConstants::charMax;
}
/*--------------------------------------------------------------------------*/
inline Tcharu CCharacter::getSystemAbsMin()
{ CALL
  return NConstants::CConstants::charAbsMin;
}
/*--------------------------------------------------------------------------*/
inline Tcharu CCharacter::getSystemAbsMax()
{ CALL
  return NConstants::CConstants::charAbsMax;
}
/*--------------------------------------------------------------------------*/
inline Tschar CCharacter::getASCIIMin()
{ CALL
  return NConstants::CConstants::scharMin;
}
/*--------------------------------------------------------------------------*/
inline Tschar CCharacter::getASCIIMax()
{ CALL
  return NConstants::CConstants::scharMax;
}
/*--------------------------------------------------------------------------*/
inline Tscharu CCharacter::getASCIIAbsMin()
{ CALL
  return NConstants::CConstants::scharAbsMin;
}
/*--------------------------------------------------------------------------*/
inline Tscharu CCharacter::getASCIIAbsMax()
{ CALL
  return NConstants::CConstants::scharAbsMax;
}
/*--------------------------------------------------------------------------*/
inline Twchar CCharacter::getUnicodeMin()
{ CALL
  return NConstants::CConstants::wcharMin;
}
/*--------------------------------------------------------------------------*/
inline Twchar CCharacter::getUnicodeMax()
{ CALL
  return NConstants::CConstants::wcharMax;
}
/*--------------------------------------------------------------------------*/
inline Twcharu CCharacter::getUnicodeAbsMin()
{ CALL
  return NConstants::CConstants::wcharAbsMin;
}
/*--------------------------------------------------------------------------*/
inline Twcharu CCharacter::getUnicodeAbsMax()
{ CALL
  return NConstants::CConstants::wcharAbsMax;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CCharacter::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NString::CCharacter")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_Value, STR("m_Value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
inline void CCharacter::swap(CCharacter& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_Value, a_rInstance.m_Value);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
