/*!
 *  \file    CTribool.inl Three state boolean logic class. It represents all
 *           operations with 3-state boolean logic values.
 *  \brief   Three state boolean logic class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Three state boolean logic class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Base
    VERSION:   1.0
    CREATED:   01.02.2006 02:42:24

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
#ifndef __CTRIBOOL_INL__
#define __CTRIBOOL_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NBase {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CTribool::CTribool(const Tbool a_cValue/* = false */) :
  m_Value(CTribool::getTribool(a_cValue))
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CTribool::CTribool(const ETriboolState a_cValue) :
  m_Value(a_cValue)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CTribool::CTribool(const CTribool& a_crInstance) :
  m_Value(a_crInstance.m_Value)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CTribool::~CTribool()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline BASE_API CTribool operator == (const CTribool& a_crInstance, const Tbool a_cValue)
{ CALL
  return CTribool(CTribool::getEqual(a_crInstance.m_Value, CTribool::getTribool(a_cValue)));
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTribool operator == (const CTribool& a_crInstance, const CTribool::ETriboolState a_cValue)
{ CALL
  return CTribool(CTribool::getEqual(a_crInstance.m_Value, a_cValue));
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTribool operator == (const CTribool& a_crInstance1, const CTribool& a_crInstance2)
{ CALL
  return CTribool(CTribool::getEqual(a_crInstance1.m_Value, a_crInstance2.m_Value));
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTribool operator == (const Tbool a_cValue, const CTribool& a_crInstance)
{ CALL
  return CTribool(CTribool::getEqual(CTribool::getTribool(a_cValue), a_crInstance.m_Value));
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTribool operator == (const CTribool::ETriboolState a_cValue, const CTribool& a_crInstance)
{ CALL
  return CTribool(CTribool::getEqual(a_cValue, a_crInstance.m_Value));
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTribool operator != (const CTribool& a_crInstance, const Tbool a_cValue)
{ CALL
  return CTribool(CTribool::getNotEqual(a_crInstance.m_Value, CTribool::getTribool(a_cValue)));
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTribool operator != (const CTribool& a_crInstance, const CTribool::ETriboolState a_cValue)
{ CALL
  return CTribool(CTribool::getNotEqual(a_crInstance.m_Value, a_cValue));
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTribool operator != (const CTribool& a_crInstance1, const CTribool& a_crInstance2)
{ CALL
  return CTribool(CTribool::getNotEqual(a_crInstance1.m_Value, a_crInstance2.m_Value));
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTribool operator != (const Tbool a_cValue, const CTribool& a_crInstance)
{ CALL
  return CTribool(CTribool::getNotEqual(CTribool::getTribool(a_cValue), a_crInstance.m_Value));
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTribool operator != (const CTribool::ETriboolState a_cValue, const CTribool& a_crInstance)
{ CALL
  return CTribool(CTribool::getNotEqual(a_cValue, a_crInstance.m_Value));
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTribool operator && (const CTribool& a_crInstance, const Tbool a_cValue)
{ CALL
  return CTribool(CTribool::getConjuction(a_crInstance.m_Value, CTribool::getTribool(a_cValue)));
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTribool operator && (const CTribool& a_crInstance, const CTribool::ETriboolState a_cValue)
{ CALL
  return CTribool(CTribool::getConjuction(a_crInstance.m_Value, a_cValue));
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTribool operator && (const CTribool& a_crInstance1, const CTribool& a_crInstance2)
{ CALL
  return CTribool(CTribool::getConjuction(a_crInstance1.m_Value, a_crInstance2.m_Value));
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTribool operator && (const Tbool a_cValue, const CTribool& a_crInstance)
{ CALL
  return CTribool(CTribool::getConjuction(CTribool::getTribool(a_cValue), a_crInstance.m_Value));
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTribool operator && (const CTribool::ETriboolState a_cValue, const CTribool& a_crInstance)
{ CALL
  return CTribool(CTribool::getConjuction(a_cValue, a_crInstance.m_Value));
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTribool operator || (const CTribool& a_crInstance, const Tbool a_cValue)
{ CALL
  return CTribool(CTribool::getDisjunction(a_crInstance.m_Value, CTribool::getTribool(a_cValue)));
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTribool operator || (const CTribool& a_crInstance, const CTribool::ETriboolState a_cValue)
{ CALL
  return CTribool(CTribool::getDisjunction(a_crInstance.m_Value, a_cValue));
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTribool operator || (const CTribool& a_crInstance1, const CTribool& a_crInstance2)
{ CALL
  return CTribool(CTribool::getDisjunction(a_crInstance1.m_Value, a_crInstance2.m_Value));
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTribool operator || (const Tbool a_cValue, const CTribool& a_crInstance)
{ CALL
  return CTribool(CTribool::getDisjunction(CTribool::getTribool(a_cValue), a_crInstance.m_Value));
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTribool operator || (const CTribool::ETriboolState a_cValue, const CTribool& a_crInstance)
{ CALL
  return CTribool(CTribool::getDisjunction(a_cValue, a_crInstance.m_Value));
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTribool operator ! (const CTribool& a_crInstance)
{ CALL
  return CTribool(CTribool::getNot(a_crInstance.m_Value));
}
/*--------------------------------------------------------------------------*/
inline CTribool& CTribool::operator = (const Tbool a_cValue)
{ CALL
  set(a_cValue);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CTribool& CTribool::operator = (const ETriboolState a_cValue)
{ CALL
  set(a_cValue);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CTribool& CTribool::operator = (const CTribool& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CTribool::operator CTribool::ETriboolState& ()
{ CALL
  return m_Value;
}
/*--------------------------------------------------------------------------*/
inline CTribool::operator const CTribool::ETriboolState& () const
{ CALL
  return m_Value;
}
/*--------------------------------------------------------------------------*/
inline CTribool::operator CTribool::ETriboolState* ()
{ CALL
  return &m_Value;
}
/*--------------------------------------------------------------------------*/
inline CTribool::operator const CTribool::ETriboolState* () const
{ CALL
  return &m_Value;
}
/*--------------------------------------------------------------------------*/
inline void CTribool::set(const Tbool a_cValue)
{ CALL
  m_Value = CTribool::getTribool(a_cValue);
}
/*--------------------------------------------------------------------------*/
inline void CTribool::set(const ETriboolState a_cValue)
{ CALL
  m_Value = a_cValue;
}
/*--------------------------------------------------------------------------*/
inline void CTribool::set(const CTribool& a_crInstance)
{ CALL
  m_Value = a_crInstance.m_Value;
}
/*--------------------------------------------------------------------------*/
inline CTribool::ETriboolState CTribool::getValue() const
{ CALL
  return m_Value;
}
/*--------------------------------------------------------------------------*/
inline Tbool CTribool::isTrue() const
{ CALL
  return (m_Value == e_TRUE);
}
/*--------------------------------------------------------------------------*/
inline Tbool CTribool::isFalse() const
{ CALL
  return (m_Value == e_FALSE);
}
/*--------------------------------------------------------------------------*/
inline Tbool CTribool::isNull() const
{ CALL
  return (m_Value == e_NULL);
}
/*--------------------------------------------------------------------------*/
inline void CTribool::setTrue()
{ CALL
  m_Value = e_TRUE;
}
/*--------------------------------------------------------------------------*/
inline void CTribool::setFalse()
{ CALL
  m_Value = e_FALSE;
}
/*--------------------------------------------------------------------------*/
inline void CTribool::setNull()
{ CALL
  m_Value = e_NULL;
}
/*--------------------------------------------------------------------------*/
inline CTribool::ETriboolState CTribool::getTrue()
{ CALL
  return e_TRUE;
}
/*--------------------------------------------------------------------------*/
inline CTribool::ETriboolState CTribool::getFalse()
{ CALL
  return e_FALSE;
}
/*--------------------------------------------------------------------------*/
inline CTribool::ETriboolState CTribool::getNull()
{ CALL
  return e_NULL;
}
/*--------------------------------------------------------------------------*/
inline CTribool::ETriboolState CTribool::getTribool(const Tbool a_cValue)
{ CALL
  return ((a_cValue) ? CTribool::e_TRUE : CTribool::e_FALSE);
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CTribool::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NBase::CTribool")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_Value, STR("m_Value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
inline void CTribool::swap(CTribool& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_Value, a_rInstance.m_Value);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
/* INLINE SERIALIZATION FUNCTION IMPLEMENTATIONS                            */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSerialization {
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool load(T_Archive& a_rArchive, NBase::CTribool::ETriboolState& a_rInstance)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint value;

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NBase::CTribool::ETriboolState")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(value, STR("value")));
  CHECK(a_rArchive.end());

  // Set three boolean state value.
  switch (value)
  {
    case 0:
      a_rInstance = NBase::CTribool::e_FALSE;
      break;
    case 1:
      a_rInstance = NBase::CTribool::e_TRUE;
      break;
    case 2:
      a_rInstance = NBase::CTribool::e_NULL;
      break;
    default:
      WARNING(STR("Cannot load invalid three boolean state value from the archive."));
      return false;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool save(T_Archive& a_rArchive, const NBase::CTribool::ETriboolState& a_crInstance)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint value;

  // Get three boolean state value.
  switch (a_crInstance)
  {
    case NBase::CTribool::e_FALSE:
      value = 0;
      break;
    case NBase::CTribool::e_TRUE:
      value = 1;
      break;
    case NBase::CTribool::e_NULL:
      value = 2;
      break;
    default:
      WARNING(STR("Cannot save invalid three boolean state value into the archive."));
      return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NBase::CTribool::ETriboolState")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(value, STR("value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool serialize(T_Archive& a_rArchive, NBase::CTribool::ETriboolState& a_rInstance)
{ CALL
  // Split 'serialize()' free function into 'load()' and 'save()' ones.
  return serializeSplitFunction(a_rArchive, a_rInstance);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
