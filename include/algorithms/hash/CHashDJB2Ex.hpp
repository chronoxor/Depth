/*!
 *  \file    CHashDJB2Ex.hpp Extended DJB2 hash function algorithm.
 *  \brief   Extended DJB2 hash function algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.03.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Extended DJB2 hash function algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Hash functions algorithms
    VERSION:   1.0
    CREATED:   10.03.2007 22:37:42

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
#ifndef __CHASHDJB2EX_HPP__
#define __CHASHDJB2EX_HPP__
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
//! Extended DJB2 hash function algorithm.
/*!
    This algorithm was first reported by  Dan  Bernstein  many  years  ago  in
    comp.lang.c. Another version of this algorithm (now favored by  Bernstein)
    uses XOR: hash(i) = hash(i - 1) * 33 ^ str[i]. The magic of number 33 (why
    it works better than many other constants, prime or not)  has  never  been
    adequately explained.

    \see NDepth::NAlgorithms::NHash::CHashDJB2
*/
class BASE_API CHashDJB2Ex :
  public IHash
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CHashDJB2Ex TDepthCheckType;

  // Check CHashDJB2Ex class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  CHashDJB2Ex();
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CHashDJB2Ex class.
  */
  CHashDJB2Ex(const CHashDJB2Ex& a_crInstance);
  //! Class virtual destructor.
  virtual ~CHashDJB2Ex();

  //! Operator: Assign another CHashDJB2Ex class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CHashDJB2Ex class.
      \return Reference to the current class instance.
  */
  CHashDJB2Ex& operator = (const CHashDJB2Ex& a_crInstance);

  //! Set another CHashDJB2Ex class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CHashDJB2Ex class.
  */
  void set(const CHashDJB2Ex& a_crInstance);

  // IHash interface overriding methods.
  virtual Tuint getHash() const;
  virtual Tbool initialize(const Tuint a_cSeed = 5381);
  virtual Tuint hash(Tcbuffer a_cpBuffer, const Tuint a_cSize);
  virtual Tbool close();

  //! Serialize CHashDJB2Ex class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CHashDJB2Ex class instances.
  /*!
      \param a_rInstance - Reference to another CHashDJB2Ex class instance.
  */
  void swap(CHashDJB2Ex& a_rInstance);

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
#include <Depth/include/algorithms/hash/CHashDJB2Ex.inl>
/*==========================================================================*/
#endif
