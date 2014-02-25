/*!
 *  \file    IDistribution.inl Interface for all statistical distributions.
 *  \brief   Statistical distribution interface (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Statistical distribution interface (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Statistic
    VERSION:   1.0
    CREATED:   04.03.2009 02:13:10

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
#ifndef __IDISTRIBUTION_INL__
#define __IDISTRIBUTION_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStatistic {
/*==========================================================================*/
/* INLINE INTERFACE IMPLEMENTATIONS                                         */
/*==========================================================================*/
inline IDistribution::IDistribution(NRandom::IRandomGenerator* a_pIRandomGenerator/* = NULL */) :
  m_IsLocalGenerator(false),
  m_pRandomGenerator(NULL)
{ CALL
  setRandomGenerator(a_pIRandomGenerator);
}
/*--------------------------------------------------------------------------*/
inline IDistribution::IDistribution(const IDistribution & a_crInstance) :
  m_IsLocalGenerator(false),
  m_pRandomGenerator(NULL)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline IDistribution::~IDistribution()
{ CALL
  // Clear the current random number generator.
  clear();
}
/*--------------------------------------------------------------------------*/
inline IDistribution& IDistribution::operator = (const IDistribution& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline Tbool IDistribution::isValidGenerator() const
{ CALL
  return (m_pRandomGenerator != NULL);
}
/*--------------------------------------------------------------------------*/
inline NRandom::IRandomGenerator& IDistribution::getRandomGeneratorRef()
{ CALL
  // Verify the random number generator to be the valid one.
  VERIFY(isValidGenerator(), STR("Taking reference to the invalid random number generator leads to the error."));

  return *m_pRandomGenerator;
}
/*--------------------------------------------------------------------------*/
inline NRandom::IRandomGenerator* IDistribution::getRandomGeneratorPtr()
{ CALL
  return m_pRandomGenerator;
}
/*--------------------------------------------------------------------------*/
inline const NRandom::IRandomGenerator& IDistribution::getRandomGeneratorRef() const
{ CALL
  // Verify the random number generator to be the valid one.
  VERIFY(isValidGenerator(), STR("Taking reference to the invalid random number generator leads to the error."));

  return *m_pRandomGenerator;
}
/*--------------------------------------------------------------------------*/
inline const NRandom::IRandomGenerator* IDistribution::getRandomGeneratorPtr() const
{ CALL
  return m_pRandomGenerator;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool IDistribution::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tbool valid = false;
  Tbool local = false;

  // Clear the current random number generator.
  clear();

  // Load the distribution header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStatistic::IDistribution")));
    CHECK(a_rArchive.doProperty(valid, STR("valid")));
    CHECK(a_rArchive.doProperty(local, STR("local")));
  CHECK(a_rArchive.body());

  if (!valid)
  {
    // Load invalid random number generator.
    m_IsLocalGenerator = false;
    m_pRandomGenerator = NULL;
  }
  else if (local)
  {
    // Load local random number generator.
    CHECK(setRandomGenerator(NULL));
  }
  else
  {
    // Load random number generator from pointer.
    CHECK(a_rArchive.doPointer(m_pRandomGenerator, STR("m_pRandomGenerator")));
  }

  // Load the distribution end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool IDistribution::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Save the distribution header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStatistic::IDistribution")));
    CHECK(a_rArchive.doProperty(isValidGenerator(), STR("valid")));
    CHECK(a_rArchive.doProperty(m_IsLocalGenerator, STR("local")));
  CHECK(a_rArchive.body());

  // Save the distribution random number generator.
  if (isValidGenerator() && !m_IsLocalGenerator)
  {
    CHECK(a_rArchive.doPointer(m_pRandomGenerator, STR("m_pRandomGenerator")));
  }

  // Save the distribution end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool IDistribution::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return NSerialization::serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
inline void IDistribution::swap(IDistribution& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_IsLocalGenerator, a_rInstance.m_IsLocalGenerator);
  NAlgorithms::NCommon::swap(m_pRandomGenerator, a_rInstance.m_pRandomGenerator);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
