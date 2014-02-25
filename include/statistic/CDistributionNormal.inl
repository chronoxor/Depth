/*!
 *  \file    CDistributionNormal.inl Normal (Gaussian) distribution class.
 *  \brief   Normal (Gaussian) distribution class (inline).
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    05.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Normal (Gaussian) distribution class (inline).

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Statistic
    VERSION:   1.0
    CREATED:   05.03.2009 03:17:11

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
#ifndef __CDISTRIBUTIONNORMAL_INL__
#define __CDISTRIBUTIONNORMAL_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStatistic {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CDistributionNormal::CDistributionNormal(const Treal a_cMean/* = CONSTR(0.0) */, const Treal a_cStdDev/* = CONSTR(1.0) */, NRandom::IRandomGenerator* a_pIRandomGenerator/* = NULL */) :
  IDistribution(a_pIRandomGenerator)
{ CALL
  setParameters(a_cMean, a_cStdDev);
}
/*--------------------------------------------------------------------------*/
inline CDistributionNormal::CDistributionNormal(const CDistributionNormal& a_crInstance) :
  IDistribution(a_crInstance)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CDistributionNormal::~CDistributionNormal()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CDistributionNormal& CDistributionNormal::operator = (const CDistributionNormal& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline Treal CDistributionNormal::getMean() const
{ CALL
  return m_M;
}
/*--------------------------------------------------------------------------*/
inline Treal CDistributionNormal::getStdDev() const
{ CALL
  return m_S;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CDistributionNormal::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStatistic::CDistributionNormal")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((IDistribution&)(*this), STR("base")));
    CHECK(a_rArchive.doValue(m_Cached, STR("m_Cached")));
    CHECK(a_rArchive.doValue(m_Cache, STR("m_Cache")));
    CHECK(a_rArchive.doValue(m_M, STR("m_M")));
    CHECK(a_rArchive.doValue(m_S, STR("m_S")));
  CHECK(a_rArchive.end());
  return true;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
