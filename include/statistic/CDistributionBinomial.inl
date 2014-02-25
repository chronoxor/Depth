/*!
 *  \file    CDistributionBinomial.inl Binomial distribution class.
 *  \brief   Binomial distribution class (inline).
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    05.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Binomial distribution class (inline).

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Statistic
    VERSION:   1.0
    CREATED:   05.03.2009 03:54:41

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
#ifndef __CDISTRIBUTIONBINOMIAL_INL__
#define __CDISTRIBUTIONBINOMIAL_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStatistic {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CDistributionBinomial::CDistributionBinomial(const Treal a_cProb/* = CONSTR(0.5) */, const Tuint a_cN/* = 20 */, NRandom::IRandomGenerator* a_pIRandomGenerator/* = NULL */) :
  IDistribution(a_pIRandomGenerator)
{ CALL
  setParameters(a_cProb, a_cN);
}
/*--------------------------------------------------------------------------*/
inline CDistributionBinomial::CDistributionBinomial(const CDistributionBinomial& a_crInstance) :
  IDistribution(a_crInstance)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CDistributionBinomial::~CDistributionBinomial()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CDistributionBinomial& CDistributionBinomial::operator = (const CDistributionBinomial& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline Treal CDistributionBinomial::getProb() const
{ CALL
  return m_P;
}
/*--------------------------------------------------------------------------*/
inline Tuint CDistributionBinomial::getN() const
{ CALL
  return m_N;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CDistributionBinomial::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStatistic::CDistributionBinomial")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((IDistribution&)(*this), STR("base")));
    CHECK(a_rArchive.doValue(m_N, STR("m_N")));
    CHECK(a_rArchive.doValue(m_Sym, STR("m_Sym")));
    CHECK(a_rArchive.doValue(m_Scale, STR("m_Scale")));
    CHECK(a_rArchive.doValue(m_ScalePI, STR("m_ScalePI")));
    CHECK(a_rArchive.doValue(m_P, STR("m_P")));
    CHECK(a_rArchive.doValue(m_Pc, STR("m_Pc")));
    CHECK(a_rArchive.doValue(m_Plog, STR("m_Plog")));
    CHECK(a_rArchive.doValue(m_Pclog, STR("m_Pclog")));
    CHECK(a_rArchive.doValue(m_Np, STR("m_Np")));
    CHECK(a_rArchive.doValue(m_Npexp, STR("m_Npexp")));
    CHECK(a_rArchive.doValue(m_En, STR("m_En")));
    CHECK(a_rArchive.doValue(m_En1, STR("m_En1")));
    CHECK(a_rArchive.doValue(m_Gamen1, STR("m_Gamen1")));
    CHECK(a_rArchive.doValue(m_Sq, STR("m_Sq")));
  CHECK(a_rArchive.end());
  return true;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
