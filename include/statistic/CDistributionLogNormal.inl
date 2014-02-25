/*!
 *  \file    CDistributionLogNormal.inl Log-normal distribution class.
 *  \brief   Log-normal distribution class (inline).
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    05.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Log-normal distribution class (inline).

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Statistic
    VERSION:   1.0
    CREATED:   05.03.2009 03:15:23

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
#ifndef __CDISTRIBUTIONLOGNORMAL_INL__
#define __CDISTRIBUTIONLOGNORMAL_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStatistic {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CDistributionLogNormal::CDistributionLogNormal(const Treal a_cMean/* = CONSTR(1.0) */, const Treal a_cStdDev/* = CONSTR(1.0) */, NRandom::IRandomGenerator* a_pIRandomGenerator/* = NULL */) :
  CDistributionNormal(a_cMean, a_cStdDev, a_pIRandomGenerator)
{ CALL
  setParameters(a_cMean, a_cStdDev);
}
/*--------------------------------------------------------------------------*/
inline CDistributionLogNormal::CDistributionLogNormal(const CDistributionLogNormal& a_crInstance) :
  CDistributionNormal(a_crInstance)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CDistributionLogNormal::~CDistributionLogNormal()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CDistributionLogNormal& CDistributionLogNormal::operator = (const CDistributionLogNormal& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline Treal CDistributionLogNormal::getMean() const
{ CALL
  return m_MLog;
}
/*--------------------------------------------------------------------------*/
inline Treal CDistributionLogNormal::getStdDev() const
{ CALL
  return m_SLog;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CDistributionLogNormal::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStatistic::CDistributionLogNormal")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((CDistributionNormal&)(*this), STR("base")));
    CHECK(a_rArchive.doValue(m_MLog, STR("m_MLog")));
    CHECK(a_rArchive.doValue(m_SLog, STR("m_SLog")));
  CHECK(a_rArchive.end());
  return true;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
