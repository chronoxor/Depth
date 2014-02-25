/*!
 *  \file    CRandomGeneratorRANMAR.inl James-Marsaglia "RANMAR" random number
 *           generator.
 *  \brief   James-Marsaglia "RANMAR" random number generator class (inline).
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    26.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: James-Marsaglia "RANMAR" random number generator class (inline).

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Random
    VERSION:   1.0
    CREATED:   26.02.2009 02:03:00

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
#ifndef __CRANDOMGENERATORRANMAR_INL__
#define __CRANDOMGENERATORRANMAR_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NRandom {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CRandomGeneratorRANMAR::CRandomGeneratorRANMAR(const Tuint a_cSeed/* = IRandomGenerator::getSystemSeed() */) :
  IRandomGenerator()
{ CALL
  setSeed(a_cSeed);
}
/*--------------------------------------------------------------------------*/
inline CRandomGeneratorRANMAR::CRandomGeneratorRANMAR(const CRandomGeneratorRANMAR& a_crInstance) :
  IRandomGenerator(a_crInstance)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CRandomGeneratorRANMAR::~CRandomGeneratorRANMAR()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CRandomGeneratorRANMAR& CRandomGeneratorRANMAR::operator = (const CRandomGeneratorRANMAR& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CRandomGeneratorRANMAR::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NRandom::CRandomGeneratorRANMAR")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((IRandomGenerator&)(*this), STR("base")));
    CHECK(a_rArchive.doValue(m_u, 97, STR("m_u")));
    CHECK(a_rArchive.doValue(m_c, STR("m_c")));
    CHECK(a_rArchive.doValue(m_cd, STR("m_cd")));
    CHECK(a_rArchive.doValue(m_cm, STR("m_cm")));
    CHECK(a_rArchive.doValue(m_i97, STR("m_i97")));
    CHECK(a_rArchive.doValue(m_j97, STR("m_j97")));
  CHECK(a_rArchive.end());
  return true;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
