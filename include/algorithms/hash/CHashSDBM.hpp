/*!
 *  \file    CHashSDBM.hpp SDBM hash function algorithm.
 *  \brief   SDBM hash function algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.03.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: SDBM hash function algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Hash functions algorithms
    VERSION:   1.0
    CREATED:   10.03.2007 22:45:26

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
#ifndef __CHASHSDBM_HPP__
#define __CHASHSDBM_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/hash/IHash.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NHash {
/*==========================================================================*/
/* ALGORITHM DECLARATIONS                                                   */
/*==========================================================================*/
//! SDBM hash function algorithm.
/*!
    This algorithm was created for sdbm (a public-domain  reimplementation  of
    ndbm) database library. it was  found  to  do  well  in  scrambling  bits,
    causing better distribution of the keys and fewer splits. it also  happens
    to be a good general hashing function with good distribution.  the  actual
    function is hash(i) = hash(i - 1) * 65599 + str[i]. What is included below
    is the faster version used in gawk (there is even  a  faster,  duff-device
    version). The magic constant 65599  was  picked  out  of  thin  air  while
    experimenting with different constants, and turns out to be a prime.  this
    is one  of  the  algorithms  used  in  berkeley  db  (see  sleepycat)  and
    elsewhere.
*/
class BASE_API CHashSDBM :
  public IHash
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CHashSDBM TDepthCheckType;

  // Check CHashSDBM class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  CHashSDBM();
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CHashSDBM class.
  */
  CHashSDBM(const CHashSDBM& a_crInstance);
  //! Class virtual destructor.
  virtual ~CHashSDBM();

  //! Operator: Assign another CHashSDBM class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CHashSDBM class.
      \return Reference to the current class instance.
  */
  CHashSDBM& operator = (const CHashSDBM& a_crInstance);

  //! Set another CHashSDBM class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CHashSDBM class.
  */
  void set(const CHashSDBM& a_crInstance);

  // IHash interface overriding methods.
  virtual Tuint getHash() const;
  virtual Tbool initialize(const Tuint a_cSeed = 0);
  virtual Tuint hash(Tcbuffer a_cpBuffer, const Tuint a_cSize);
  virtual Tbool close();

  //! Serialize CHashSDBM class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CHashSDBM class instances.
  /*!
      \param a_rInstance - Reference to another CHashSDBM class instance.
  */
  void swap(CHashSDBM& a_rInstance);

private:
  Tuint m_Hash;                         //!< Current hash value.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/hash/CHashSDBM.inl>
/*==========================================================================*/
#endif
