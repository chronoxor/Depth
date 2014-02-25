/*!
 *  \file    CDistributionFisher.inl Fisher-Snedecor distribution class.
 *  \brief   Fisher-Snedecor distribution class (inline).
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    05.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Fisher-Snedecor distribution class (inline).

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Statistic
    VERSION:   1.0
    CREATED:   05.03.2009 03:12:41

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
#ifndef __CDISTRIBUTIONFISHER_INL__
#define __CDISTRIBUTIONFISHER_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStatistic {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CDistributionFisher::CDistributionFisher(const Treal a_cNumF/* = CONSTR(1.0) */, const Treal a_cDenomF/* = CONSTR(1.0) */, NRandom::IRandomGenerator* a_pIRandomGenerator/* = NULL */) :
  IDistribution(a_pIRandomGenerator)
{ CALL
  setParameters(a_cNumF, a_cDenomF);
}
/*--------------------------------------------------------------------------*/
inline CDistributionFisher::CDistributionFisher(const CDistributionFisher& a_crInstance) :
  IDistribution(a_crInstance)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CDistributionFisher::~CDistributionFisher()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CDistributionFisher& CDistributionFisher::operator = (const CDistributionFisher& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline Treal CDistributionFisher::getNumF() const
{ CALL
  return m_NF;
}
/*--------------------------------------------------------------------------*/
inline Treal CDistributionFisher::getDenomF() const
{ CALL
  return m_DF;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CDistributionFisher::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStatistic::CDistributionFisher")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((IDistribution&)(*this), STR("base")));
    CHECK(a_rArchive.doValue(m_NF, STR("m_NF")));
    CHECK(a_rArchive.doValue(m_DF, STR("m_DF")));
    CHECK(a_rArchive.doValue(m_NumChi2, STR("m_NumChi2")));
    CHECK(a_rArchive.doValue(m_DenomChi2, STR("m_DenomChi2")));
  CHECK(a_rArchive.end());
  return true;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
