/*!
 *  \file    CDistributionBinomial.hpp Binomial distribution class.
 *  \brief   Binomial distribution class.
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    05.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Binomial distribution class.

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
#ifndef __CDISTRIBUTIONBINOMIAL_HPP__
#define __CDISTRIBUTIONBINOMIAL_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/statistic/IDistribution.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStatistic {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Binomial distribution class.
/*!
    Returns a binomial distributed deviate  (integer  returned  in  a  double)
    according to the distribution:

              j+eps                 / n \    j      n-j
      integral       p   (m) dm  = |     |  q  (1-q)
              j-eps   n,q           \ j /

    References:
    - D. E. Knuth: The Art of Computer Programming, Vol. 2, Seminumerical
      Algorithms, pp. 120, 2nd edition, 1981.
    - W. H. Press, B. P. Flannery, S. A. Teukolsky, W. T. Vetterling,
      Numerical Recipies in C, Cambridge Univ. Press, 1988.
*/
class STATISTIC_API CDistributionBinomial :
  public IDistribution
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CDistributionBinomial TDepthCheckType;

  // Check CDistributionBinomial class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  /*!
      \param a_cProb - Probability argument of the binomial distribution (must be in the [0.0, 1.0] interval) (default is 0.5).
      \param a_cN - Number-of-trials argument of the binomial distribution (default is 20).
      \param a_pIRandomGenerator - Pointer to the random number generator instance (default is NULL).
  */
  CDistributionBinomial(const Treal a_cProb = CONSTR(0.5), const Tuint a_cN = 20, NRandom::IRandomGenerator* a_pIRandomGenerator = NULL);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDistributionBinomial class.
  */
  CDistributionBinomial(const CDistributionBinomial& a_crInstance);
  //! Class virtual destructor.
  virtual ~CDistributionBinomial();

  //! Operator: Assign another CDistributionBinomial class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDistributionBinomial class.
      \return Reference to the current class instance.
  */
  CDistributionBinomial& operator = (const CDistributionBinomial& a_crInstance);

  //! Set another CDistributionBinomial class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CDistributionBinomial class.
      \return true  - if another distribution was successfully set. \n
              false - if another distribution was not successfully set. \n
  */
  Tbool set(const CDistributionBinomial& a_crInstance);

  //! Set distribution parameters.
  /*!
      \param a_cProb - Probability argument of the binomial distribution (must be in the [0.0, 1.0] interval).
      \param a_cN - Number-of-trials argument of the binomial distribution.
      \return true  - if distribution parameters were successfully set. \n
              false - if distribution parameters were not successfully set. \n
  */
  Tbool setParameters(const Treal a_cProb, const Tuint a_cN);
  //! Get probability argument of the binomial distribution.
  /*!
      \return Probability argument of the binomial distribution.
  */
  Treal getProb() const;
  //! Get number-of-trials argument of the binomial distribution.
  /*!
      \return Number-of-trials argument of the binomial distribution.
  */
  Tuint getN() const;

  // IDistribution interface overriding methods.
  virtual Treal randomReal();

  //! Serialize CDistributionBinomial class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CDistributionBinomial class instances.
  /*!
      \param a_rInstance - Reference to another CDistributionBinomial class instance.
  */
  void swap(CDistributionBinomial& a_rInstance);

protected:
  Tuint m_N;                            //!< Distribution state.
  Tbool m_Sym;                          //!< Distribution state.
  Treal m_Scale;                        //!< Distribution state.
  Treal m_ScalePI;                      //!< Distribution state.
  Treal m_P;                            //!< Distribution state.
  Treal m_Pc;                           //!< Distribution state.
  Treal m_Plog;                         //!< Distribution state.
  Treal m_Pclog;                        //!< Distribution state.
  Treal m_Np;                           //!< Distribution state.
  Treal m_Npexp;                        //!< Distribution state.
  Treal m_En;                           //!< Distribution state.
  Treal m_En1;                          //!< Distribution state.
  Treal m_Gamen1;                       //!< Distribution state.
  Treal m_Sq;                           //!< Distribution state.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/statistic/CDistributionBinomial.inl>
/*==========================================================================*/
//! \example example-statistic-CDistributionBinomial.cpp
/*--------------------------------------------------------------------------*/
//! \test test-statistic-CDistributionBinomial.cpp
/*==========================================================================*/
#endif
