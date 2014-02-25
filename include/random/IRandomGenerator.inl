/*!
 *  \file    IRandomGenerator.inl Interface for all random number generators.
 *  \brief   Random number generator interface (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Random number generator interface (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Random
    VERSION:   1.0
    CREATED:   24.02.2009 22:42:02

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
#ifndef __IRANDOMGENERATOR_INL__
#define __IRANDOMGENERATOR_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NRandom {
/*==========================================================================*/
/* INLINE INTERFACE IMPLEMENTATIONS                                         */
/*==========================================================================*/
inline IRandomGenerator::IRandomGenerator() :
  m_Seed(0),
  m_MaxInteger(0)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline IRandomGenerator::IRandomGenerator(const IRandomGenerator & a_crInstance) :
  m_Seed(a_crInstance.m_Seed),
  m_MaxInteger(a_crInstance.m_MaxInteger)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline IRandomGenerator::~IRandomGenerator()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline IRandomGenerator& IRandomGenerator::operator = (const IRandomGenerator& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline void IRandomGenerator::set(const IRandomGenerator& a_crInstance)
{ CALL
  m_Seed = a_crInstance.m_Seed;
  m_MaxInteger = a_crInstance.m_MaxInteger;
}
/*--------------------------------------------------------------------------*/
inline Tuint IRandomGenerator::getSeed() const
{ CALL
  return m_Seed;
}
/*--------------------------------------------------------------------------*/
inline Tuint IRandomGenerator::getMaxInteger() const
{ CALL
  return m_MaxInteger;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool IRandomGenerator::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NRandom::IRandomGenerator")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_Seed, STR("m_Seed")));
    CHECK(a_rArchive.doValue(m_MaxInteger, STR("m_MaxInteger")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
inline void IRandomGenerator::swap(IRandomGenerator& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_Seed, a_rInstance.m_Seed);
  NAlgorithms::NCommon::swap(m_MaxInteger, a_rInstance.m_MaxInteger);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
