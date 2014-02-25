/*!
 *  \file    CDistributionBeta.inl Beta distribution class.
 *  \brief   Beta distribution class (inline).
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    04.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Beta distribution class (inline).

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Statistic
    VERSION:   1.0
    CREATED:   04.03.2009 20:46:14

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
#ifndef __CDISTRIBUTIONBETA_INL__
#define __CDISTRIBUTIONBETA_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStatistic {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CDistributionBeta::CDistributionBeta(const Treal a_cPA/* = CONSTR(0.5) */, const Treal a_cPB/* = CONSTR(0.5) */, NRandom::IRandomGenerator* a_pIRandomGenerator/* = NULL */) :
  IDistribution(a_pIRandomGenerator)
{ CALL
  setParameters(a_cPA, a_cPB);
}
/*--------------------------------------------------------------------------*/
inline CDistributionBeta::CDistributionBeta(const CDistributionBeta& a_crInstance) :
  IDistribution(a_crInstance)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CDistributionBeta::~CDistributionBeta()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CDistributionBeta& CDistributionBeta::operator = (const CDistributionBeta& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline Treal CDistributionBeta::getPA() const
{ CALL
  return m_aa;
}
/*--------------------------------------------------------------------------*/
inline Treal CDistributionBeta::getPB() const
{ CALL
  return m_bb;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CDistributionBeta::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStatistic::CDistributionBeta")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((IDistribution&)(*this), STR("base")));
    CHECK(a_rArchive.doValue(m_AlgorithmBB, STR("m_AlgorithmBB")));
    CHECK(a_rArchive.doValue(m_aa, STR("m_aa")));
    CHECK(a_rArchive.doValue(m_bb, STR("m_bb")));
    CHECK(a_rArchive.doValue(m_scale, STR("m_scale")));
    CHECK(a_rArchive.doValue(m_a, STR("m_a")));
    CHECK(a_rArchive.doValue(m_alpha, STR("m_alpha")));
    CHECK(a_rArchive.doValue(m_b, STR("m_b")));
    CHECK(a_rArchive.doValue(m_beta, STR("m_beta")));
    CHECK(a_rArchive.doValue(m_delta, STR("m_delta")));
    CHECK(a_rArchive.doValue(m_gamma, STR("m_gamma")));
    CHECK(a_rArchive.doValue(m_k1, STR("m_k1")));
    CHECK(a_rArchive.doValue(m_k2, STR("m_k2")));
    CHECK(a_rArchive.doValue(m_maxexp, STR("m_maxexp")));
  CHECK(a_rArchive.end());
  return true;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
