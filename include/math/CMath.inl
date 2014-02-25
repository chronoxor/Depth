/*!
 *  \file    CMath.inl Math class contains common functionality for various
 *           mathematical calculations.
 *  \brief   Static class for mathematical calculations (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Static class for mathematical calculations (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Math
    VERSION:   1.0
    CREATED:   05.01.2006 23:59:45

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
#ifndef __CMATH_INL__
#define __CMATH_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NMath {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline void CMath::setEpsilon(const Treal a_cEpsilon)
{ CALL
  // Exclusive lock the math class under the multi-threaded environment.
  NProcess::CScopeWriter wlocker(CMath::ms_Locker);

  CMath::ms_Epsilon = a_cEpsilon;
}
/*--------------------------------------------------------------------------*/
inline Treal CMath::getEpsilon()
{ CALL
  // Shared lock the math class under the multi-threaded environment.
  NProcess::CScopeReader rlocker(CMath::ms_Locker);

  return CMath::ms_Epsilon;
}
/*--------------------------------------------------------------------------*/
inline Tbool CMath::isNormal(const Treal a_cX)
{ CALL
  return (CMath::getNumberState(a_cX) == e_NORMAL);
}
/*--------------------------------------------------------------------------*/
inline Tbool CMath::isInfinite(const Treal a_cX)
{ CALL
  ENumberState state = CMath::getNumberState(a_cX);

  return ((state == e_POSINF) || (state == e_NEGINF));
}
/*--------------------------------------------------------------------------*/
inline Tbool CMath::isPosInf(const Treal a_cX)
{ CALL
  return (CMath::getNumberState(a_cX) == e_POSINF);
}
/*--------------------------------------------------------------------------*/
inline Tbool CMath::isNegInf(const Treal a_cX)
{ CALL
  return (CMath::getNumberState(a_cX) == e_NEGINF);
}
/*--------------------------------------------------------------------------*/
inline Tbool CMath::isNan(const Treal a_cX)
{ CALL
  ENumberState state = CMath::getNumberState(a_cX);

  return ((state == e_QNAN) || (state == e_SNAN));
}
/*--------------------------------------------------------------------------*/
inline Tbool CMath::isQNan(const Treal a_cX)
{ CALL
  return (CMath::getNumberState(a_cX) == e_QNAN);
}
/*--------------------------------------------------------------------------*/
inline Tbool CMath::isSNan(const Treal a_cX)
{ CALL
  return (CMath::getNumberState(a_cX) == e_SNAN);
}
/*--------------------------------------------------------------------------*/
inline Tbool CMath::isEqual(const Treal a_cX, const Treal a_cY, const Treal a_cDelta/* = CMath::getEpsilon() */)
{ CALL
  return (CMath::fabs(a_cX - a_cY) <= a_cDelta);
}
/*--------------------------------------------------------------------------*/
inline Tbool CMath::isEqualZero(const Treal a_cX, const Treal a_cDelta/* = CMath::getEpsilon() */)
{ CALL
  return (CMath::fabs(a_cX) <= a_cDelta);
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
inline Tbool load(T_Archive& a_rArchive, NMath::CMath::ENumberState& a_rInstance)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint value;

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NMath::CMath::ENumberState")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(value, STR("value")));
  CHECK(a_rArchive.end());

  // Set real number state.
  switch (value)
  {
    case 0:
      a_rInstance = NMath::CMath::e_NORMAL;
      break;
    case 1:
      a_rInstance = NMath::CMath::e_POSINF;
      break;
    case 2:
      a_rInstance = NMath::CMath::e_NEGINF;
      break;
    case 3:
      a_rInstance = NMath::CMath::e_QNAN;
      break;
    case 4:
      a_rInstance = NMath::CMath::e_SNAN;
      break;
    default:
      WARNING(STR("Cannot load invalid real number state from the archive."));
      return false;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool save(T_Archive& a_rArchive, const NMath::CMath::ENumberState& a_crInstance)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint value;

  // Get real number state.
  switch (a_crInstance)
  {
    case NMath::CMath::e_NORMAL:
      value = 0;
      break;
    case NMath::CMath::e_POSINF:
      value = 1;
      break;
    case NMath::CMath::e_NEGINF:
      value = 2;
      break;
    case NMath::CMath::e_QNAN:
      value = 3;
      break;
    case NMath::CMath::e_SNAN:
      value = 4;
      break;
    default:
      WARNING(STR("Cannot save invalid real number state into the archive."));
      return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NMath::CMath::ENumberState")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(value, STR("value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool serialize(T_Archive& a_rArchive, NMath::CMath::ENumberState& a_rInstance)
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
