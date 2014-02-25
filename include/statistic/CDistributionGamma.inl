/*!
 *  \file    CDistributionGamma.inl Gamma distribution class.
 *  \brief   Gamma distribution class (inline).
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    05.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Gamma distribution class (inline).

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Statistic
    VERSION:   1.0
    CREATED:   05.03.2009 03:13:55

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
#ifndef __CDISTRIBUTIONGAMMA_INL__
#define __CDISTRIBUTIONGAMMA_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStatistic {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CDistributionGamma::CDistributionGamma(const Treal a_cOrder/* = CONSTR(1.0) */, const Treal a_cLocation/* = CONSTR(2.0) */, NRandom::IRandomGenerator* a_pIRandomGenerator/* = NULL */) :
  IDistribution(a_pIRandomGenerator)
{ CALL
  setParameters(a_cOrder, a_cLocation);
}
/*--------------------------------------------------------------------------*/
inline CDistributionGamma::CDistributionGamma(const CDistributionGamma& a_crInstance) :
  IDistribution(a_crInstance)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CDistributionGamma::~CDistributionGamma()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CDistributionGamma& CDistributionGamma::operator = (const CDistributionGamma& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline Treal CDistributionGamma::getOrder() const
{ CALL
  return m_A;
}
/*--------------------------------------------------------------------------*/
inline Treal CDistributionGamma::getLocation() const
{ CALL
  return m_B;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CDistributionGamma::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStatistic::CDistributionGamma")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((IDistribution&)(*this), STR("base")));
    CHECK(a_rArchive.doValue(m_AlgorithmGD, STR("m_AlgorithmGD")));
    CHECK(a_rArchive.doValue(m_Cached, STR("m_Cached")));
    CHECK(a_rArchive.doValue(m_Cache, STR("m_Cache")));
    CHECK(a_rArchive.doValue(m_A, STR("m_A")));
    CHECK(a_rArchive.doValue(m_B, STR("m_B")));
    CHECK(a_rArchive.doValue(m_s, STR("m_s")));
    CHECK(a_rArchive.doValue(m_s2, STR("m_s2")));
    CHECK(a_rArchive.doValue(m_d, STR("m_d")));
    CHECK(a_rArchive.doValue(m_r, STR("m_r")));
    CHECK(a_rArchive.doValue(m_q0, STR("m_q0")));
    CHECK(a_rArchive.doValue(m_b, STR("m_b")));
    CHECK(a_rArchive.doValue(m_si, STR("m_si")));
    CHECK(a_rArchive.doValue(m_c, STR("m_c")));
    CHECK(a_rArchive.doValue(m_scale, STR("m_scale")));
    CHECK(a_rArchive.doValue(m_M, STR("m_M")));
    CHECK(a_rArchive.doValue(m_S, STR("m_S")));
    CHECK(a_rArchive.doValue(m_MExp, STR("m_MExp")));
  CHECK(a_rArchive.end());
  return true;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
