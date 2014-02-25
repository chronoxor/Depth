/*!
 *  \file    CRandomGeneratorMT19937B.inl Matsumoto's GFSR "MT19937B" random
 *           number generator.
 *  \brief   Matsumoto's GFSR "MT19937B" random number generator class (inline).
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    26.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Matsumoto's GFSR "MT19937B" random number generator class (inline).

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Random
    VERSION:   1.0
    CREATED:   26.02.2009 03:19:00

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
#ifndef __CRANDOMGENERATORMT19937B_INL__
#define __CRANDOMGENERATORMT19937B_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NRandom {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CRandomGeneratorMT19937B::CRandomGeneratorMT19937B(const Tuint a_cSeed/* = IRandomGenerator::getSystemSeed() */) :
  IRandomGenerator()
{ CALL
  setSeed(a_cSeed);
}
/*--------------------------------------------------------------------------*/
inline CRandomGeneratorMT19937B::CRandomGeneratorMT19937B(const CRandomGeneratorMT19937B& a_crInstance) :
  IRandomGenerator(a_crInstance)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CRandomGeneratorMT19937B::~CRandomGeneratorMT19937B()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CRandomGeneratorMT19937B& CRandomGeneratorMT19937B::operator = (const CRandomGeneratorMT19937B& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CRandomGeneratorMT19937B::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NRandom::CRandomGeneratorMT19937B")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((IRandomGenerator&)(*this), STR("base")));
    CHECK(a_rArchive.doValue(m_k, STR("m_k")));
    CHECK(a_rArchive.doValue(m_ptgfsr, 624, STR("m_ptgfsr")));
  CHECK(a_rArchive.end());
  return true;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
