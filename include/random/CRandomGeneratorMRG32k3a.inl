/*!
 *  \file    CRandomGeneratorMRG32k3a.inl L'Ecuyer's 1997 MRG "MRG32k3a"
 *           random number generator.
 *  \brief   L'Ecuyer's 1997 MRG "MRG32k3a" random number generator class (inline).
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    26.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: L'Ecuyer's 1997 MRG "MRG32k3a" random number generator class (inline).

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Random
    VERSION:   1.0
    CREATED:   26.02.2009 02:18:12

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
#ifndef __CRANDOMGENERATORMRG32K3A_INL__
#define __CRANDOMGENERATORMRG32K3A_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NRandom {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CRandomGeneratorMRG32k3a::CRandomGeneratorMRG32k3a(const Tuint a_cSeed/* = IRandomGenerator::getSystemSeed() */) :
  IRandomGenerator()
{ CALL
  setSeed(a_cSeed);
}
/*--------------------------------------------------------------------------*/
inline CRandomGeneratorMRG32k3a::CRandomGeneratorMRG32k3a(const Tuint a_cSeed10, const Tuint a_cSeed11, const Tuint a_cSeed12, const Tuint a_cSeed20, const Tuint a_cSeed21, const Tuint a_cSeed22) :
 IRandomGenerator()
{ CALL
  setSeed(a_cSeed10, a_cSeed11, a_cSeed12, a_cSeed20, a_cSeed21, a_cSeed22);
}
/*--------------------------------------------------------------------------*/
inline CRandomGeneratorMRG32k3a::CRandomGeneratorMRG32k3a(const CRandomGeneratorMRG32k3a& a_crInstance) :
  IRandomGenerator(a_crInstance)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CRandomGeneratorMRG32k3a::~CRandomGeneratorMRG32k3a()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CRandomGeneratorMRG32k3a& CRandomGeneratorMRG32k3a::operator = (const CRandomGeneratorMRG32k3a& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CRandomGeneratorMRG32k3a::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NRandom::CRandomGeneratorMRG32k3a")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((IRandomGenerator&)(*this), STR("base")));
    CHECK(a_rArchive.doValue(m_s10, STR("m_s10")));
    CHECK(a_rArchive.doValue(m_s11, STR("m_s11")));
    CHECK(a_rArchive.doValue(m_s12, STR("m_s12")));
    CHECK(a_rArchive.doValue(m_s20, STR("m_s20")));
    CHECK(a_rArchive.doValue(m_s21, STR("m_s21")));
    CHECK(a_rArchive.doValue(m_s22, STR("m_s22")));
  CHECK(a_rArchive.end());
  return true;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
